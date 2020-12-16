#pragma once
#include<iostream>
#include<conio.h>
#include <algorithm>

using namespace std;

class Resident
{
private:
	char fingerprint;
	string NFC;
	string PIN;
	string password;
	string userName;

public:
	Resident();
	~Resident();
	void changePassword();
	void changePIN();
	void changeNFC();

	void createPassword();
	void createUserName();
	void createPIN();
	void createNFC();
	void createFingerPrint();

	bool checkPassword(string passAtempt);
	bool checkPIN(string PINAtempt);
	bool checkNFC(string NFCAtempt);
	bool checkFingerPrint(char fingerAtempt);

	string printResident();
};

