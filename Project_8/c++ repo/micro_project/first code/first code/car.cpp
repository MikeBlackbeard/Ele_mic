#include "car.h"
#include<iostream>

car::car(string mak, int year, string colo): maker(mak),model(year),color(colo)

{
	cout << "the object life time starts " << "\n"; 
	cout << "this car is made at " << model << endl;
	cout << "this car is made by  " << maker << endl;
	cout << "this car is  " << color << endl;
}

car::~car()
{
	cout << "the object life time end " << "\n";

}
void car::setMaker(string m)
{
	maker = m; 
}


string car::getMaker()
{
	return maker; 
}

void car:: setModel(int mo){
	model = mo; 

}
int car:: getModel(){
	return model; 
}
void car::setColor(string co) {

	color = co; 
}

string car::getColor()
{
	return color;
}


