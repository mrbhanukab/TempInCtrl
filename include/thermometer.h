#pragma once

Adafruit_MLX90614 mlx = Adafruit_MLX90614();

void thermometer_init() {
    if (!mlx.begin()) {
        Serial.println("Error connecting to MLX sensor. Check wiring.");
        bottomPanel("Error: !MLX_Sensor");
        while (1);
    };
}

void thermometer_read() {
    const int current_temp = mlx.readObjectTempC();
    if (temprature != current_temp) {
        temprature = current_temp;
        current_temprature(temprature);
    }
}