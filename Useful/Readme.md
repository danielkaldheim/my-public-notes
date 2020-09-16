[< Parent](./Readme.md)

# Useful stuff

- [Open api's](./Api.md)
- [MacOS](./MacOS.md)
- [Markdown cheatsheet](./Markdown%20Cheatsheet.md)
- [Useful commands](./UsefulCommands.md)

## Git

- [Oh Shit, Git!?!](https://ohshitgit.com/)
- [BFG Repo-Cleaner](https://rtyley.github.io/bfg-repo-cleaner/)

### Commands

Patch a file from another branch

```sh
git diff current_branch target_branch -- src/filename | git apply -3
```

## Github CLI

Github command line tool [CLI Github](https://cli.github.com/)

### Install

```sh
brew install github/gh/gh
```

### Usage

To view detail on any command, use ```gh [command] [subcommand] --help```

```sh
gh pr [status, list, view, checkout, create]
gh issue [status, list, view, create]
gh help
```
