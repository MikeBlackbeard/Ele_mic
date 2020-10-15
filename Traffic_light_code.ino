#include <EEPROM.h>

void setup()
{
  pinMode(4, OUTPUT);//Green
  pinMode(3, OUTPUT);//yellow
  pinMode(2, OUTPUT); //red
  

  
}

void loop()
{
  digitalWrite (2,HIGH); //on red
    delay (4000); //4sec 
  digitalWrite (2,LOW);//off red
  
  
  digitalWrite (3,HIGH); //on yello
    delay (2000);  //2 sec
  digitalWrite (3,LOW);//off yellow
  
  digitalWrite (4,HIGH); // on green
    delay (4000); //4sec 
  digitalWrite (4,LOW);//off green
   
}
