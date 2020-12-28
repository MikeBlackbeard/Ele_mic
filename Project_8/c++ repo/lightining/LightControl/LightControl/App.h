#pragma once
#include<string>
#include"Bulb.h"
#include"Room.h"
#include"Resident.h"
using namespace std;
class App
{

private:
	string UserName;
	string Password; 


public:
	void NewUser(string n, string p);
	void log(string n, string p);
	void modifyUser(string n,string p);
	void deleteUser(string n);
	void Room();
	string saveUser();
	

};

