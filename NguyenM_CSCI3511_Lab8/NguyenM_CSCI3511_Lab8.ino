int ledPin = 5;
int buttonApin = 9;
int buttonBpin = 8;

byte leds = 0;

void setup() {
  // put your setup code here, to run once:
  pinMode(ledPin, OUTPUT);
  pinMode(buttonApin, INPUT_PULLUP);
  pinMode(buttonBpin, INPUT_PULLUP);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (digitalRead(buttonApin) == LOW){
    digitalWrite(ledpin, HIGH);
  }
  if (digitalRead(buttonBpin) == LOW){
    digitalWrite(ledPin, LOW);
  }
}
