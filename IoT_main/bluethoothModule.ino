int led = 13;
char data;

void setup() {
  Serial.begin(9600);      
  pinMode(led, OUTPUT);    
}

void loop() 
{
  if (Serial.available() > 0) 
  {
    data = Serial.read();     
    Serial.println(data);        

    if (data == 'A') {
      digitalWrite(led, HIGH);  
    } else if (data == 'B') {
      digitalWrite(led, LOW);   
    }
  }
}