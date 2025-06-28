#include <ESP8266WiFi.h>

// Replace these with your Wi-Fi network credentials
const char* ssid = "YourSSID";
const char* password = "YourPassword";

const int ledPin = D1; // GPIO 5
const int blinkInterval = 500; // Blink interval in milliseconds

void setup() {
  Serial.begin(115200);
  pinMode(ledPin, OUTPUT);
  digitalWrite(ledPin, LOW); // Ensure the LED is off initially

  Serial.println("Connecting to Wi-Fi...");

  WiFi.begin(ssid, password);

  while (WiFi.status() != WL_CONNECTED) {
    delay(1000);
    Serial.print(".");
  }

  Serial.println();
  Serial.print("Connected to ");
  Serial.println(ssid);
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  if (WiFi.status() == WL_CONNECTED) {
    digitalWrite(ledPin, HIGH); // Turn the LED on
    delay(blinkInterval);
    digitalWrite(ledPin, LOW); // Turn the LED off
    delay(blinkInterval);
  } else {
    digitalWrite(ledPin, LOW); // Ensure the LED is off if not connected
  }
}
