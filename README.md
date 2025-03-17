# SimpleBatteryMonitor

A simple library to monitor battery voltage using a voltage divider and an ADC pin. Designed for battery-powered projects, this library allows you to configure the ADC pin, voltage divider resistors (R1 and R2), reference voltage, and ADC resolution, then read the scaled input voltage.

## Features
- Configurable ADC pin, voltage divider resistors, reference voltage, and ADC resolution.
- Simple `readVoltage()` method to get the scaled input voltage.
- Suitable for use in Serial printing, webservers, or other applications.
- Compatible with ESP32, ESP8266, and other Arduino boards.

## Installation
1. Install via PlatformIO:`pio lib install SimpleBatteryMonitor`
2. Or clone this repository into your 'lib' folder.

## Example
```cpp
#include <SimpleBatteryMonitor.h>

// Create an instance of BatteryMonitor
BatteryMonitor battery;

// Setup
void setup() {
  Serial.begin(115200);
  delay(2000);

  // Configure: ADC pin, R1, R2, Vref, ADC resolution
  battery.configure(5, 330000, 100000, 3.3, 4096); // GPIO5, 330kΩ, 100kΩ, 3.3V, 12-bit
  battery.begin();
}

// Loop
void loop() {
  float voltage = battery.readVoltage();
  Serial.print("Battery Voltage: ");
  Serial.print(voltage);
  Serial.println(" V");
  delay(5000);
}