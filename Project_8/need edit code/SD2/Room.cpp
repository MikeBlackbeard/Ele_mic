#include "Room.h"
#include"Bulb.h"

Room::Room()
{
	RoomID = "unkown"; 
	counter = 0; 

}

string Room::saveRoom()
{
	string toSave;
	toSave = RoomID;
	return toSave;
}


void Room::addBulb(string n)
{
	bool enough=1;
	do{
		if (counter < 7)
		{
			string lightName;
			cout << "enter a bulb name " << endl;
			cin >> lightName;
			counter++;
			cout << "new bulb" << lightName << " created " << endl;
		}
		else
			cout << "you are not able to add new Bulb ,please delete a Bulb" << endl;
		    enough = 0;

	} while (!enough);
	
}

void Room::selectBulb()
{
	int n; 
	cout << "selcet which bulb you want to access" << endl; 
	cin >> n; 
	for (i=0; i<; i++)
	{


	
	}

}



void Room::deleteBulb(string n)
{
	cout << "please enter the bulbID you want to delete: ";
	string deletebulb;
	cin >> deletebulb;
	cout << "Bulb" << deletebulb << "is deleted" << endl;
}


