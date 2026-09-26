# Arduino Uno R3 Projects

## Index

1. Basic LED Blink
2. Analog Read + Serial Monitor
3. LED Fade / Pin 13 Experiment
4. Four LED Potentiometer Selector
5. Eight LED Four-Pattern Controller
6. Eight-Key Arduino Mini Piano
7. Two-Pin Button Test

## Purpose

This collection records the Arduino projects actually built/tested in the learning sequence. It is organized from fundamental digital I/O through analog input, timing, arrays, state-based LED patterns, and sound generation.

## Hardware used across the work

Arduino Uno R3, breadboard, jumper wires, LEDs, 220/330 ohm resistors, 1k/10k/100k resistors, 10k potentiometer, push buttons, 2N2222/BC547 transistors, IRFZ44N MOSFET, ceramic and electrolytic capacitors, diodes, small motors, and a 4-ohm 2-watt speaker.

## 01 — Basic LED Blink

The onboard L LED on D13 is turned on for 1500 ms and off for 500 ms. This teaches `pinMode()`, `digitalWrite()`, `delay()`, and the Arduino `setup()/loop()` structure.

## 02 — Analog Read + Serial Monitor

A0 is sampled with `analogRead()`. On an Uno the ADC normally returns 0–1023. `Serial.begin(9600)` establishes serial communication and `Serial.println()` prints the reading. A potentiometer is an ideal input.

## 03 — LED Fade / Pin 13 Experiment

The Uno's D13 is not a hardware PWM pin. Hardware PWM is available on D3, D5, D6, D9, D10 and D11. This sketch demonstrates a software-timed approximation on the onboard LED. For a genuine PWM fade, use a PWM pin and `analogWrite()`.

## 04 — Four LED Potentiometer Selector

D2-D5 each drive an LED through its own 220-ohm resistor. A 10k potentiometer feeds A0. The 0–1023 ADC range is divided into four regions, selecting one LED at a time. This demonstrates analog-to-digital threshold control.

## 05 — Eight LED Four-Pattern Controller

Eight LEDs use D2-D9. A switch is wired between D12 and D13; D12 uses `INPUT_PULLUP` and D13 is held LOW. Four patterns are included: smooth trail, alternating blink, fill/clear, and center-out. The program demonstrates arrays, loops, functions, `switch/case`, debouncing, persistent state variables, and non-blocking `millis()` timing.

The use of `millis()` is important: long `delay()` calls would prevent responsive button checking. `millis()` allows the program to repeatedly check the button while also updating the animation.

## 06 — Eight-Key Arduino Mini Piano

Eight buttons on D2-D9 map to C4 through C5. The note frequencies are 262, 294, 330, 349, 392, 440, 494 and 523 Hz. `tone()` generates a square wave on D10.

Buttons use `INPUT_PULLUP`, so a released button reads HIGH and a pressed button reads LOW. The same array index connects each button to its note frequency. The current sketch is monophonic: it plays the first pressed button it finds.

A 4-ohm speaker must not be connected directly to an Uno GPIO. Use a suitable transistor driver or, preferably for a 2 W speaker, a small audio amplifier. A 2N2222 is a switching transistor and should not be treated as a 2 W audio amplifier.

## 07 — Two-Pin Button Test

D12 is connected to a two-pin push button and the other button terminal goes to GND. `INPUT_PULLUP` makes the released state HIGH and pressed state LOW. D13 drives the onboard L LED as an indicator. This test was useful for confirming that ordinary two-pin tactile switches work; the earlier issue was physical alignment on the breadboard.

# Core concepts learned

### Digital I/O

`pinMode()`, `digitalRead()`, and `digitalWrite()`.

### Analog input

`analogRead()` and the Uno's 10-bit ADC range of 0–1023.

### Serial communication

`Serial.begin(9600)` and `Serial.println()`.

### PWM

Uno hardware PWM pins: D3, D5, D6, D9, D10, D11.

### Arrays and loops

Used to manage multiple LEDs/buttons without duplicating code.

### Functions

Used to separate patterns and keep the program readable.

### State

Variables such as `pattern`, `position`, and `filling` remember what the program is doing between loop iterations.

### Debouncing

Mechanical buttons can electrically bounce for a few milliseconds. Debouncing prevents one physical press from being interpreted as many presses.

### `millis()`

Provides non-blocking timing so animations and input handling can run together.

### `tone()`

Generates a square-wave audio signal at a requested frequency.

# Safety and hardware notes

- Give every normal LED its own current-limiting resistor.
- Do not drive motors directly from Arduino GPIO pins.
- Use a flyback diode when switching brushed DC motors with a transistor/MOSFET.
- IRFZ44N is not an ideal logic-level MOSFET for direct 5 V Arduino gate drive; a logic-level MOSFET such as IRLZ44N is generally a better choice.
- Electrolytic capacitors are polarized; observe + and -.
- Do not connect a 4-ohm speaker directly to an Arduino GPIO.
- A 2N2222 is not a 2 W audio amplifier.
- For mains-voltage experiments, use proper isolation and rated hardware; do not experiment directly from household mains on a breadboard.

# Suggested next projects

LDR automatic light, LM35 thermometer, PIR motion alarm, HC-SR04 distance meter, DHT11/22 weather station, MPU6050 motion/tilt sensor, RC522 RFID project, 74HC595 LED expansion, NE555 timer, LM358 analog sensor amplifier, LM393 comparator, and TB6612FNG motor controller.

# Folder structure

```
arduino_projects/
├── README.md
├── 01_LED_Blink/
│   └── LED_Blink.ino
├── 02_Analog_Read_Serial/
│   └── Analog_Read_Serial.ino
├── 03_LED_Fade_Pin13/
│   └── LED_Fade_Pin13.ino
├── 04_4LED_Potentiometer/
│   └── 4LED_Potentiometer.ino
├── 05_8LED_4Patterns/
│   └── 8LED_4Patterns.ino
├── 06_8Key_Arduino_Piano/
│   └── 8Key_Arduino_Piano.ino
└── 07_Button_Test/
    └── Button_Test.ino
```

## Important scope note

This portfolio includes projects that were actually implemented/tested in the learning sequence. Discussed-but-not-yet-built projects such as the BC547 touch light, IRFZ44N motor controller, capacitor visualizer, PIR projects, ultrasonic projects and Li-Fi/laser communication are intentionally not presented as completed.
