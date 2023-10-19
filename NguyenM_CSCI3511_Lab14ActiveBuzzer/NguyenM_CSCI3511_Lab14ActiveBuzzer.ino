int buzzerpin = 4;
int ledpin = 5;

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzerpin, OUTPUT);
  pinMode(ledpin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  digitalWrite(buzzerpin, HIGH);
  digitalWrite(ledpin, HIGH);
  delay(1000);
  digitalWrite(buzzerpin, LOW);
  digitalWrite(ledpin, LOW);
  delay(1000);

  
}
