const int flameSensorPin = A0;
const int ledPin = 9; 
const int sensorMin = 0;
const int sensorMax = 1024;         

int flameValue;
int range

void setup() {
  pinMode(flameSensorPin, INPUT);
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  int flameValue = analogRead(flameSensorPin);
  int range = map(sensorReading, sensorMin, sensorMax,0,3); 


  switch (range) {
    case 1:
      digitalWrite(ledPin, HIGH);
      Serial.println("Close Fire Detected!");
      break;

    case 2:
      analogWrite(ledPin, 128); 
      Serial.println("Distant Fire Detected!");
      break;

    case 3:
      digitalWrite(ledPin, LOW);
      Serial.println("No Fire");
      break;
  }

  delay(300);
}
