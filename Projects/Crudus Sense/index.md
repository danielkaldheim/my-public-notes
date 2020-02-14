# Crudus Sense

![Sensor board 3D](./images/Sensor&#32;board&#32;3d.jpg)

![Sensor board PCB](./images/Sensor&#32;board&#32;pcb.png)

![Sensor board schematics](./images/Sensors&#32;board.png)

\newpage
\blandscape

## BLE device configuration specification

| Name                     | Type                     | R/W | Key          | UUID                                 | Comment                                                   |
| ------------------------ | ------------------------ | --- | ------------ | ------------------------------------ | --------------------------------------------------------- |
| Device name              | String                   | R/W | deviceName   | 5759f8cc-69ee-11e9-8a12-1681be663d3e |                                                           |
| WiFi Mac                 | String                   | R   |              | 51ecb1ca-6b85-11e9-a923-1681be663d3e | Read from ESP and register device to Crudus sense backend |
| WiFi SSID                | String                   | R/W | wifi-ssid    | 51ecb440-6b85-11e9-a923-1681be663d3e |                                                           |
| WiFi passwd              | String                   | W   | wifi-pwd     | 51ecb594-6b85-11e9-a923-1681be663d3e |                                                           |
| Room                     | String                   | R/W | loc-room     | 51ecb6ca-6b85-11e9-a923-1681be663d3e |                                                           |
| Floor                    | Integer?                 | R/W | loc-floor    | 51ecb7f6-6b85-11e9-a923-1681be663d3e |                                                           |
| Compound                 | String                   | R/W | Loc-comp     | 51ecb922-6b85-11e9-a923-1681be663d3e |                                                           |
| MQTT topic               | String                   | R/W | mqtt-topic   | 51ecba4e-6b85-11e9-a923-1681be663d3e | Only if MQTT-host is changed                              |
| MQTT host                | String                   | R/W | mqtt-host    | 51ecbf26-6b85-11e9-a923-1681be663d3e | Disables default mqtt host                                |
| MQTT port                | Integer                  | R/W | mqtt-port    | 51ecc156-6b85-11e9-a923-1681be663d3e | Only if MQTT-host is changed                              |
| MQTT username            | String                   | R/W | mqtt-user    | 51ecc2c8-6b85-11e9-a923-1681be663d3e | Only if MQTT-host is changed                              |
| MQTT password            | String                   | W   | mqtt-pwd     | 51ecc3fe-6b85-11e9-a923-1681be663d3e | Only if MQTT-host is changed                              |
| Crudus Accounts username | String                   | W   | crudus-user  | 51ecc52a-6b85-11e9-a923-1681be663d3e | For setting default MQTT topic and MQTT username          |
| Crudus Accounts token    | String                   | W   | crudus-token | 51ecc6d8-6b85-11e9-a923-1681be663d3e | For OTA downloads and MQTT password / token               |
| Calibration temperature  | String (comma separated) | R/W | cali-temp    | 51ecca5c-6b85-11e9-a923-1681be663d3e | For calibrate temperature                                 |
| Calibration humidity     | String (comma separated) | R/W | cali-hum     | 51eccbb0-6b85-11e9-a923-1681be663d3e | For calibrate humidity                                    |
| Soft reset               | boolean                  | W   | soft-reset   | 51eccd18-6b85-11e9-a923-1681be663d3e | For clearing preferences                                  |

\elandscape
\newpage

## MQTT publish Topics

| Topic | Payload | Comment |
| ----- | ------- | ------- |
|       |         |         |

## MQTT Subscribe Topics

| Topic      | Payload | Action               | Comment |
| ---------- | ------- | -------------------- | ------- |
| /sense/ota |         | Calls OTA for update |         |

## Extensions

Sleep Tracking using an Arduino
<https://duino4projects.com/sleep-tracking-using-an-arduino/>

Reset:
<https://www.esp8266.com/viewtopic.php?t=9558&start=8>

Chip: CCS811 (indoor air quality sensor)
