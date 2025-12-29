#include <ESP8266WiFi.h>
#include <WiFiClient.h>
#include <ThingSpeak.h>

const char* ssid = "Your_SSID";
const char* password = "Your_PASSWORD";

int flamePin = A0;
int flameValue;
WiFiClient client;
unsigned long channelNumber = 123456; 
const char *apiKey = "YOUR_API_KEY";

void setup() {
  Serial.begin(9600);
  delay(10);

  WiFi.begin(ssid, password);
  while (WiFi.status() != WL_CONNECTED) {
    delay(500);
    Serial.print(".");
  }
  Serial.println("WiFi connected");

  ThingSpeak.begin(client);

  pinMode(flamePin, INPUT);
}

void loop() {
  flameValue = analogRead(flamePin);
  int flameLevel = map(flameValue, 0, 1023, 100, 0); 
  Serial.print("Raw Flame Value: ");
  Serial.print(flameValue);
  Serial.print(" | Mapped: ");
  Serial.println(flameLevel);

  switch (flameLevel) {
    case 0 ... 30:
      Serial.println("Close Fire Detected!");
      break;

    case 31 ... 60:
      Serial.println("Distant Fire Detected");
      break;

    default:
      Serial.println("No Fire");
      break;
  }
  ThingSpeak.writeField(channelNumber, 1, flameLevel, apiKey);
  delay(2000);
}
