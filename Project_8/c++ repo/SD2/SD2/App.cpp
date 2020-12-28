#include "App.h"


void App::addRoom(string n)
{
	n = roomname; 
}

void App::logRoom(string n)
{
	bool s;
	do {
		
		if (n == roomname)
		{
			int ch;
			cout << "you are in room " << n << endl;
			cout << "choose 1-add bulb , 2-access bulb 3-delete Bulb" << endl;
			cin >> ch;
			switch (ch)
			{
			case ('1'): 

				ro.addBulb(); s = true; break;
			case ('2'):
				ro.accessBulb(); s = true;  break;
			case ('3'):
				ro.deleteBulb(); s = true;  break;
			default:
				s == false; break; 
			}	

		}
		else
			cout << "no room found ,try again";
		s = false;
	} while (s == false);
}

void App::deleteRoom(string n)
{
	bool s;
	do {
		bool y; 
		if (n == roomname)
		{
			cout << "you are in room " << n <<"enter 1 to delete room  "<< endl;
			cin >> y;
			if (y==1)
			{
				roomname = "  "; 
				cout << "the room is deleted" << endl; 
			}
			else 
			s = false;
		}
		else
			cout << "no room found ,try again";
		s = false;
	} while (s == false);
}

string App::saveAllData()
{
		string toSave;
		toSave = roomname;
		return toSave;
	}


