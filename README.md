# led-strip
Smart ledstrip for use at my desk

# Hardware

## Arduino

For this project i am using an Arduino Nano

### Other components

1m RGB LED strip
12 V Power supply
3x TIP122 Transistors
3x 1k resistors

# Software

## Arduino

The arduino uses the `led.ino` code.

## Controller

### Python

The controller on the computer runs on the `main.py` python code.
It is in a test stage with 2 While loops i swap between.
The first taking the 5 most dominant color on my screen, and randomly choosing one to display with the led
The secod one is just taking a hexadexcimal RGB value to display

### C# (Windows forms application)

**Currently unavailable** - Trying to upload

This program currently has 10 buttons, 3 for RGB, 3 for Cyan, Purple and Yellow, 1 for White, 1 for off and 1-1 for closing and opening serial connection.
Planning to add a colorwheel, and rainbow button after i figure out the final place of the led strip and it's wiring.
