#pragma once
#include<iostream>
#include<conio.h>


class Resident
{
private:
	char fingerprint;
	std::string NFC;
	char PIN[6];
	std::string password;
	std::string userName;

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

	bool checkPassword(std::string passAtempt);
	bool checkPIN(char PINAtempt[6]);
	bool checkNFC(std::string NFCAtempt);
	bool checkFingerPrint(char fingerAtempt);

	std::string printResident();
};

