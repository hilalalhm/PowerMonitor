#ifndef DISPLAY_OLED_H
#define DISPLAY_OLED_H

#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include "pzem_sensor.h"

#define SCREEN_WIDTH 128
#define SCREEN_HEIGHT 64
#define OLED_RESET -1

Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, OLED_RESET);

void initOLED() {
    if (!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) {
        Serial.println(F("Gagal menginisialisasi OLED"));
    } else {
        display.clearDisplay();
        display.setTextColor(WHITE);
        display.setTextSize(1);
        display.setCursor(15, 20);
        display.println("MONITOR LISTRIK");
        display.setCursor(30, 40);
        display.println("Memulai...");
        display.display();
    }
}

void updateOLEDDisplay(const PowerData &data) {
    display.clearDisplay();
    display.setTextColor(WHITE);

    display.drawFastHLine(0, 31, 128, WHITE); // Garis mendatar di tengah
    display.drawFastVLine(63, 0, 64, WHITE);  // Garis tegak di tengah

    display.setTextSize(1);
    display.setCursor(2, 2);
    display.print("TEGANGAN");
    display.setCursor(2, 16);
    display.print(data.voltage, 1);
    display.print(" V");

    display.setTextSize(1);
    display.setCursor(67, 2);
    display.print("ARUS");
    display.setCursor(67, 16);
    display.print(data.current, 2);
    display.print(" A");

    display.setTextSize(1);
    display.setCursor(2, 34);
    display.print("DAYA");
    display.setCursor(2, 48);
    display.print(data.power, 1);
    display.print(" W");

    display.setTextSize(1);
    display.setCursor(67, 34);
    display.print("ENERGI");
    display.setCursor(67, 48);
    display.print(data.energy, 2);
    display.print(" kWh");

    display.display();
}

#endif