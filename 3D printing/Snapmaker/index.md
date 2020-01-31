# Snapmaker

<https://forum.snapmaker.com/t/reverse-engineering-the-module-wiring/3031>

**3D Printing Module:**

```sh
PIN1: VCC, Heater Socket Pin 1, Fan+
PIN2: Stepper Coil A+
PIN3: Heater Socket Pin 2
PIN4: Stepper Coil A-
PIN5: Thermistor Socket Pin 1
PIN6: Stepper Coil B-
PIN7: GND, Fan-, Thermistor Socket Pin 2
PIN8: Stepper Coil B+
```

**Heated Build Plate:**

```sh
PIN1: Heating Element +
PIN2: UNUSED
PIN3: Heating Element -
PIN4: UNUSED
PIN5: Thermistor +
PIN6: Thermistor -
```

The heating element registered as 12Ohms so 48W at 24V. The Thermistor gave a reading of 80kOhm in my 90 degree F garage.

**Linear Module:**

```sh
PIN1: Coil A +
PIN2: Coil A -
PIN3: Coil B +
PIN4: Limit Switch +
PIN5: Coil B -
PIN6: Limit Switch -
```
