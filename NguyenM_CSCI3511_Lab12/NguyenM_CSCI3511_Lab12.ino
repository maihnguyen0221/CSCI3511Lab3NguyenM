#include "EEPROM.h";
#include <string.h>



int successfulAuthentication = 0;
int addressRegistrationFlag = 0; //address 0 stores the flag value, 0 = not registered, 1 for registered.

//password begins starting at address 1
int addressBeginOfPassword = 1;
int addressEndOfPassword = 6;

int correctPassword = 0; // 0 if false, 1 if true
int charMatch = 1;

int lengthOfStoredPassword = 1;



using namespace std;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);

  EEPROM.write(addressRegistrationFlag, 0); //reset flag for complete restart with no users

  //place to do authentication
  //enter loop only when successful
  while (successfulAuthentication == 0){
    if (EEPROM.read(addressRegistrationFlag) != 1){
      EEPROM.write(addressRegistrationFlag, 0);
    }
    
    //case 1: new user
    if (EEPROM.read(addressRegistrationFlag) == 0){
      //ask user to enter password
      Serial.println("");
      Serial.print("Enter the password you'd like to configure up to 6 numbers: ");
      while (!Serial.available()){
        //wait for user input
      }

      //read input
      String userInput = Serial.readStringUntil('\n');
      userInput.trim();
      //Serial.print("password is: ");
      //Serial.println(userInput);
  
      //taking userInput and storing the password into the address values
      int startAddress = addressBeginOfPassword;
      for (auto &ch : userInput){
        //Print current char
        //convert character into integer value
        int intPassChar = int(ch) - 48; // typecast numeric character value into an actual integer value
        //Serial.print("Integer equivalent: "); //debug purposes
        //Serial.println(intPassChar);
        EEPROM.write(startAddress, intPassChar);

        /* debugging
        int value = EEPROM.read(startAddress);
        Serial.print("The value at address ");
        Serial.print(startAddress);
        Serial.print(" is: ");
        Serial.println(value);
        */
        lengthOfStoredPassword++;
        startAddress++; 
      
      }
      
      EEPROM.write(addressRegistrationFlag, 1);
    }

    //case 2: registered user, compare password 
    if (EEPROM.read(addressRegistrationFlag) == 1){
      //ask user to enter password
      Serial.println("\nWelcome!");

      while(correctPassword == 0){
        Serial.print("Enter your password: ");

        while (!Serial.available()){
          //wait for user input
        }

        //read input
        String userInput = Serial.readStringUntil('\n');
        userInput.trim();

        Serial.print("\nThe password you entered is: ");
        Serial.println(userInput);
    
        //taking userInput and compare it to stored passwords
        int startAddress = addressBeginOfPassword;
        String strStoredPassword = ""; //empty string

        for (int i = addressBeginOfPassword; i < (lengthOfStoredPassword) ; i++){
          int charValue = EEPROM.read(i);
          strStoredPassword += String(charValue);
        }
        //Serial.print("stored password: "); //debug
        //Serial.println(strStoredPassword);

        if ( (userInput.equals(strStoredPassword)) && (userInput.length() == strStoredPassword.length()) ){
          correctPassword = 1; //exit the while loop for asking password
        }
        else {
          Serial.println("Password not found. Please try again.");
        }
        
      }
      
      

    }
    successfulAuthentication = 1; // done


    
  }
   

     
}





void loop() {
  // put your main code here, to run repeatedly:
  Serial.print("SUCCESSFUL AUTHENTICATION!");
  delay(20000);
}
