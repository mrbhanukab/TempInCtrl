#pragma once

#include "icons.h"

#define SCREEN_WIDTH 128 // OLED display width, in pixels
#define SCREEN_HEIGHT 64 // OLED display height, in pixels

// Declaration for an SSD1306 display connected to I2C (SDA, SCL pins)
Adafruit_SSD1306 display(SCREEN_WIDTH, SCREEN_HEIGHT, &Wire, -1);

inline void oled_init() {
    if(!display.begin(SSD1306_SWITCHCAPVCC, 0x3C)) { // Address 0x3D for 128x64
        Serial.println(F("SSD1306 allocation failed"));
        for(;;);
    }
    display.clearDisplay();
    display.setTextSize(1);
    display.setTextColor(WHITE);
}

//? Bottom panel
inline void bottomPanel(const String& content)
{
    // Clear the bottom part of the screen
    display.fillRect(0, 51, SCREEN_WIDTH, 13, SSD1306_BLACK);

    // Draw the horizontal line at y=50
    display.drawLine(0, 50, SCREEN_WIDTH, 50, SSD1306_WHITE);

    display.setTextSize(1);
    display.setCursor(4, 55);
    display.print(content);
    display.display();
}

//? Booting splash screen
inline void booting_splash(const bool isBooted)
{
    display.clearDisplay();
    display.drawBitmap(18, 8, logo, 50, 50, SSD1306_WHITE);
    display.setTextSize(1);
    display.setCursor(60, 12);
    display.print("TempIn");
    display.setTextSize(2);
    display.setCursor(60, 22);
    display.print("CTRL");
    display.setTextSize(1);
    if (isBooted)
    {
        bottomPanel("Booted, Ready!");
    }
    else
    {
        bottomPanel("Booting ...");
    }
    display.display();
}

inline void current_temprature(const int temprature)
{
    display.fillRect(0, 0, SCREEN_WIDTH, 50, SSD1306_BLACK);
    display.drawBitmap(10, (SCREEN_HEIGHT - 45) / 2, temperature, 30, 30, SSD1306_WHITE);
    display.setTextSize(1);
    display.setCursor(50, 10);
    display.print("Temp:");
    display.setTextSize(2);
    display.setCursor(50, 22);
    display.print(temprature);
    display.print(static_cast<char>(247));
    display.print("C");
    display.display();
}