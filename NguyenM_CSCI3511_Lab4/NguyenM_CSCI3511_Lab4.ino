float maxNum = 999999;

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Calculator Program");
  Serial.println("Enter an expression (e.g., 1 + 1):");
}

void loop() {

  if(Serial.available() > 0){
    //read the input from the serial monitor until it reaches a newline char
    String userInput = Serial.readStringUntil('\n');
    userInput.trim(); // remove leading and trailing spaces


    //split the input into two operands and a operator
    int indexOfSpace = userInput.indexOf(' ');

    if(indexOfSpace != -1 && userInput.length() > indexOfSpace + 1){

      //create substrings of the operands and operator
      String strLeftOperand = userInput.substring(0, indexOfSpace);
      String strOperator = userInput.substring(indexOfSpace + 1, indexOfSpace + 2);
      String strRightOperand = userInput.substring(indexOfSpace + 3);


      //convert substrings to float
      float floatLeftOperand = strLeftOperand.toFloat();
      float floatRightOperand = strRightOperand.toFloat();

      float result;

      if (strOperator == "+"){
        result = floatLeftOperand + floatRightOperand;


      }
      else if (strOperator == "-"){
        result = floatLeftOperand - floatRightOperand;
      }
      else if (strOperator == "/"){
        //just in case they try to divide by 0
        if(floatRightOperand == 0){
          Serial.println("Error: Division by zero.");
          return;
        }
        else{
          result = floatLeftOperand / floatRightOperand;
        }
        

      }
      else if (strOperator == "*"){
        result = floatLeftOperand * floatRightOperand;
      }
      else { //final error checking for wrong operator
        Serial.println("Invalid operator. Please use one of the following: +, -, *, or /.");
        return;
      }

      //Print the result

      if (result > maxNum){
        Serial.print("Error. Overflow, your result was larger than: ");
        Serial.print(maxNum);
      }
      else{
        Serial.print("Result: ");
        Serial.println(result);
      }

    }
    else{ 
      Serial.println("Invalid input format. Please enter an expression like '1 + 1' with appropriate spaces.");

    }

    Serial.println("Enter another expression:");
  }

  
}
