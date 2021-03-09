int carred = 10; //car lights assigned
int caryellow = 9;
int cargreen = 8;
int pedred = 12; //ped lights  assigned
int pedgreen = 11;
int button = 13; // button pin
int state = digitalRead(button);

void setup () {
pinMode(carred, OUTPUT);
pinMode(caryellow, OUTPUT);
pinMode(cargreen, OUTPUT);
pinMode(pedred, OUTPUT);
pinMode(pedgreen, OUTPUT);
pinMode(button, INPUT);

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
    delay(3000);
}


void go_red(){
    digitalWrite(caryellow, LOW);
    digitalWrite(carred, HIGH);
    digitalWrite(pedred, LOW);
    digitalWrite(pedgreen, HIGH);
  if (state==1 )
   delay(20000);
  else 
     delay(10000);
}



void go_yellow_red(){
  digitalWrite(caryellow, HIGH);
    digitalWrite(caryellow, HIGH);
    digitalWrite(pedred, HIGH);
    digitalWrite(pedgreen, LOW);
    delay(3000);
}

void go_green(){
    digitalWrite(caryellow, LOW);
    digitalWrite(carred, LOW);
    digitalWrite(cargreen, HIGH);
   if (state==1 )
   delay(10000);
  else 
     delay(20000);
    
}
