int temppin = A0;
int enablepin = 5;
int dirpin1 = 4;
int dirpin2 = 3;
int txpin = 12; //trigger pin
int rxpin = 11;  //echo pin

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(enablepin, OUTPUT);
  pinMode(dirpin1, OUTPUT);
  pinMode(dirpin2, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int reading = analogRead(temppin);
  //first number is the resistor 10k, if you change resistor you must change the number
  double thermoresist = 10000.0 * ((1024.0 / reading - 1));
  double logofthermoresist = log(thermoresist);
  double tempK = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * logofthermoresist * logofthermoresist )) * logofthermoresist);
  float tempC = tempK - 273.15;
  float tempF = (tempC * 9.0) / 5.0 + 32.0;

  //motor will rotate in forward direction
  digitalWrite(dirpin1, LOW);
  digitalWrite(dirpin2, HIGH);

  Serial.print("Temp K: ");
  Serial.print(tempK);
  Serial.print('\t');
  Serial.print("Temp C: ");
  Serial.print(tempC);
  Serial.print('\t');
  Serial.print("Temp F: ");
  Serial.print(tempF);
  Serial.print('\t');
  Serial.print("\n");

  delay(2000);

}
`