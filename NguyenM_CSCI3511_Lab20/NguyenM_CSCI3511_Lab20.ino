int temppin = A0;
int ledpin = 9;
int buzzerpin = 4;
int brightness;
int maxTemp = 80.0; // for fahrenheit

void setup() {
  // put your setup code here, to run once:
  Serial.begin(9600);
  pinMode(buzzerpin, OUTPUT);
  pinMode(ledpin, OUTPUT);
}

void loop() {
  // put your main code here, to run repeatedly:
  int reading = analogRead(temppin);
  double thermoresist = 10000.0 * ((1024.0 / reading - 1));
  double logofthermoresist = log(thermoresist);
  double tempK = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * logofthermoresist * logofthermoresist )) * logofthermoresist);
  float tempC = tempK - 273.15;
  float tempF = (tempC * 9.0) / 5.0 + 32.0;

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

  // map the brightness of the led to values picked up from thermometer
  //just do a range from 0 - 212 degrees fahrenheit since 212 = boiling point
  brightness = map(tempF, 70, 130, 0, 255); 
  analogWrite(ledpin, brightness);
  Serial.print("brightness: ");
  Serial.println(brightness);


  if (tempF >= maxTemp){
    //predefined max temp, sound the buzzer
    digitalWrite(buzzerpin, HIGH);
  } else {
    digitalWrite(buzzerpin, LOW);
  }

  delay(2000);

}
