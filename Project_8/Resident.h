#pragma once
#include<iostream>
#include<string>

class Resident
{
private:
	char fingerPrint;		//finger print
	int uniqueCode[4];			//Personal pin code
	int uniqueNFC;			//Personal NFC chip
	std::string password;	//app password
	std::string uniqueUser;	//app user
public:
	Resident();				//Create a Resident user
	~Resident();			//Distroy a Resident user
	void addFingerPrint();
	void changeUniqueCode();
	void changeNFCCode();
	void deactivateSystem();
    void createPassword();
    //set new password and check password strength
	void changePassword();
	void createUserName();
	void alowVisitor();
	bool checkpassword();
	bool checkNFCCode();
	bool checkFingerPrint();
};

