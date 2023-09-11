
int maxNum = 99999;
int menuOption = 0;
int theOperator = 0;
int leftOperand = 0;
int rightOperand = 0;


void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  Serial.println("Calculator Program ");
  Serial.println("\n 1. Addition (+)");
  Serial.println("\n 2. Subtraction (-)");
  Serial.println("\n 3. Multiplication (*)");
  Serial.println("\n 4. Division (/)");
}

void loop() {
  Serial.println("\n Enter the operation you would like to complete: "); 
  while (Serial.available() == 0){
  }

  menuOption = Serial.parseInt();

  switch (menuOption) {
    case 1:
      Serial.print("You have chosen Addition");
      Serial.print("\nEnter in the left operand: ");
      Serial.flush();
      
      leftOperand = Serial.parseInt();
      

      Serial.print(leftOperand);
      break;
    case 2:
      Serial.print("You have chosen Subtraction");
      break;
    case 3:
      Serial.print("You have chosen Multiplication");
      break;
    case 4:
      Serial.print("You have chosen Division");
      break;
  }

  

  

  
}
