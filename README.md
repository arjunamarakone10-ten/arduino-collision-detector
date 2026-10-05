# Arduino Collision Detector

An ultrasonic proximity alarm built on an Arduino UNO, similar to a car's parking sensor.

## Features
- Continuously measures distance using an HC-SR04 ultrasonic sensor
- Displays live distance readout on an LCD
- RGB LED shifts green to yellow to red as an object gets closer
- Buzzer frequency increases the nearer an object gets
- Fully non-blocking, all outputs update independently in real time

## Components
- Arduino UNO
- HC-SR04 ultrasonic sensor
- RGB LED
- Buzzer
- 16x2 LCD display with potentiometer

## What I learned
Moved past simple digital I/O into pulse-duration sensing (pulseIn()), range mapping (map()), and frequency control (tone()). Rebuilding the timing logic around millis() instead of delay() was the key shift, since every output needed to update independently without blocking the others.

## Status
Complete
