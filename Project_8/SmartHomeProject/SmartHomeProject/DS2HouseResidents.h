#pragma once
#include <iostream>
#include <vector>
#include <conio.h>
#include <fstream>
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
	int FindResidentName(string nameAtepmt);
	bool VerifyResidentPIN(int NResident, string enterPIN);
	bool VerifyResidentNFC(int NResident, std::string NFCAtempt);
	void loadResident(Resident newResident);
	void saveDatabase();
};

