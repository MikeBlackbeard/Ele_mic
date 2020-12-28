#pragma once
#include<iostream>
#include<conio.h>
#include<fstream>
#include <algorithm>

using namespace std;

class Resident
{
private:
	char fingerprint;
	string NFC;
	string PIN;
protected :

	string password;
	string userName;

public:
	Resident();
	~Resident();
	void changePassword();
	void changePIN();
	void changeNFC();
	void addResident(string newUserName);

	void createPassword();
	void createUserName();
	void createPIN();
	void createNFC();
	void createFingerPrint();

	bool checkPassword(string passAtempt);
	bool checkPIN(string PINAtempt);
	bool checkNFC(string NFCAtempt);
	bool checkFingerPrint(char fingerAtempt);
	bool checkName(string nameAtept);

	string printResident();

	void loadResident(char load_fingerPring, string load_NFC, string load_PIN, string load_password, string load_username);
	string saveResident();
};

