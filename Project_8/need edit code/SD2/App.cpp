#include "App.h"


void App::addRoom(string n)
{
}

void App::logRoom(string n)
{
	bool s;
	do {
		cout << "enter userName" << endl;
		cin >> n;
		if (n == userName)
		{
			cout << "user found";
			s = true;
		}
		else
			cout << "user not found,try again";
		s = false;
	} while (s == false);
}

void App::deleteRoom(string n)
{
}

void App::saveAllData()
{
}
