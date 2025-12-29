const int in1 = 8; 
const int in2 = 9;  

void setup() {
  pinMode(in1, OUTPUT);
  pinMode(in2, OUTPUT);
}

void loop()
 {
  digitalWrite(in1, HIGH);
  digitalWrite(in2, LOW);
  serial.println("Motor FW")
  delay(2000);
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  serial.println("Motor FW LOW")
  delay(1000);
  digitalWrite(in1, LOW);
  digitalWrite(in2, HIGH);
  serial.println("Motor BW")
  delay(2000);  
  digitalWrite(in1, LOW);
  digitalWrite(in2, LOW);
  serial.println("Motor BW LOW")
  delay(1000);
}
