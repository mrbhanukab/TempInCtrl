#pragma once

int currentStateCLK;                // Current state of CLK
int lastStateCLK;                   // Last state of CLK

inline void rotary_encoder_init() {
    lastStateCLK = digitalRead(CLK);
}

inline bool temprature_limit_handler() {
    currentStateCLK = digitalRead(CLK);

    if (currentStateCLK != lastStateCLK) {
        if (digitalRead(DT) != currentStateCLK) {
            temprature_limit--;
        } else {
            temprature_limit++;
        }
        lastStateCLK = currentStateCLK;
        return true;
    }

    lastStateCLK = currentStateCLK;
    return false;
}