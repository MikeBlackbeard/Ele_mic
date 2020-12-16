#pragma once
#include <iostream>
#include <vector>
#include <conio.h>
#include "Resident.h"

class DS2HouseResidents
{
private:
	std::vector<Resident> resident;
public:
	DS2HouseResidents();
	~DS2HouseResidents();
	void AddResident();
	void DeleteResident();
	void ShowResidents();
	void EditResident();
	int FindResident(char FingerRead);
	bool VerifyResidentPIN(int NResident, string enterPIN);
	bool VerifyResidentNFC(int NResident, std::string NFCAtempt);
};

