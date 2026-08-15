#include <WiFi.h>
#include <WebServer.h>

#include "index.h"
#include "pzem_sensor.h"
#include "display_oled.h"

const char* ssid = "Power Monitor";
const char* password = "power123";

WebServer server(80);
PowerData powerData;
unsigned long lastReadTime = 0;

void handleRoot() {
    server.send(200, "text/html", html_page);
}

void handleData() {
    String json = "{";
    json += "\"v\":" + String(powerData.voltage) + ",";
    json += "\"i\":" + String(powerData.current) + ",";
    json += "\"p\":" + String(powerData.power) + ",";
    json += "\"e\":" + String(powerData.energy) + ",";
    json += "}";
    server.send(200, "application/json", json);
}

void setup() {
    Serial.begin(115200);

    initOLED();

    WiFi.softAP(ssid, password);
    IPAddress myIP = WiFi.softAPIP();
    Serial.print("AP IP Address: ");
    Serial.println(myIP);

    server.on("/", handleRoot);
    server.on("/data", handleData);
    server.begin();
    Serial.println("Web Server aktif!");
}

void loop() {
    server.handleClient();

    if (millis() - lastReadTime >= 2000) {
        lastReadTime = millis();

        updatePZEMData(powerData);

        updateOLEDDisplay(powerData);

        Serial.printf("V: %.1fV | I: %.2fA | P: %.1fW | E: %.3fkWh\n", 
                      powerData.voltage, powerData.current, powerData.power, powerData.energy);
    }
}