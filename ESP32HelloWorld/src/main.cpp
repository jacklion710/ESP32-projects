#include <Arduino.h>

const int ledPin = 2;

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(921600);
  Serial.println("Hello from the setup");
}

void loop() {
  delay(1000);
  digitalWrite(ledPin, HIGH);
  Serial.println("Hello from the loop");
  delay(1000);
  digitalWrite(ledPin, LOW);
}