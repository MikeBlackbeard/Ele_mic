#include "Bulb.h"

void Bulb::addBulb(string n)
{
	BulbID = n;
	cout << "new bulb" << BulbID << " created " << endl;
}

void Bulb::logBulb(string n)

{
	bool s; 
	do {
		cout << "enter bulb ID" << endl;
		cin >> n;
		if (n == BulbID)
		{
			cout << "bulb " << n << "is accessed";
		s= true;
		}
		else
			cout << "bulb not found";
		s= false;
	} while (s==false); 
}

void Bulb::deleteBulb(string n)
{

}

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
	string 
	return string();
}
