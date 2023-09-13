int ledpin = 9; //non PWM pin just blinks turns off and on. But PWM pin fades out the light/dims slowly when turning off.

void setup() {
  // put your setup code here, to run once:
  pinMode(ledpin, OUTPUT); // seems like it stays on longer if you remove this statement
}

void loop() {
  // put your main code here, to run repeatedly:
  for(int brightness = 255; brightness >= 0; brightness --){
    analogWrite(ledpin, 260);
    delay(30);
  }
  delay(1000);
}
