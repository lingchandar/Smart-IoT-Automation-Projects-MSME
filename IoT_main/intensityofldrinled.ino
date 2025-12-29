const int ldrPin = 7;
const int ledPin = 13;   

void setup() {
  pinMOde(ledPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int ldrValue = analogRead(ldrPin); 

  Serial.print("LDR Value: ");
  Serial.println(ldrValue);

  if (ldrValue < 500) {
    digitalWrite(ledPin, HIGH); 
  } else {
    digitalWrite(ledPin, LOW); 
  }

  delay(200); 
}
