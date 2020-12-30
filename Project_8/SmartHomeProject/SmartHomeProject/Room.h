#pragma once
#include<string>
#include"Bulb.h"
#include<algorithm>
using namespace std;
class Room
{
	private:
		string RoomID;
		vector<Bulb> Lamps;
		

	public:
		Room();
		bool checkRoom(string nameAtept);
		void room(string newRoom); 
		string printRoom();
		string saveRoom();

		void addBulb();
		void accessBulb();
		void deleteBulb();
		int FindBulbName(string nameAtepmt);
//Amit 
		/* Window fun
		void addBulb();
		void accessBulb();
		void deleteBulb();*/


		//window part
		/*void addWindow(string n);
		void deleteBulb(string n);
		void selectWindow();*/
		

};

