# Useful Commands

## Terminal recording

[Asciinema](https://asciinema.org/docs/how-it-works)

### 1. Install

```sh
brew install asciinema
```

### 2. Record

```sh
asciinema rec filename.cast
```

### 3. Play

```sh
asciinema play filename.cast
```

## WiFi QR-code

```sh
qrencode -o wifi.png "WIFI:T:WPA;S:<SSID>;P:<PASSWORD>;;"
```

## Rsync

[Rsync cheatsheat](https://devhints.io/rsync)

```sh
# syncing folder src into dest:
rsync -avzP ./src /dest
# syncing the content of src into dest:
rsync -avzP ./src/ /dest
```

## Unite PDF documents

### Install

```sh
brew install poppler
```

### Usage

```sh
pdfunite file1.pdf file2.pdf output.pdf
```
