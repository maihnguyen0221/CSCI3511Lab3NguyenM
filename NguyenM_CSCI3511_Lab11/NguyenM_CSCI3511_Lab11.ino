#include "EEPROM.h"

int value = 0;
int newVal = 0;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

}

void loop() {

  //reset value inside these addresses as something random
  /*
  newVal = 154;
  for (int address = 10; address < 21; address++){
    EEPROM.write(address, newVal);
    newVal++;
  }
  */

  
  // put your main code here, to run repeatedly:
  int EEPROMsize = EEPROM.length();
  Serial.print("The size of the EEPROM is: ");
  Serial.println(EEPROMsize);
  delay (5000);


  for (int address = 10; address < 21; address++){

    value = EEPROM.read(address);
    Serial.print("The value at address ");
    Serial.print(address);
    Serial.print(" is: ");
    Serial.println(value);
    delay(2000);
  }

  newVal = 0;

  for (int address = 10; address < 21; address++){
    EEPROM.write(address, newVal);
    value = EEPROM.read(address);
    Serial.print("The value at address ");
    Serial.print(address);
    Serial.print(" is: ");
    Serial.println(value);

    newVal++; // for next iteration increments newVal up to 10;
    delay(2000);
    
  }
 
  //pt 4 change val at address 0 to 256
  //When you set the value at the address to 256, it takes the modulo of value % 256 because 256 is the maximum value for addresses
  //there is overflow so the actual value you get when the number is 256 and above is the modulo and that is what gets written into
  //the address. 256 % 256 = 0, 257 % 256 = 1, 258 % 256 = 2, .... etc.
  EEPROM.write(0, 256);
  value = EEPROM.read(0);
  Serial.print("The value at address 0 is: ");
  Serial.println(value);
  delay(2000);

  EEPROM.write(0, 257);
  value = EEPROM.read(0);
  Serial.print("The value at address 0 is: ");
  Serial.println(value);
  delay(2000);

  EEPROM.write(0, 258);
  value = EEPROM.read(0);
  Serial.print("The value at address 0 is: ");
  Serial.println(value);
  delay(2000);
  
}
