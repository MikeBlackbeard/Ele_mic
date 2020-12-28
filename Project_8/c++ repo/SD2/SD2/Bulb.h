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
	int BulbID; 
	bool BulbState; 

public: 
	
	void lightOn();
	void lightOff(); 
	void PrintState();
	string saveBulb(); 
	 

};

