//car lights assigned
int cargreen = 10;
int caryellow = 9;
int carred = 8; 

//ped lights  assigned
int pedred = 12; 
int pedgreen = 11;

//button pin
int button = 2;
int bus_button = 3;

//Wait button
int white = 7;

//Blue button
int blue = 6;

enum traffic_light_status{
	GREEN, RED, YELLOW, RED_YELLOW
};

traffic_light_status status;

unsigned long time1 = 0;
unsigned long time2 = 0;

bool button_on = false;
bool button_driver = false;

int counter = 0;

void setup () {
	pinMode(carred, OUTPUT);
	pinMode(caryellow, OUTPUT);
	pinMode(cargreen, OUTPUT);
	pinMode(pedred, OUTPUT);
	pinMode(pedgreen, OUTPUT);
	pinMode(button, INPUT);
	pinMode(white, OUTPUT);
	Serial.begin(9600);
  	status = GREEN;
  
  	attachInterrupt(digitalPinToInterrupt(button), ped_press, HIGH);
  	attachInterrupt(digitalPinToInterrupt(bus_button), bus_press,RISING);
}

void loop(){
    switch (status){
    case YELLOW:
    	go_red();
    	break;
    case RED:
    	go_yellow_red();
    	break;
    case RED_YELLOW:
    	go_green();
    	break;
    case GREEN:
    	go_yellow();
    	break;
    default:
    	break;
  } 
}

void ped_press(){
  	if(status == RED_YELLOW || status == GREEN)
      	digitalWrite(white, HIGH);
  	if(status != GREEN)
     	button_on = true;
}

void bus_press(){
  	if(status == RED || status == YELLOW)
    	digitalWrite(blue, HIGH);
  	button_driver = true;
}
  	
void go_yellow(){
  	digitalWrite(cargreen, LOW);
  	digitalWrite(caryellow, HIGH);
  	digitalWrite(pedred, HIGH);
  	digitalWrite(pedgreen, LOW);
  	status = YELLOW;
  	delay(3000);
  	button_on = false;
  	digitalWrite(white, LOW);
}

void go_red(){
  	status = RED;
  	digitalWrite(caryellow, LOW);
    digitalWrite(carred, HIGH);
    digitalWrite(pedred, LOW);
    digitalWrite(pedgreen, HIGH);
	time1 = millis();
    time2 = millis();    
    unsigned long elapsed = 0;
    bool change = false;
    bool button_on = false;
    while(change == false){
        time2 = millis();
        elapsed = time2 - time1;
        if((button_driver == true) && (elapsed > 10000))
          	change = true;

        if((button_driver == false) && (elapsed > 20000))
            change = true;
    }
  	button_on = false;
  	button_driver = false;
  	digitalWrite(blue, LOW);
}

void go_yellow_red(){
  	digitalWrite(caryellow, HIGH);
    digitalWrite(pedred, HIGH);
    digitalWrite(pedgreen, LOW);
  	status = RED_YELLOW;
    delay(3000);
  	button_driver = false;
}

void go_green(){
  	digitalWrite(cargreen, HIGH);
  	digitalWrite(caryellow, LOW);
  	digitalWrite(carred, LOW);
    time1 = millis();
    time2 = millis();

    unsigned long elapsed = 0;
    bool change = false;

    while(change == false){
     	if (button_on == true)
    		digitalWrite(white, HIGH); 
        time2 = millis();
        elapsed = time2 - time1;
        
        if ((button_on == true) && (elapsed > 10000))
          	change = true; //delay 10 sec 

       	else if(button_driver == true &&( elapsed > 30000))
      		change = true; //delay 30 sec 
         
        else if (button_driver == false && elapsed > 20000 )
        	change = true; //delay 20 sec       
    }
  	button_driver = false;
  	status = GREEN;
}