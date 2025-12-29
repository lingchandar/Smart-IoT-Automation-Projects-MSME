const int potPin = A0; 
const int ledPin = 9;  

void setup() {
  serial.begin(9600);
  pinMode(ledPin, OUTPUT);
}
void loop() {
  int potValue = analogRead(potPin); 
  int brightness = map(potValue, 0, 1023, 0, 255); 
  serial println (potValue);
  analogWrite(ledPin, brightness);
}
