// PWM: {3,5,6,9,10,11}
int redpin = 3;
int bluepin = 5;
int greenpin = 6;
int yellowpin = 9;

int brightnessValue[4] = {50, 100, 180, 230};
void setup() {

  // put your setup code here, to run once:
  pinMode(redpin, OUTPUT);
  pinMode(bluepin, OUTPUT);
  pinMode(greenpin, OUTPUT);
  pinMode(yellowpin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < 4; i++ ){
    analogWrite(redpin, brightnessValue[i]);
    delay(500);
  }
  analogWrite(redpin, 0);
  
  for (int i = 0; i < 4; i++ ){
    analogWrite(bluepin, brightnessValue[i]);
    delay(500);
  }
  analogWrite(bluepin, 0);

  for (int i = 0; i < 4; i++ ){
    analogWrite(greenpin, brightnessValue[i]);
    delay(500);
  }
  analogWrite(greenpin, 0);

  for (int i = 0; i < 4; i++ ){
    analogWrite(yellowpin, brightnessValue[i]);
    delay(500);
  }
  analogWrite(yellowpin, 0);
}
