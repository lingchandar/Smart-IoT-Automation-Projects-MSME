const int soilMoisturePin = A0;
void setup() {
 Serial.begin(9600); 
}
void loop() {
 int soilMoistureValue = analogRead(soilMoisturePin);
 int moisturePercentage = map(soilMoistureValue, 0, 1023, 0, 100);
 Serial.print("Soil Moisture: ");
 Serial.print(moisturePercentage);
 Serial.println("%");
 delay(1000);
}
