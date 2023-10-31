int redpin = 13;
int yellowpin = 12;
int bluepin = 9;
int greenpin = 11;


int VRxPin = A1;
int VRyPin = A0;
int SWpin = 7;
int currentLitLED; 
bool isBlinking = false;
bool buttonState;
bool lastButtonState = HIGH; //stores previous state of button

bool firstLoop = true;


void setup() {
  // put your setup code here, to run once:
  pinMode(redpin, OUTPUT);
  pinMode(yellowpin, OUTPUT);
  pinMode(bluepin, OUTPUT);
  pinMode(greenpin, OUTPUT);
  pinMode(SWpin, INPUT_PULLUP);

  Serial.begin(9600);


}

void loop() {
  // put your main code here, to run repeatedly:

  buttonState = digitalRead(SWpin);
  if (buttonState == LOW && lastButtonState == HIGH){
    //button is pressed
    isBlinking = !isBlinking; //toggle blinking
  }

  lastButtonState = buttonState; //save current button state for next loop
  //by default turn on the top left for first loop only
  if (firstLoop){
    digitalWrite(yellowpin, HIGH);
    digitalWrite(redpin, LOW);
    digitalWrite(bluepin, LOW);
    digitalWrite(greenpin, LOW);
    currentLitLED = yellowpin;
    firstLoop = false;

  }

  if (isBlinking){
    digitalWrite(currentLitLED, HIGH);
    delay(100);
    digitalWrite(currentLitLED, LOW);
    delay(100);
    buttonState = digitalRead(SWpin);
    if (buttonState == LOW && lastButtonState == LOW){
    //button is pressed again
      isBlinking = !isBlinking; //turn off blinking
    
    }
  } else { //not blinking anymore
    //relight the LED 
    digitalWrite(currentLitLED, HIGH);
  }

  int VRxVal = analogRead(VRxPin);
  int VryVal = analogRead(VRyPin);

  int xVal = map(VRxVal, 0, 1023, -255, 255);
  int yVal = map(VryVal, 0, 1023, -255, 255);

  //Serial.print("X val: ");
  //Serial.println(xVal);
  //Serial.print("Y val: ");
  //Serial.println(yVal);
  //Serial.println();



  if (xVal == -255 && yVal == 255){
    //bottom left
    digitalWrite(yellowpin, LOW);
    digitalWrite(redpin, LOW);
    digitalWrite(bluepin, HIGH);
    digitalWrite(greenpin, LOW);
    currentLitLED = bluepin;

  }
  else if (xVal == 255 && yVal == 255){
    //bottom right
    digitalWrite(yellowpin, LOW);
    digitalWrite(redpin, LOW);
    digitalWrite(bluepin, LOW);
    digitalWrite(greenpin, HIGH);
    currentLitLED = greenpin;
  }
  else if (xVal == 255 && yVal == -255 ){
    // top right
    digitalWrite(yellowpin, LOW);
    digitalWrite(redpin, HIGH);
    digitalWrite(bluepin, LOW);
    digitalWrite(greenpin, LOW);
    currentLitLED = redpin;

  }
  else if (xVal == -255 && yVal == -255){
    //top left
    digitalWrite(yellowpin, HIGH);
    digitalWrite(redpin, LOW);
    digitalWrite(bluepin, LOW);
    digitalWrite(greenpin, LOW);
    currentLitLED = yellowpin;

  }


}
