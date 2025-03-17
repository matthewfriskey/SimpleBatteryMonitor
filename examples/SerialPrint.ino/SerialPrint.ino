#include <SimpleBatteryMonitor.h>

// Create an instance of SimpleBatteryMonitor
SimpleBatteryMonitor battery;

void setup() {
  Serial.begin(115200);
  delay(2000);
  Serial.println("SimpleBatteryMonitor Serial Print Example");

  // Configure: ADC pin, R1, R2, Vref, ADC resolution
  battery.configure(5, 330000, 100000, 3.3, 4096); // GPIO5, 330kΩ, 100kΩ, 3.3V, 12-bit
  battery.begin();
}

void loop() {
  float voltage = battery.readVoltage();
  Serial.print("Battery Voltage: ");
  Serial.print(voltage);
  Serial.println(" V");
  delay(5000);
}