/* This is the program for the streetLight as created by 

Obigwe Vincent Chinedu
Micro-Processor HSHL */

int green = 7;
int yellow = 12;
int red = 9;

void setup()
{
  // put your setup code here, to run once:
  pinMode(green, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(red, OUTPUT);

  digitalWrite(green, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(red, LOW);

  Serial.begin(9600);
}

void loop()
{
  // put your main code here, to run repeatedly:

  //Caution Mode

  digitalWrite(green, LOW);
  digitalWrite(yellow, HIGH);
  digitalWrite(red, LOW);

  Serial.println(" Light Mode : Yield ");
  delay(1000);

  //GO Mode

  digitalWrite(green, HIGH);
  digitalWrite(yellow, LOW);
  digitalWrite(red, LOW);

  Serial.println(" Light Mode : GO ");
  delay(5000);

  //Caution Mode

  digitalWrite(green, LOW);
  digitalWrite(yellow, HIGH);
  digitalWrite(red, LOW);

  Serial.println(" Light Mode : Yield ");
  delay(1000);

  //STOP Mode

  digitalWrite(green, LOW);
  digitalWrite(yellow, LOW);
  digitalWrite(red, HIGH);

  Serial.println(" Light Mode : STOP ");
  delay(3000);
}