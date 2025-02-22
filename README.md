# TempInCtrl

TempInCtrl is a sleek and efficient temperature control system designed to monitor and regulate temperature with precision. It features a user-friendly interface and real-time updates, making temperature management a breeze.

<img src="/README.Files/main.gif" alt="Project" />

## Table of Contents
- [Introduction](#introduction)
- [Features](#features)
- [Technologies Used](#technologies-used)
- [Setup & Installation](#setup--installation)
- [Usage](#usage)
- [Contribution Guidelines](#contribution-guidelines)
- [License](#license)
- [Credits](#Credits)

## Introduction

TempInCtrl is designed to track the temperature of a specific object and control the temperature using a blower. It aims to provide minimal delay, higher precision, and more informative feedback. The system features an easy-to-use UI/UX on an OLED display, making it accessible and user-friendly. Additionally, it ensures real-time updates and efficient temperature management, catering to users who require precise and reliable temperature control solutions.

## Features

- **Real-time Temperature Monitoring:** Continuously tracks the temperature of a specific object with high precision.
- **Blower Control:** Automatically adjusts the blower to maintain the desired temperature.
- **User-friendly OLED Display:** Provides an easy-to-read interface with real-time updates.
- **Minimal Delay:** Ensures quick response times for temperature adjustments.
- **High Precision:** Offers accurate temperature readings and control.
- **Informative Feedback:** Displays detailed temperature information and system status.
- **Easy UI/UX:** Simple and intuitive user interface for seamless operation.
- **Buzzer Alerts:** Indicates important events like blower on/off with audible alerts.

## Technologies Used

TempInCtrl utilizes PlatformIO with the Arduino framework for development and deployment.

### Libraries

- **Adafruit SSD1306**: For controlling the OLED display.
- **Adafruit GFX Library**: For graphics support on the OLED display.
- **Adafruit BusIO**: For I2C communication.
- **Adafruit MLX90614 Library**: For interfacing with the MLX90614 temperature sensor.


## Setup & Installation

### Prerequisites

- PlatformIO with any supported IDE
- Required libraries:
    - Adafruit SSD1306
    - Adafruit GFX Library
    - Adafruit BusIO
    - Adafruit MLX90614 Library
- Hardware requirements:
    - Rotary encoder
    - Buzzer
    - OLED display
    - GY-906 IR Thermometer
    - Arduino Uno (or any compatible board)

### Steps

#### Wiring

Ensure proper wiring according to the included wiring schema.

<table>
    <tr>
        <td><img src="https://github.com/user-attachments/assets/454f3f92-afbb-4e2e-a68d-5c3f5b85ef94" alt="Project Wiring" /></td>
    </tr>
     <tr>
     <td>
            <ol>
                <li><strong>Rotary Encoder:</strong> CLK Pin 9, DT Pin 10</li>
                <li><strong>Fan:</strong> Pin 11</li>
                <li><strong>Buzzer:</strong> Pin 12</li>
                <li><strong>OLED Display and Thermometer:*</strong> Connect both the OLED display and the MLX90614 thermometer to the SDA and SCL pins of the Arduino device. The specific pins for SDA and SCL vary depending on the Arduino model.</li>
            </ol>
     </td>
     </tr>
</table>

## Usage
### `src/main.cpp`
This is the main file where the setup and loop functions are defined. It initializes the hardware and handles the main logic of the application.
```c++
void setup() {
    ...
    rotary_encoder_init();
    thermometer_init();
    ...
}

void loop() {
    ...
    thermometer_read();
    ...
    if (temprature_limit_handler())
        bottomPanel("Fan: " + String(fan_status ? "ON" : "OFF") + " | Limit: " + String(temprature_limit));
    ...
    fan_control();
}
```

### `include/io_setup.h`
Defines and sets up the I/O pins for the hardware components.

### `include/oled.h`
Handles the initialization and display functions for the OLED screen.
```c++
inline void oled_init() {
    ...
    display.setTextColor(WHITE);
}

inline void bottomPanel(const String& content) {
    ...
    display.print(content);
    display.display();
}

inline void current_temprature(const int temprature)
{
    ...
    display.print(temprature);
    ...
}
```

### `include/thermometer.h`
Initializes and reads the temperature from the MLX90614 sensor.
```c++
void thermometer_init() {
    ...
    bottomPanel("Error: !MLX_Sensor");
    ...
}

void thermometer_read() {
    ...
    current_temprature(temprature);
}
```

### `include/rotary_encoder.h`
Handles the rotary encoder input for setting the temperature limit.
```c++
inline void rotary_encoder_init() {
    ...
}

inline bool temprature_limit_handler() {
    ...
    return false;
}
```

### `include/fan.h`
Controls the fan based on the temperature readings and limit.
```c++
void fan_control() {
    ...
    bottomPanel("Fan: ON | Limit: " + String(temprature_limit));
    ...
    bottomPanel("Fan: OFF | Limit: " + String(temprature_limit));
}
```


## Contribution Guidelines + License
> **Contributions are welcome!**
> This project (Only Codebase) is licensed under [Apache License Version 2](LICENSE). Please make sure to review it before submitting pull requests. We encourage you to add new and creative things! We encourage you to fork the repo, contribute, and build on our ideas. Together, we can make it even better.

## Credits
[TempInCtrl](https://github.com/mrbhanukab/TempInCtrl) is created by [Bhanuka Bandara](https://github.com/mrbhanukab) and Keshan Perera (who also contributed the idea). Feel free to contribute, report issues, or provide suggestions on the GitHub repository. You are free to use the code, but you must obtain permission from Keshan Perera before implementing the same idea, as it belongs to him.

[![github](https://img.shields.io/badge/GitHub-100000?style=for-the-badge&logo=github&logoColor=white)](https://github.com/mrbhanukab)
[![linkedin](https://img.shields.io/badge/LinkedIn-0077B5?style=for-the-badge&logo=linkedin&logoColor=white)](https://www.linkedin.com/in/bhanuka-bandara-8a209420a)
