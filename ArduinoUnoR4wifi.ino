#include <WiFiS3.h>

const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";

void setup() {
  Serial.begin(115200);
  while (!Serial); 

  Serial.print("Attempting to connect to SSID: ");
  Serial.println(ssid);

  while (WiFi.begin(ssid, password) != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }

  Serial.println("\nConnected to Wi-Fi!");
  Serial.print("IP Address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - lastMillis >= interval) {
    lastMillis = currentMillis;

    float temperature = random(200, 300) / 10.0;
    Serial.print("Sensor Reading -> Temperature: ");
    Serial.print(temperature);
    Serial.println(" °C");
}
}
