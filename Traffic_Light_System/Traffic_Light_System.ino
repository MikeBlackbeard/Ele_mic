void setup()
{
  /*Microcontroller course in the department of Electronics Engineering 
   *At Hochshule Hamm-Lippstadt University of Applied Sciences. 
   Professor Stefan Henkler.
    */
      
  pinMode(12,OUTPUT);
  pinMode(8,OUTPUT);
  pinMode(4,OUTPUT);
}

void loop()
{
  digitalWrite(12, HIGH);//This PIN on Arduino Board is used for STOP mode(Red LED)
  digitalWrite(8, LOW);
  digitalWrite(4, LOW);
  delay(2000); // Wait for 2000 millisecond(s)
  
  digitalWrite(12, LOW);
  digitalWrite(8, HIGH);//This PIN on Arduino Board is used for READY mode(Yellow LED)
  digitalWrite(4, LOW);
  delay(2000); // Wait for 2000 millisecond(s)
  
  digitalWrite(12, LOW);
  digitalWrite(8, LOW);
  digitalWrite(4, HIGH);//This PIN on Arduino Board is used for GO mode(Green LED)
  delay(2500); // Wait for 2000 millisecond(s)
}
