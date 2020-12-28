#include "App.h"

void App::NewUser(string n, string p)
{
	cout << "enter username" << endl;
	cin >> n; 
	cout << "choose a strong password min: 8 digits , one lower,upper case and Number" << endl;
	cin >> p; 
	//confirm strong code
	cout << "user created " << endl;
}

void App::log(string n, string p)
{
	bool s;
	do {
		cout << "enter userName" << endl;
		cin >> n;
		if (n == UserName)
		{
			cout << "user found";
			s = true;
		}
		else
			cout << "user not found,try again";
		s = false;
	} while (s == false);
}

void App::modifyUser(string n,string p)
{
	UserName = n; 
	Password = p; 
}

void App::deleteUser(string n)
{
}

void App::Room()
{
}

string App::saveUser()
{
	return string();
}
