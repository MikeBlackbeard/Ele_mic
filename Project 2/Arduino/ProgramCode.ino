//car lights assigned
int cargreen = 10;
int caryellow = 9;
int carred = 8; 

//ped lights  assigned
int pedred = 12; 
int pedgreen = 11;

//button pin
int button = 13; 

//Wait button
int white = 7;

//Orange button
int orange = 6;


unsigned long time1 = 0;
unsigned long time2 = 0;



void setup () {
	pinMode(carred, OUTPUT);
	pinMode(caryellow, OUTPUT);
	pinMode(cargreen, OUTPUT);
	pinMode(pedred, OUTPUT);
	pinMode(pedgreen, OUTPUT);
	pinMode(button, INPUT);
	pinMode(white, OUTPUT);
  	pinMode(orange, OUTPUT);
	Serial.begin(9600);
}

void loop() {
  changeLights();
  
 }

void changeLights(){
    go_yellow();
    go_red();
    go_yellow_red();
    go_green();
}

void go_yellow(){
  	digitalWrite(cargreen, LOW);
  	digitalWrite(caryellow, HIGH);
  	digitalWrite(pedred, HIGH);
  	digitalWrite(pedgreen, LOW);
  	delay(3000);
}

void go_red(){
  	digitalWrite(caryellow, LOW);
    digitalWrite(carred, HIGH);
    digitalWrite(pedred, LOW);
    digitalWrite(pedgreen, HIGH);
	unsigned long time1 = millis();
    unsigned long time2 = millis();
  
  	delay(8000);
    
    
    unsigned long elapsed = 0;
    bool change = false;
    bool button_on = false;
    while(change == false){
        time2 = millis();
        elapsed = time2 - time1;
        

        if (digitalRead(button) == HIGH){
            button_on = true;
            digitalWrite(orange, HIGH);        
        }
        
        if((button_on == true) && (elapsed > 15000))
          	change = true;

        if((button_on == false) && (elapsed > 10000))
            change = true;
    }
    digitalWrite(orange, LOW);
  button_on = false;
}


void go_yellow_red(){
  	digitalWrite(caryellow, HIGH);
    digitalWrite(pedred, HIGH);
    digitalWrite(pedgreen, LOW);
    delay(3000);
}

void go_green(){
  	digitalWrite(cargreen, HIGH);
  	digitalWrite(caryellow, LOW);
  	digitalWrite(carred, LOW);
    unsigned long time1 = millis();
    unsigned long time2 = millis();
    
    
    unsigned long elapsed = 0;
    bool change = false;
    bool button_on = false;
    while(change == false){
        time2 = millis();
        elapsed = time2 - time1;
        

        if (digitalRead(button) == HIGH){
            button_on = true;
            digitalWrite(white, HIGH);        
        }
        
        if((button_on == true) && (elapsed > 10000))
          	change = true;

        if(elapsed > 20000)
            change = true;
    }
    digitalWrite(white, LOW);
  button_on = false;
}
