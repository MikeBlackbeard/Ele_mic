#pragma once
#include<string>
#include"Bulb.h"
#include"Room.h"
#include"Resident.h"
using namespace std;
class App:protected Resident 
{


public:
	
	void addRoom(string n);
	void logRoom(string n);
	void deleteRoom(string n);
	void saveAllData(); 

	
	

};

