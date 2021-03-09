int red = 10;
int yellow = 9;
int green = 8;


void setup() {
  pinMode(red, OUTPUT);
  pinMode(yellow, OUTPUT);
  pinMode(green, OUTPUT);

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


// turn off red and yellow, then turn on green for 5 seconds
void go_green(){
  	digitalWrite(yellow, LOW);
    digitalWrite(red, LOW);
    digitalWrite(green, HIGH);
    delay(5000);
}


// turn off yellow, then turn red on for 5 seconds
void go_red(){
  	digitalWrite(yellow, LOW);
    digitalWrite(red, HIGH);
    delay(5000);
}


// green off, yellow on for 3 seconds
void go_yellow(){
  	digitalWrite(green, LOW);
    digitalWrite(yellow, HIGH);
    delay(3000);
}


// red and yellow on for 3 seconds (red is already on though)
void go_yellow_red(){
	digitalWrite(yellow, HIGH);
    delay(3000);
}
