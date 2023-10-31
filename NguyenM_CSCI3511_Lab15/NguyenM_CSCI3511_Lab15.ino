#include <LiquidCrystal.h>

LiquidCrystal lcd(7, 8, 9, 10, 11, 12);

byte smiley[8] = {
  B00000,
  B10001,
  B00000,
  B00000,
  B10001,
  B01110,
  B00000,
};

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  lcd.begin(16, 2);
  lcd.setCursor(0, 0);
  lcd.createChar(0, smiley);

}

void loop() {
  // put your main code here, to run repeatedly:
  if (Serial.available()){
    delay(100);
    lcd.clear();
    
    while (Serial.available() > 0){
      char inputchar = Serial.read();
      if(inputchar != '\n'){
        lcd.print(inputchar);
      }
    }
    lcd.blink();
    
    delay(2000);

    lcd.scrollDisplayRight();
    lcd.write(byte(0));

    

    
  
  }

}
