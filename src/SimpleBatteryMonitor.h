// SimpleBatteryMonitor.h
#ifndef SIMPLE_BATTERY_MONITOR_H
#define SIMPLE_BATTERY_MONITOR_H

#include <Arduino.h>

class SimpleBatteryMonitor {
public:
  // Constructor
  SimpleBatteryMonitor();

  // Configure the monitor with ADC pin, resistors, reference voltage, and resolution
  void configure(int adcPin, float r1, float r2, float vRef = 3.3, int adcResolution = 4096);

  // Initialize the monitor (optional setup, e.g., for Serial)
  void begin();

  // Read the scaled voltage (returns the input voltage before the divider)
  float readVoltage();

private:
  int _adcPin = -1;        // ADC pin (default: uninitialized)
  float _r1 = 0.0;         // Resistor R1 (default: 0, unconfigured)
  float _r2 = 0.0;         // Resistor R2 (default: 0, unconfigured)
  float _vRef = 3.3;       // ADC reference voltage (default: 3.3V for ESP32)
  int _adcResolution = 4096;  // ADC resolution (default: 12-bit, 0-4095)

  float _dividerRatio = 0.0;  // Computed divider ratio (R2 / (R1 + R2))
  float _scaleFactor = 0.0;   // Computed scale factor for voltage calculation
  bool _isConfigured = false; // Flag to ensure configuration before reading
};

#endif