#!/bin/bash

if [ -f 'md2PDF.md' ]; then
    rm md2PDF.md
fi

touch md2PDF.md

function findMd() {
    path=$1
    hasIndex=false
    sedImages="s,\[(.+)\]\(.\/(.+).(jpg|png|gif|webp)\),[\1](${path}\/\2.\3),g"
    depth=$(expr $(echo "$path" | awk -F"/" '{print NF-1}') - 1)
    bangs=''
    if [ "$depth" -gt "0" ]; then
        bangs=$(seq -f "#" -s '' $depth)
    fi

    if [ -f "$path/index.md" ]; then
        # echo "$path/index.md ($depth) -> $bangs"
        echo '' >>md2PDF.md
        cat "$path/index.md" | sed -E "s/^#/#$bangs/g" | sed -E "$sedImages" >>md2PDF.md
        hasIndex=true
    fi
    for file in "$path"/*.md; do
        if [ -f "$file" ]; then
            # echo "$path -> $file ($depth) -> $bangs"
            if [[ "$file" != "$path/index.md" && "$file" != "$path/md2PDF.md" && "$file" != "./Useful/Markdown Cheatsheet.md" ]]; then
                echo '' >>md2PDF.md
                if [ "$hasIndex" == "true" ]; then
                    cat "$file" | sed -E "s/^#/##$bangs/g" | sed -E "$sedImages" >>md2PDF.md
                else
                    cat "$file" | sed -E "s/^#/#$bangs/g" | sed -E "$sedImages" >>md2PDF.md
                fi
            fi
        fi
    done

    for i in "$path"/*; do
        if [ -d "$i" ]; then
            findMd "$i"
        fi
    done
}

name=$(basename $1)
if [ "$name" == "." ]; then
    name="Notes"
fi

findMd $1

pandoc "md2PDF.md" \
    -f gfm \
    --toc \
    --include-in-header ./.pandoc_pdf/chapter_break.tex \
    --include-in-header ./.pandoc_pdf/inline_code.tex \
    --include-in-header ./.pandoc_pdf/bullet_style.tex \
    --include-in-header ./.pandoc_pdf/pdf_properties.tex \
    --highlight-style ./.pandoc_pdf/pygments.theme \
    -V toc-title='Table of contents' \
    -V linkcolor:blue \
    -V geometry:a4paper \
    -V geometry:margin=2cm \
    -V mainfont="Helvetica" \
    -V monofont="FuraCode Nerd Font Mono" \
    --pdf-engine=xelatex \
    -o "$name.pdf"

rm md2PDF.md
