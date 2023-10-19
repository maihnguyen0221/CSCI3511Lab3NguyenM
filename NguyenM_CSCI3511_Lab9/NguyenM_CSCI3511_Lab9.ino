int potpin = 6;
int ledpin = 9;
int brightness;

void setup() {

  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(ledpin,OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int potvalue = analogRead(potpin);
  
  brightness = map(potvalue, 0, 1023, 0, 255);
  analogWrite(ledpin, brightness);

}
