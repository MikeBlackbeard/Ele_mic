#include "Bulb.h"


void Bulb::lightOn()
{
	BulbState = 1; 
}

void Bulb::lightOff()
{
	BulbState = 0; 
}

void Bulb::PrintState()
{
	cout << "current state is " << BulbState << endl; 
}

string Bulb::saveBulb()
{
	string toSave;
	toSave = BulbID;
	return toSave;

}
