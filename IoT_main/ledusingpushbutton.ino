const int buttonPin = 2;  
const int ledPin = 13;        
bool ledState = false;        
bool lastButtonState = LOW;   

void setup() {
  pinMode(buttonPin, INPUT_PULLUP);  
  pinMode(ledPin, OUTPUT);
  serial.begin(9600);
}

void loop() {
  bool buttonState = digitalRead(buttonPin);

  if (buttonState == LOW && lastButtonState == HIGH) {
    ledState = !ledState;
    digitalWrite(ledPin, ledState ? HIGH : LOW);
    delay(200); 
  }

  lastButtonState = buttonState;
}
