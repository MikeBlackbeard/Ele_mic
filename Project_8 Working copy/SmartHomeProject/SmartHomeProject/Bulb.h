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
protected : 
	string BulbID; 
	bool BulbState; 

public: 
	Bulb();
	void bulb(string newBulb);
	void lightOn();
	void lightOff(); 

	void PrintState();
	void EditBulbName();
	bool checkBulb(string nameAtept);
	string printBulb();
	void loadBulb( string load_BulbID, bool load_BulbState);


};

