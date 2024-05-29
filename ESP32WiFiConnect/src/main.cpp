#include <Arduino.h>
#include <WiFi.h>
#include <WebServer.h>

const char* ssid = "ssid";
const char* password = "password";

WebServer server(80);

void handleMessage() {
  if (server.hasArg("message")) {
    String message = server.arg("message");
    Serial.println("Received message: " + message);
    server.send(200, "text/plain", "Message received");
  } else {
    server.send(400, "text/plain", "Invalid request");
  }
}

void setup() {
  Serial.begin(921600);
  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.println("Connecting to WiFi...");
  }

  Serial.println("Connected to WiFi");
  Serial.println("IP address: " + WiFi.localIP().toString());

  server.on("/message", handleMessage);
  server.begin();
}

void loop() {
  server.handleClient();
}
