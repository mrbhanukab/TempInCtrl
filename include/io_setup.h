#pragma once

//! Here Define All The I/O Pins
//? Rotary Encoder Pins
#define CLK 9
#define DT 10
#define FAN 11
#define BUZZER 12

inline void io_setup() {
    pinMode (CLK, INPUT);
    pinMode (DT, INPUT);
    pinMode (FAN, OUTPUT);
    pinMode (BUZZER, OUTPUT);
}