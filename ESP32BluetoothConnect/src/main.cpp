#include <Arduino.h>
#include <BluetoothSerial.h>

BluetoothSerial SerialBT;

void setup() {
  Serial.begin(921600);
  SerialBT.begin("ESP32_BT"); // Set the Bluetooth device name
  Serial.println("Bluetooth device is ready to pair");
}

void loop() {
  if (Serial.available()) {
    String message = Serial.readString();
    SerialBT.println(message);
  }

  if (SerialBT.available()) {
    String message = SerialBT.readString();
    Serial.println("Received message: " + message);
  }
  delay(20);
}