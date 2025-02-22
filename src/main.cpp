#include <Arduino.h>

#include "libraries.h"
#include "global_variables.h"
#include "io_setup.h"
#include "oled.h"
#include "thermometer.h"
#include "rotary-encoder.h"
#include "fan.h"

/* Tasks:
* - [x] read Temprature & display (100ms)
* - [x] read Rotary Encoder & update bottom panel (300ms)
* - [x] ctrl fan and update bottom panel (1100ms)
*/

//? Timing variables
unsigned long previousReadTempratureHandleMillis = 0;
unsigned long previousReadRotaryEncoderIntervalHandleMillis = 0;
unsigned long previousFanControlIntervalHandleMillis = 0;

//? Interval constants
const long readTempratureInterval = 10;
const long readRotaryEncoderInterval = 10;
const long fanControlInterval = 100;

void setup() {
    io_setup();
    Serial.begin (9600);
    oled_init();
    booting_splash(false);
    rotary_encoder_init();
    thermometer_init();
    delay(1500); //for aesthetics you know ;)
    booting_splash(true);
    delay(500);
     bottomPanel("Fan: " + String(fan_status ? "ON" : "OFF") + " | Limit: " + String(temprature_limit));
}

void loop() {
    unsigned long currentMillis = millis();

    //! read Temprature
    if (currentMillis - previousReadTempratureHandleMillis >= readTempratureInterval) {
        previousReadTempratureHandleMillis = currentMillis;
        thermometer_read();
     }

    //! Read Rotary Encoder & update bottom panel
    if (currentMillis - previousReadRotaryEncoderIntervalHandleMillis >= readRotaryEncoderInterval) {
        previousReadRotaryEncoderIntervalHandleMillis = currentMillis;
        if(temprature_limit_handler())
          bottomPanel("Fan: " + String(fan_status ? "ON" : "OFF") + " | Limit: " + String(temprature_limit));
    }

    //! Control fan and update bottom panel
    if (currentMillis - previousFanControlIntervalHandleMillis >= fanControlInterval) {
        previousFanControlIntervalHandleMillis = currentMillis;
        fan_control();
    }

}