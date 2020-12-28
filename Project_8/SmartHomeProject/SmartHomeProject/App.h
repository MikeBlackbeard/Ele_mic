#pragma once
#include<string>
#include"Bulb.h"
#include"Room.h"
#include"Resident.h"
#include<vector>
using namespace std;
class App:protected Resident // semicolon to inherit the protected and the public part of the resident class
{
	string roomname; 
	vector<Room> roomList; //we vector to have a dynamic array
public:
	App();
	void addRoom(string n);
	void logRoom(string n);
	void deleteRoom(string n);
	string saveAllData();
};

