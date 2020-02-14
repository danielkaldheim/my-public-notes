# Espressif

## ESP Voice stream

<https://snips.ai>

<https://www.hackster.io/julianfschroeter/esp32-voice-streamer-52bd7e>

```sh
nc -l 4444 | mplayer -quiet -rawaudio samplesize=1:channels=1:rate=8000 -demuxer rawaudio -
```
