int bluepin = 6;
int greenpin = 5;
int redpin = 3;

int colorValue[3] = {300,300,300};

void setup() {
  // put your setup code here, to run once:
  pinMode(bluepin, OUTPUT); 
  pinMode(greenpin, OUTPUT); 
  pinMode(redpin, OUTPUT); 
}

void loop() {

  
  analogWrite(redpin, 0);
  analogWrite(bluepin, 10);
  delay(1000);
  analogWrite(bluepin, 300);
  delay(1000);
  analogWrite(bluepin, 0);

  analogWrite(greenpin, 50);
  delay(1000);
  analogWrite(greenpin, 300);
  delay(1000);
  analogWrite(greenpin, 0);

  delay(1000);
  analogWrite(redpin, 400);
  delay(1000);

  
  /*
  for (int i = 0; i < 3; i++){
    analogWrite(bluepin, colorValue[i]);
    delay(500);
    analogWrite(greenpin, colorValue[i]);
    delay(500);
    analogWrite(redpin, colorValue[i]);
    delay(500);
  }
  */
  
  
}

