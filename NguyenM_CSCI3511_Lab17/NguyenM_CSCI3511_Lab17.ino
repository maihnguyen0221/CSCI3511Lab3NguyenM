#include "SR04.h"
int txpin = 12;
int rxpin = 11;

SR04 sr04 = SR04(rxpin, txpin);
int distance;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(txpin, OUTPUT);
  pinMode(rxpin, INPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  distance = sr04.Distance();
  Serial.print(distance);
  Serial.println(" cm");
  delay(1000);
}
