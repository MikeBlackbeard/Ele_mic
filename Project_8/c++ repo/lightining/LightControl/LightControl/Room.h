#pragma once
#include<string>
#include"Bulb.h"
using namespace std;
class Room
{
	private:
		string RoomID;
		Bulb Lamps[6];
		

	public:
		void addRoom(string n);
		void logRoom(string n);
		void deleteRoom(string n);
		void chooseBulb();
		void ChooseWindow();
		string saveRoom();
	


};

