//code library 
#include <IRremote.h>    
#include <LiquidCrystal.h> 

//Intiliaze LCD 
LiquidCrystal lcd(7,8,9,10,11,12);//LCD connencted Pin 

//intiliaze IR 

const int RECV_PIN=14; //PWM (Pulse Width Modulation) Pin A0
IRrecv irrecv(RECV_PIN);
decode_results results;

//Rooms Bulb Pins 
#define BedRoom1    2
#define BedRoom2    3  
#define Kitchen     4
#define Hall        5
#define DiningRoom  6
int leds[10]; 

void setup()
{
  
 
  Serial.begin(9600); //serial monitor 
  irrecv.enableIRIn(); // IR reciever begin 
  irrecv.blink13(true); //recieve an I/P (default led )
  lcd.begin(16, 2); //LCD 16*2 rows &Coloums 
  lcd.print ("Hello!Room No?"); 
  
  //led as O/P 
  pinMode(BedRoom1, OUTPUT);
  pinMode(BedRoom2, OUTPUT);
  pinMode(Kitchen, OUTPUT);
  pinMode(Hall, OUTPUT);
  pinMode(DiningRoom, OUTPUT);
  
}


  void Toggle(int LedNo){

  if (leds[LedNo]) {
    
    lcd.print(" off");

    Serial.println(" turned off");
    
    digitalWrite(LedNo, LOW);
    leds[LedNo] = 0;
  } 
  else {
    
 
    lcd.print("on");
    
    Serial.println(" turned on");
    
    digitalWrite(LedNo, HIGH);
    leds[LedNo] = 1;
  }
}



void loop() 
{
   if (irrecv.decode(&results)) {
       switch(results.value)
        {
    
         case 16582903: //button 1
         
        lcd.clear();
        lcd.print("BedRoom1  ");
        Toggle(2);          
        break; 
        
  
          
        case 16615543:   //button 2

         lcd.clear();
        lcd.print("BedRoom2  ");
         Toggle(3); 

      
      
        break;        
          
        case 16599223:  //button 3
         
         lcd.clear();
        lcd.print("Kitchen  ");
         Toggle(4); 
   
        break;  
     
      case 16591063: //button 4

         lcd.clear();
         lcd.print("Hall  ");
           Toggle(5); 
     
        break;  
     
      case 16623703: //button 5

        lcd.clear();
        lcd.print("DiningRoom  ");
        Toggle(6);
        break; 
         
          case 16607383: //button 6

        lcd.clear();
        lcd.print("create room  ");
       
        break;
         
          case 16586983: //button 7

        lcd.clear();
        lcd.print("create room  ");
       
        break;
         
         case 16619623: //button 8

        lcd.clear();
        lcd.print("create room  ");
       
        break;
         
        
      case 16603303:   //button 9

         lcd.clear();
        lcd.print("all open  ");
         
        //button 9 all on 
     
     digitalWrite(BedRoom1, HIGH);
     digitalWrite(BedRoom2, HIGH);
     digitalWrite(Kitchen, HIGH);
     digitalWrite(Hall, HIGH);
     digitalWrite(DiningRoom, HIGH);
     lcd.clear();
     Serial.print(" all on");
     lcd.print("ALL Lights oN");
   
     break;  
     
      case 16593103:  //button 0 all off 
     
     digitalWrite(BedRoom1, LOW);
     digitalWrite(BedRoom2, LOW);
     digitalWrite(Kitchen, LOW);
     digitalWrite(Hall, LOW);
     digitalWrite(DiningRoom, LOW);
     lcd.clear();
     Serial.print(" all off");
     lcd.print("ALL Lights off");
    
     break;  
      
     default: Serial.println(results.value); 
    
      }  
    irrecv.resume(); // Receive the next value
}  
} 

    