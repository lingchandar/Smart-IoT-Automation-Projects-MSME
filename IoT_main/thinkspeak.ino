#include <WiFiS3.h>
#include <WiFiClient.h>
#include <DHT.h>

const char* ssid = "YOUR_SSID";
const char* password = "YOUR_PASSWORD";

const char* server = "api.thingspeak.com";
const int port = 80;
const String apiKey = "YOUR_THINGSPEAK_API_KEY";

#define DHTPIN 2  
#define DHTTYPE DHT11 
DHT dht(DHTPIN, DHTTYPE);

WiFiClient client;

unsigned long lastMillis = 0;
const long interval = 15000; 

void setup() {
  Serial.begin(115200);
  while (!Serial);

  dht.begin();

  Serial.print("Connecting to Wi-Fi: ");
  Serial.println(ssid);

  while (WiFi.begin(ssid, password) != WL_CONNECTED) {
    Serial.print(".");
    delay(1000);
  }

  Serial.println("\nConnected to Wi-Fi!");
  Serial.print("IP address: ");
  Serial.println(WiFi.localIP());
}

void loop() {
  unsigned long currentMillis = millis();

  if (currentMillis - lastMillis >= interval) {
    lastMillis = currentMillis;

    float humidity = dht.readHumidity();
    float temperature = dht.readTemperature();

    if (isnan(humidity) || isnan(temperature)) {
      Serial.println("Failed to read from DHT sensor!");
      return;
    }

    Serial.print("Temperature: ");
    Serial.print(temperature);
    Serial.print(" °C | Humidity: ");
    Serial.print(humidity);
    Serial.println(" %");

    if (client.connect(server, port)) {
      String url = "/update?api_key=" + apiKey +
                   "&field1=" + String(temperature) +
                   "&field2=" + String(humidity);

      client.print(String("GET ") + url + " HTTP/1.1\r\n" +
                   "Host: " + server + "\r\n" +
                   "Connection: close\r\n\r\n");

      Serial.println("Data sent to ThingSpeak.");
    } else {
      Serial.println("Failed to connect to ThingSpeak.");
    }

    client.stop(); 
  }
}

