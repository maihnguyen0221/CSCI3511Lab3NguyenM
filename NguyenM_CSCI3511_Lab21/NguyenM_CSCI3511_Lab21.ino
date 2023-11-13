#include "SimpleDHT.h"

int DHTpin = 7;
SimpleDHT11 dht11;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {
  // put your main code here, to run repeatedly:
  byte temp = 0;
  byte humidity = 0;
  byte rawdata[40] = {0};

  if (dht11.read(DHTpin, &temp, &humidity, rawdata)){
    Serial.print("Read DHT11 failed");
    return;
  }
  Serial.print((int)temp);
  Serial.print("C, ");
  Serial.print((int)humidity);
  Serial.println("%");

  delay(500);
}
