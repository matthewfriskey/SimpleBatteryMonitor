// SimpleBatteryMonitor.cpp
#include "SimpleBatteryMonitor.h"

SimpleBatteryMonitor::SimpleBatteryMonitor() {
  // Constructor: Initialize defaults (already set in the class definition)
}

void SimpleBatteryMonitor::configure(int adcPin, float r1, float r2, float vRef, int adcResolution) {
  _adcPin = adcPin;
  _r1 = r1;
  _r2 = r2;
  _vRef = vRef;
  _adcResolution = adcResolution;

  // Compute the divider ratio and scale factor
  _dividerRatio = _r2 / (_r1 + _r2);
  _scaleFactor = (_vRef / (float)(_adcResolution - 1)) / _dividerRatio;

  _isConfigured = true;
}

void SimpleBatteryMonitor::begin() {
  // Optional: Initialize Serial or other setup if needed
  // For now, just ensure the pin is set as input
  if (_adcPin >= 0) {
    pinMode(_adcPin, INPUT);
  }
}

float SimpleBatteryMonitor::readVoltage() {
  if (!_isConfigured) {
    // Return 0 if not configured
    return 0.0;
  }

  // Read the ADC value
  int adcValue = analogRead(_adcPin);

  // Convert to the original voltage (before the divider)
  float voltage = adcValue * _scaleFactor;

  return voltage;
}