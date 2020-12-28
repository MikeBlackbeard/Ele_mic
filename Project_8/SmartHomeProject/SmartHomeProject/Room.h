#pragma once
#include<string>
#include"Bulb.h"
#include<algorithm>
using namespace std;
class Room
{
	private:
		string RoomID;
		string BulbID;
		Bulb lamp;
		int counter; 
		

	public:
		Room();
		void addBulb();
		void accessBulb();
		void deleteBulb();

		string saveRoom();

		//window part
		/*void addWindow(string n);
		void deleteBulb(string n);
		void selectWindow();*/
		

};

