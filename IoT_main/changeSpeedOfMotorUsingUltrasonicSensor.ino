const int trigPin = 10;
const int echoPin = 11;

long duration;
int distanceCM, distanceInch;

int enA = 9;
int in1 = 8;
int in2 = 7;

void setup() {
  pinMode(enA, OUTPUT);
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
  
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);

  Serial.begin(9600);
  delay(100);
}

void loop() {
  SpeedControl();
  delay(100);

  Serial.print("Distance CM: ");
  Serial.print(distanceCM);
  Serial.print(" | Duration: ");
  Serial.println(duration);

void SpeedControl() {
  digitalWrite(trigPin, LOW);
  delayMicroseconds(2);
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(10);
  digitalWrite(trigPin, LOW);

  duration = pulseIn(echoPin, HIGH);
  distanceCM = duration * 0.034 / 2;
  distanceInch = duration * 0.0133 / 2;

  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);

  int speed = map(distanceCM, 5, 30, 255, 0);
  speed = constrain(speed, 0, 255);

  analogWrite(enA, speed);
}
