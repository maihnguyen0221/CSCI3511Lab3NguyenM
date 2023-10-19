#include "pitches.h"
int redpin = 10;
int bluepin = 9;
int greenpin = 5;
int yellowpin = 3;
int potpin = A5;


int buzzerpin = 8;
//notes in melody
int Freq[] = { NOTE_C4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_F4,
NOTE_E4, NOTE_C4, NOTE_C4, NOTE_D4, NOTE_C4, NOTE_G4,
NOTE_F4, NOTE_C4, NOTE_C4, NOTE_C5, NOTE_A4, NOTE_F4,
NOTE_E4, NOTE_D4, NOTE_AS4, NOTE_AS4, NOTE_A4, NOTE_F4,
NOTE_G4, NOTE_F4 };
int sizeOfFreq = sizeof(Freq)/sizeof(int);
int duration = 500;
int delayVal;

void setup() {
  // put your setup code here, to run once:
  pinMode(buzzerpin, OUTPUT);
  pinMode(redpin, OUTPUT);
  pinMode(bluepin, OUTPUT);
  pinMode(greenpin, OUTPUT);
  pinMode(yellowpin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  for (int i = 0; i < sizeOfFreq; i++){
    int potvalue = analogRead(potpin);
    delayVal = map(potvalue, 0, 1023, 50, 5000);

    if (Freq[i] == NOTE_C4 || Freq[i] == NOTE_E4){
      analogWrite(yellowpin, 255);
      tone(buzzerpin, Freq[i], duration);
      analogWrite(yellowpin, 0);

    }
    else if (Freq[i] == NOTE_F4 || Freq[i] == NOTE_D4){
      analogWrite(greenpin, 255);
      tone(buzzerpin, Freq[i], duration);
      analogWrite(greenpin, 0);
    }
    else if (Freq[i] == NOTE_G4 || Freq[i] == NOTE_A4){
      analogWrite(bluepin, 255);
      tone(buzzerpin, Freq[i], duration);
      analogWrite(bluepin, 0);
    }
    else if (Freq[i] == NOTE_AS4 || Freq[i] == NOTE_C5){
      analogWrite(redpin, 255);
      tone(buzzerpin, Freq[i], duration);
      analogWrite(redpin, 0);
    }


    delay(delayVal);
  }
  delay(400);
}
