#pragma once
#include<string>
#include<iostream>
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

