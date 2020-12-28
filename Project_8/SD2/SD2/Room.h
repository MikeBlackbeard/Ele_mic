#pragma once
#include<string>
#include"Bulb.h"
using namespace std;
class Room
{
	private:
		string RoomID;
		Bulb lamps[6];
		int counter; 
		

	public:
		Room();
		void addBulb(string n);
		void selectBulb();
		void deleteBulb(string n);

		string saveRoom();

		//window part
		/*void addWindow(string n);
		void deleteBulb(string n);
		void selectWindow();*/
		

};

