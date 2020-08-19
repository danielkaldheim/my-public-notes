# Systemair

Model: Systemair  VR 400 DCV/B R

## Images

![Make and model](./images/IMG_3640.jpeg)
![Controller unit datalines](./images/IMG_1649.jpeg)
![Remote controller modbus settings](./images/IMG_3642.jpeg)
![Controller board](./images/IMG_3644.jpeg)
![Oscilloscope measurements from usb to rs485 (modbus signal)](./images/IMG_3641.jpeg)

![FT232 USB cable](./images/IMG_3645.jpeg)
![SparkFun Transceiver Breakout - RS-485](./images/IMG_3646.jpeg)
![RJ45](./images/IMG_3647.jpeg)
Pin 4 -> B (Blue -> Yellow), Pin 5 -> A (Half Blue -> Green) (Note. I know they are switched around on this picture)

![Pinout RJ45](./images/RJ-45-Pinout-T-568B-pin-diagram.jpg)

![Wiring systemair](./images/wiring-systemair.png)

![Wiring RS-485](./images/IMG_3648.jpeg)

## Hardware

### USB to RS485

```sh
/dev/ttyACM0
```

## Software

[Airiana - SystemAir control](https://github.com/BeamCtrl/Airiana)

```sh
curl https://bootstrap.pypa.io/get-pip.py -o get-pip.py
python get-pip.py
```

## Issues

Unable to connect to Modbus.

Airiana dump of RAM/err and RAM/out:
[Gist Dump](https://gist.github.com/danielkaldheim/cca07903f6734031c1fda6edd6703354)
