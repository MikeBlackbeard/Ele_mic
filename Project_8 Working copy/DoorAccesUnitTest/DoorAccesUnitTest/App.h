#pragma once
#include<string>
#include"Bulb.h"
#include"Room.h"
#include"Resident.h"
#include <iostream>
#include <vector>
#include <conio.h>
#include <fstream>

using namespace std;
class App:protected Resident // semicolon to inherit the protected and the public part of the resident class
{ 
	vector<Room> roomList; //we vector to have a dynamic array
public:
	App();
	void AddRoom();
	void EnterRoom();
	void deleteRoom();
	int FindRoomName(string nameAtepmt);
	void saveRoom(Room newRoom);
	void ShowRoom();
	void loadRoom(Room newRoom);
	void saveRoomDatabase();
};

