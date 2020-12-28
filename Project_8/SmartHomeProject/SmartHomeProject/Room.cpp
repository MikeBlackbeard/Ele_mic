#include "Room.h"
#include"Bulb.h"

Room::Room()
{
	RoomID = "unkown"; 
	counter = 0; 
	Bulb bulbs[6];

}

string Room::saveRoom()
{
	string toSave;
	toSave = RoomID;
	return toSave;
}


void Room::addBulb()
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

void Room::accessBulb()
{ 
	bool s;
	do {
		string bname;
		cout << "enter bulb name you want to access" << endl;
		cin >> bname;
		if (bname == BulbID)

		{
		cout << "you are now at lamp " << bname << endl;
		cout << "choose 1- light On , 2- light Off , 3-showState 4-delete bulb " << endl;
		int ch;
		cin >> ch;
		switch (ch)
		{
		case ('1'):

			lamp.lightOff(); s = true; break;
		case ('2'):
			 lamp.lightOn(); s = true;  break;
		case ('3'):
			 lamp.PrintState(); s = true;  break;
		case ('4'):
			deleteBulb(); s = true;  break;
		default:
			s == false; break;
		}

		}
		else
			cout << "bulb not found ,try again";
		s = false;
	} while (s == false);

			
	
}



void Room::deleteBulb()
{
	cout << "please enter the bulbID you want to delete: ";
	string deletebulb;
	cin >> deletebulb;
	deletebulb = "  "; 
	cout << "Bulb" << deletebulb << "is deleted" << endl;
}


