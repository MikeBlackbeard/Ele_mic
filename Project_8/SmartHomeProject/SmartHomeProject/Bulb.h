#pragma once
#include<string>
#include<iostream>
#include<conio.h>
#include<fstream>
#include <algorithm>
#include"Resident.h"
#include"DS2HouseResidents.h"
using namespace std; 
class Bulb
{
private : 
	string BulbID; 
	bool BulbState; 

public: 
	void bulb();
	void bulb(string newBulb);
	bool lightOn();
	bool lightOff(); 

	bool PrintState();
	void EditBulbName();
	bool checkBulb(string nameAtept);
	string printBulb();

};

