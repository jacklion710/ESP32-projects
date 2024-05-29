# ESP32 Projects

A collection of various experiments I have done while exploring the ESP32 CP210x embedded device. Each project consists of a core concept which can be extrapolated from or studied as educational content.

## Project Contents

- `Hello World`: Simple 'Hello World' program which prints a message to the serial console and blinks an LED on boards which include one (doesn't blink on boards that only feature a power LED indicator).
- `WiFi Connect`: Connect to WiFi and report connection to the console. Accompanying this project is the `node-esp-wifi-ping` project which runs a node server locally to send a message to ESP32 over WiFi.
- `Bluetooth Connect`: Makes the device available via bluetooth connection which allows for serial IO between ESP32 and the bluetooth connected device.