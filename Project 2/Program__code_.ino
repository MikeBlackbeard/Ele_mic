int carRed = 7; //car lights assigned
int carYellow = 6;
int carGreen = 5;
int pedRed = 9; //ped lights  assigned
int pedGreen = 8;
int button = 2; // button pin
int crossTime = 5000; //time given to pedestrians before crossing
unsigned long changeTime ; // time collected since the button was last pressed

void setup () {
pinMode(carRed, OUTPUT);
pinMode(carYellow, OUTPUT);
pinMode(carGreen, OUTPUT);
pinMode(pedRed, OUTPUT);
pinMode(pedGreen, OUTPUT);
pinMode(button, INPUT);

digitalWrite(carGreen,HIGH); //start with green car light on
digitalWrite(pedRed, HIGH); //start with red ped light on
}

void loop(){
/* check if button is pressed
and it is over 5 sec since last button press

*/
int state = digitalRead(button);{
delay(1000);
changeLights(); //function to change lights
}
}

void changeLights() {
digitalWrite(carGreen,LOW); //green car light off
digitalWrite(carYellow,HIGH); // yellow car light on
delay(2000); //wait 2 seconds

digitalWrite(carYellow,LOW); // yellow car light off
digitalWrite(carRed,HIGH); //red car light on
delay(1000); //wait 1 second to turn on ped light

digitalWrite(pedRed,LOW); //red ped light off
digitalWrite(pedGreen,HIGH); //green ped light on. allow crossing
delay(crossTime); //delay preset time of 5 seconds
//flashing of ped green light
for (int x=0; x<10; x++){
digitalWrite(pedGreen,HIGH);
delay(250);
digitalWrite(pedGreen,LOW);
delay(250);
}

digitalWrite(pedRed, HIGH); //turn red ped light on
delay(100);

digitalWrite(carGreen,HIGH); //car green light on
digitalWrite(carRed,LOW); //car red light off

changeTime = millis(); //time recorded since last lights changes

}
