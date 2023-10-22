#include "EEPROM.h";
#include <string.h>



int successfulAuthentication = 0;
int addressRegistrationFlag = 0; //address 0 stores the flag value, 0 = not registered, 1 for registered.

//password begins starting at address 1
int addressBeginOfPassword = 1;
int addressEndOfPassword = 6;


using namespace std;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  //place to do authentication
  //enter loop only when successful
  while (successfulAuthentication == 0){
    if (EEPROM.read(addressRegistrationFlag) != 1){
      EEPROM.write(addressRegistrationFlag, 0);
    }
    
    //case 1: new user
    if (EEPROM.read(addressRegistrationFlag) == 0){
      //ask user to enter password
      Serial.print("Enter the password you'd like to configure: ");
      String userInput = Serial.readStringUntil('\n');
      userInput.trim(); // remove leading and trailing spaces

      Serial.print("password is: ");
      Serial.println(userInput);





      /*
      //indexing through user input string
      for (auto &ch : strUserInput){

        //Print current char
        Serial.println(ch);
        

      */
      
      
      


      //EEPROM.write(addressRegistrationFlag, 1);
    }

      //case 2: registered user, compare password 
  }
   

     
}





void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("SUCCESSFUL AUTHENTICATION!");
}
