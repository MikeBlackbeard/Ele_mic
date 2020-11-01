//Traffic lights assigned
int cargreen = 10;
int caryellow = 9;
int carred = 8; 

//pedesterian lights  assigned
int pedred = 12; 
int pedgreen = 11;

//buttons pin ped &bus assigned 
int buttonped = 2; 
int buttonbus= 3 ; 

//white light to check if pedbutton is pressed
int white = 7;

//Orange Light to check if bus driver button is pressed 
int orange = 6;

//parameters to count the time in phases
unsigned long time1 = 0; //at initial point 
unsigned long time2 = 0;//the current time 
enum traffic_light_status
{
  GREEN, RED, YELLOW, RED_YELLOW
} ;   // enumeration to assign phases 

traffic_light_status  status; //assign status 


void setup () {
  
  pinMode(carred, OUTPUT); //traffic lights o/p
  pinMode(caryellow, OUTPUT);
  pinMode(cargreen, OUTPUT);
  
  pinMode(pedred, OUTPUT);// pedestarian lights o/p
  pinMode(pedgreen, OUTPUT);
  
  pinMode(buttonped, INPUT); // bus & ped button i/p 
    pinMode(buttonbus, INPUT);
    status = GREEN; //start at green phase to go yellow
}

void loop() {
  
  switch (status){
    
      case YELLOW: //traffic yellow phase 
               go_red();            break; //go red fun
    
       case RED: //trafic red phaase  
                 go_yellow_red();     break; //go yellow red
    
       case RED_YELLOW: //traffic red yellow phase 
    
               go_green();          break; //go green phase 
    
    case GREEN :    
               go_yellow();         break; //go yellow phase
   
  } 
  
 }



void go_yellow(){
   
  //turn on yellow traffic light and ped red for 3 sec 
  
    digitalWrite(cargreen, LOW); //traffic green off
    digitalWrite(caryellow, HIGH);//traffic yellow on 
  
    digitalWrite(pedred, HIGH);//ped red on 
    digitalWrite(pedgreen, LOW);// ped green off 
    delay(3000);// 3 sec delay 
    status = YELLOW; //go yellow case
}

void go_red(){
  
  //turn on traffic red && ped green 
  
    digitalWrite(carred, HIGH);//traffic red on 
    digitalWrite(caryellow, LOW);//traffic yellow off 
    
    digitalWrite(pedred, LOW);//ped red off 
    digitalWrite(pedgreen, HIGH); //ped green on
   

     time1 = millis(); //count initial time
     time2 = millis();  //count current time   
    
    unsigned long elapsed = 0; //count the difference 
    bool change = false; //change state parameter 
    bool button_on = false; //check button state parameter 
  
    while(change == false){
      
        time2 = millis();
        elapsed = time2 - time1;
        
        

        if (digitalRead(buttonbus) == HIGH)
        {
            button_on = true;
            digitalWrite(orange, HIGH);//turn on orange light        
        }
        
        if((button_on == true) && (elapsed > 10000))
            change = true; //delay 10 sec only 

        if((button_on == false) && (elapsed > 20000))
            change = true; //delay 20 sec 
    } 
  
    digitalWrite(orange, LOW); //turn off orange light 
    button_on = false; 
    	status = RED; //go red  case 

}

void  go_yellow_red()
{
  
    digitalWrite(caryellow, HIGH); //traffic yellow on 
  
    digitalWrite(pedred, HIGH); //ped red on 
    digitalWrite (pedgreen,LOW) ; //ped green light off
   delay (3000) ; //3 sec delay   
  status = RED_YELLOW; //go red yellow case  
  
}

void go_green(){
  
    digitalWrite(cargreen, HIGH); //traffic green on 
    digitalWrite(caryellow, LOW); //traffic yellow off 
    digitalWrite(carred, LOW); //traffic red off 

    
    
    unsigned long elapsed = 0;
    bool change = false;
    bool button_on = false; //ped button state 
    bool var =false ; 
    bool buttonbus_on = false; //busdriver button state 
  
    while(change == false)
    {
      
        time2 = millis();
        elapsed = time2 - time1;
   

        if (digitalRead(buttonped) == HIGH){
          //check if ped button on 
            button_on = true;
            digitalWrite(white, HIGH);        
        }
      
      if (digitalRead(buttonbus) == HIGH){
           //check if bus driver button on 
            buttonbus_on = true;
            digitalWrite(orange, HIGH);        
        }
        
    
        if ((button_on == true) && (elapsed > 10000))
            change = true; //delay 10 sec 

       else if  ((buttonbus_on) == true &&( elapsed > 30000))
       
          change = true; //delay 30 sec 
         
         else if ((buttonbus_on) == false && elapsed > 20000 )
                   
         change = true; //delay 20 sec 
         
         } 
  
    
      digitalWrite(white, LOW); //turn off white light 
      digitalWrite(orange, LOW); //turn off orange light 
  button_on = false;
   status = GREEN; //go green case 
}  

 