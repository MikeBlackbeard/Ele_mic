#pragma once
#include<string>
#include"Bulb.h"
#include"Room.h"
#include"Resident.h"
using namespace std;
class App:protected Resident 
{
	string roomname; 
	Room ro; 

public:
	
	void addRoom(string n);
	void logRoom(string n);
	void deleteRoom(string n);
	string saveAllData();

};

