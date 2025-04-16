#include <Arduino.h>
#include <WiFi.h>
#include "esp_camera.h"
#include "camera_setup.h"
#include <WebServer.h>   
bool initCamera();
void startCAMWEB();

extern WebServer server;

void setup() {
  Serial.begin(115200);
  Serial.setDebugOutput(true);
  Serial.println();

  if (!initCamera()) {
    Serial.println("Camera error!");
    return; 
  }

  WiFi.softAP("IP-Camera", "12345678");  
  delay(1000);
  Serial.println("Access Point Started");

  startCAMWEB();
}

void loop() {
  server.handleClient();
}
