#pragma once
#include<string>
#include<iostream>
using namespace std; 
class Bulb
{
private : 
	string BulbID; 
	bool BulbState; 

public: 
	void addBulb(string n);
	void logBulb(string n);
	void deleteBulb(string n);
	void lightOn();
	void lightOff(); 
	void PrintState();
	string saveBulb(); 

};

