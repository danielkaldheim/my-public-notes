# Octopi

## Plugins

- [OctoPrint-Dashboard](https://plugins.octoprint.org/plugins/dashboard/)
- [DisplayLayerProgress](https://plugins.octoprint.org/plugins/DisplayLayerProgress/)
- [OctoPrint-Enclosure](https://plugins.octoprint.org/plugins/enclosure/)
- [Themeify](https://plugins.octoprint.org/plugins/themeify/)
- [TouchUI](https://plugins.octoprint.org/plugins/touchui/)

## Raspberry Pi config

Add to `/boot/config.txt`:

```sh
# uncomment if hdmi display is not detected and composite is being output
hdmi_force_hotplug=1

# uncomment to force a specific HDMI mode (here we are forcing 800x480!)
hdmi_group=2
hdmi_mode=87
hdmi_cvt=800 480 60 6 0 0 0
hdmi_drive=1

...

# Enable one-wire on GPIO pin 17
dtoverlay=w1-gpio,gpiopin=17
```

## Ultimaker

Connection settings:

- Baud: 250000

Printer Profile:

- Width (X): 223mm
- Depth (Y): 223mm
- Height (Z): 205mm

## G-code for Ultimaker Cura

### Start G-code

```gcode
G21 ;metric values
G90 ;absolute positioning
M82 ;set extruder to absolute mode
M107 ;start with the fan off
G28 Z0 ;move Z to bottom endstops
G28 X0 Y0 ;move X/Y to endstops
G1 X15 Y0 F4000 ;move X/Y to front of printer
G1 Z15.0 F9000 ;move the platform to 15mm
G92 E0 ;zero the extruded length
G1 F200 E10 ;extrude 10 mm of feed stock
G92 E0 ;zero the extruded length again
G1 F9000
;Put printing message on LCD screen
M117 Printing...
```

### End G-code

```gcode
M104 S0 ;extruder heater off
M140 S0 ;heated bed heater off
G91 ;relative positioning
G1 E-1 F300  ;retract the filament a bit before lifting the nozzle, to release some of the pressure
G1 Z+0.5 E-5 X-20 Y-20 F9000 ;move Z up a bit and retract filament even more
G28 X0 Y0 ;move X/Y to min endstops, so the head is out of the way
M84 ;steppers off
G90 ;absolute positioning
;Version _2.6 of the firmware can abort the print too early if the file ends
;too soon. However if the file hasn't ended yet because there are comments at
;the end of the file, it won't abort yet. Therefore we have to put at least 512
;bytes at the end of the g-code so that the file is not yet finished by the
;time that the motion planner gets flushed. With firmware version _3.3 this
;should be fixed, so this comment wouldn't be necessary any more. Now we have
;to pad this text to make precisely 512 bytes.
```
