#include <SimpleBatteryMonitor.h>
#include <WiFi.h>
#include <WebServer.h>

// WiFi credentials
const char* ssid = "your-SSID";
const char* password = "your-PASSWORD";

// Create an instance of SimpleBatteryMonitor
SimpleBatteryMonitor battery;

// Create a webserver on port 80
WebServer server(80);

void handleRoot() {
  float voltage = battery.readVoltage();
  String html = "<html><body>";
  html += "<h1>Battery Monitor</h1>";
  html += "<p>Battery Voltage: " + String(voltage, 2) + " V</p>";
  html += "<meta http-equiv='refresh' content='5'>"; // Auto-refresh every 5 seconds
  html += "</body></html>";
  server.send(200, "text/html", html);
}

void setup() {
  Serial.begin(115200);
  delay(2000);
  Serial.println("SimpleBatteryMonitor WebServer Example");

  // Configure: ADC pin, R1, R2, Vref, ADC resolution
  battery.configure(5, 330000, 100000, 3.3, 4096); // GPIO5, 330kΩ, 100kΩ, 3.3V, 12-bit
  battery.begin();

  // Connect to WiFi
  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("\nWiFi connected!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());

  // Setup webserver routes
  server.on("/", handleRoot);
  server.begin();
  Serial.println("Webserver started.");
}

void loop() {
  server.handleClient();
}