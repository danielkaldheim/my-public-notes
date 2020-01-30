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
