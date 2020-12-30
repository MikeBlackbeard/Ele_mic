#include "Bulb.h"



void Bulb::bulb()
{
	BulbState = 0; 
	BulbID = "unkown"; 
}

void Bulb::bulb(string newBulb)
{
	BulbID = newBulb;

}

void Bulb::lightOn()
{
	BulbState = 1; 
	cout << "bulb is on " << endl; 
}

void Bulb::lightOff()
{
	BulbState = 0; 
	cout << "bulb is off " << endl;
}

void Bulb::PrintState()
{
	cout << "current state is " << BulbState << endl; 
}

void Bulb::EditBulbName()
{

	cout << "enter new name" << endl; 
	cin >> BulbID; 


}


bool Bulb::checkBulb(string nameAtempt)
{
	if (nameAtempt == BulbID)
		return true;
	else
		return false;
}

string Bulb::printBulb()
{
	return BulbID;
}


