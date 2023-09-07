int ledpin = 7;
int incomingByte = 0;
int offset = 0;
int delayTimes[5] = {450, 300, 225, 150, 50};



void setup() {
  // put your setup code here, to run once:
  pinMode(ledpin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available() > 0){
    //read the incoming byte
    incomingByte = Serial.read();

    //print out what you got, debug purposes
    //Serial.print("I received: ");
    //Serial.println(incomingByte, DEC);

  }

  //default blink frequency
  digitalWrite(ledpin, HIGH);  // turn the LED on (HIGH is the voltage level)
  delay(delayTimes[offset]);                      // wait for a second
  digitalWrite(ledpin, LOW);   // turn the LED off by making the voltage LOW
  delay(delayTimes[offset]);                      // wait for a second


  if (incomingByte == '+'){
    if(offset < 4){
      offset++; //increment the offset only when it is less than 4/max freq
    }
  
    if(offset == 4){
      Serial.print("This is the max frequency. Level 4 Frequency. \n");
      

      digitalWrite(ledpin, HIGH);  // turn the LED on (HIGH is the voltage level)
      delay(delayTimes[offset]);                      // wait for a second
      digitalWrite(ledpin, LOW);   // turn the LED off by making the voltage LOW
      delay(delayTimes[offset]);                      // wait for a second
    }
    else if (offset == 3){
      Serial.print("Level 3 Frequency. \n");

      digitalWrite(ledpin, HIGH);  // turn the LED on (HIGH is the voltage level)
      delay(delayTimes[offset]);                      // wait for a second
      digitalWrite(ledpin, LOW);   // turn the LED off by making the voltage LOW
      delay(delayTimes[offset]);                      // wait for a second
    }
    else if (offset == 2){
      Serial.print("Level 2 Frequency. \n");

      digitalWrite(ledpin, HIGH);  // turn the LED on (HIGH is the voltage level)
      delay(delayTimes[offset]);                      // wait for a second
      digitalWrite(ledpin, LOW);   // turn the LED off by making the voltage LOW
      delay(delayTimes[offset]);                      // wait for a second
    }
    else if (offset == 1){
      Serial.print("Level 1 Frequency. \n");

      digitalWrite(ledpin, HIGH);  // turn the LED on (HIGH is the voltage level)
      delay(delayTimes[offset]);                      // wait for a second
      digitalWrite(ledpin, LOW);   // turn the LED off by making the voltage LOW
      delay(delayTimes[offset]);                      // wait for a second
    }
    else if (offset == 0){
      Serial.print("This is the lowest frequency. Level 0. \n ");

      digitalWrite(ledpin, HIGH);  // turn the LED on (HIGH is the voltage level)
      delay(delayTimes[offset]);                      // wait for a second
      digitalWrite(ledpin, LOW);   // turn the LED off by making the voltage LOW
      delay(delayTimes[offset]);                      // wait for a second
      
    }
  }
  else if (incomingByte == '-'){
    if (offset > 0){
      //as long as offset is greater than zero you can decrement it
      offset--;
    }

    if(offset == 4){
      Serial.print("This is the max frequency. Level 4 Frequency. \n");

      digitalWrite(ledpin, HIGH);  // turn the LED on (HIGH is the voltage level)
      delay(delayTimes[offset]);                      // wait for a second
      digitalWrite(ledpin, LOW);   // turn the LED off by making the voltage LOW
      delay(delayTimes[offset]);                      // wait for a second
    }
    else if (offset == 3){
      Serial.print("Level 3 Frequency. \n");

      digitalWrite(ledpin, HIGH);  // turn the LED on (HIGH is the voltage level)
      delay(delayTimes[offset]);                      // wait for a second
      digitalWrite(ledpin, LOW);   // turn the LED off by making the voltage LOW
      delay(delayTimes[offset]);                      // wait for a second
    }
    else if (offset == 2){
      Serial.print("Level 2 Frequency. \n");

      digitalWrite(ledpin, HIGH);  // turn the LED on (HIGH is the voltage level)
      delay(delayTimes[offset]);                      // wait for a second
      digitalWrite(ledpin, LOW);   // turn the LED off by making the voltage LOW
      delay(delayTimes[offset]);                      // wait for a second
    }
    else if (offset == 1){
      Serial.print("Level 1 Frequency. \n");

      digitalWrite(ledpin, HIGH);  // turn the LED on (HIGH is the voltage level)
      delay(delayTimes[offset]);                      // wait for a second
      digitalWrite(ledpin, LOW);   // turn the LED off by making the voltage LOW
      delay(delayTimes[offset]);                      // wait for a second
    }
    else if (offset == 0){
      Serial.print("This is the lowest frequency. Level 0. \n");

      digitalWrite(ledpin, HIGH);  // turn the LED on (HIGH is the voltage level)
      delay(delayTimes[offset]);                      // wait for a second
      digitalWrite(ledpin, LOW);   // turn the LED off by making the voltage LOW
      delay(delayTimes[offset]);                      // wait for a second
      
    }
  }
}
