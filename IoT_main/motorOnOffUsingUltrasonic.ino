long duration;
int echoPin = 10;
int trigPin = 9;
int distance;

int m1 = 11;
int m2 = 12;

void setup() {
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(m1, OUTPUT);
  pinMode(m2, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(5);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distance = duration * 0.034 / 2;

  Serial.print("Distance = ");
  Serial.println(distance);

  if (distance > 25) {
    digitalWrite(m1, HIGH);
    digitalWrite(m2, LOW);
    Serial.println("Motor FORWARD");
  } 
  else if (distance < 10) {
    digitalWrite(m1, LOW);
    digitalWrite(m2, HIGH);
    Serial.println("Motor BACKWARD");
  } 
  else {
    digitalWrite(m1, LOW);
    digitalWrite(m2, LOW);
    Serial.println("Motor STOP");
  }

  delay(200);
}
