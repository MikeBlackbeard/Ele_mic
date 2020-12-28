#pragma once
#include<string>
using namespace std; 
class car
{

private :
	string maker; 
	int model; 
	string color; 

public : 
	void setMaker(string m);
	string getMaker(); 
	void setModel(int mo);
	int getModel(); 
	void setColor(string co);
	string getColor(); 
	car(string mak, int year , string colo);
	~car(); 

};

