#include "SR04.h"
int enablepin = 5;
int dirpin1 = 4;
int dirpin2 = 3;
int txpin = 12; //trigger pin
int rxpin = 11;  //echo pin
int brakeLEDpin = 6; //pin for red brake signal LED

SR04 sr04 = SR04(rxpin, txpin);
int distance;

void setup() {
  // put your setup code here, to run once:
  pinMode(enablepin, OUTPUT);
  pinMode(dirpin1, OUTPUT);
  pinMode(dirpin2, OUTPUT);
  pinMode(txpin, OUTPUT);
  pinMode(rxpin, INPUT);
  pinMode(brakeLEDpin, OUTPUT);
  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  distance = sr04.Distance();
  Serial.print(distance);
  Serial.println(" cm");
  //delay(1000);

  if (distance < 10){
    analogWrite(enablepin, 0); //stop the motor
    digitalWrite(brakeLEDpin, HIGH); // turn on the brake signal LED
  } else{
    analogWrite(enablepin, 255); //set motor speed to maximum
    digitalWrite(brakeLEDpin, LOW); //turn off the brake signal LED
  }


  //motor will rotate in forward direction
  digitalWrite(dirpin1, LOW);
  digitalWrite(dirpin2, HIGH);

  //backward direction
  //digitalWrite(dirpin1, HIGH);
  //digitalWrite(dirpin2, LOW);

  //delay(1000);

}
