const int ldrPin = A0;     
const int ledPin = 9;      

void setup() {
  pinMode(ledPin, OUTPUT);
  Serial.begin(9600);  
  pinMode(ldrpin, INPUT);    
}

void loop() {
  int ldrstatus = analogRead(ldrPin);
  Serial.println(ldrstatus);                   
  if(ldrstatus <= 80)
  {
    digitalWrite (ledpin, HIGH);
    delay(200);
  }
