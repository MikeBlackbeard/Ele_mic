#include "Room.h"

void Room::addRoom(string n)
{
	cout << "choose room ID" << endl;
	cin >> n;
	RoomID = n;
	cout << "room " << n << "created " << endl; 
}

void Room::logRoom(string n)
{
		bool s;
		do {
			cout << "enter Room ID" << endl;
			cin >> n;
			if (n == RoomID)
			{
				cout << "Room " << n << "is accessed";
				s = true;
			}
			else
				cout << "Room not found";
			s = false;
		} while (s == false);
	}


void Room::deleteRoom(string n)
{
}

void Room::chooseBulb()
{

}

void Room::ChooseWindow()
{
}

string Room::saveRoom()
{
	return string();
}
