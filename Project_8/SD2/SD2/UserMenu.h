#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Resident.h"
#include "DS2HouseResidents.h"
#include <conio.h>

void userMenu(DS2HouseResidents* MyHouse) {
	bool run = true;
	char a;
	do {
		system("cls");
		cout << "      ***************************************" << endl;
		cout << "      ***            USER MENU            ***" << endl;
		cout << "      ***************************************" << endl << endl;
		cout << "            1. Create a new user." << endl;
		cout << "            2. Deleta a user." << endl;
		cout << "            3. Edit user." << endl;
		cout << "            4. View resident list." << endl;
		cout << "            5. Return to user menu." << endl;
		cout << "            Select an option. ";
		string menuOption;
		cin >> menuOption;
		cin.clear();
		if (menuOption.length() == 1) {
			switch (menuOption[0])
			{
			case '1':
				MyHouse->AddResident();
				break;
			case '2':
				MyHouse->DeleteResident();
				break;
			case '3':
				MyHouse->EditResident();
				break;
			case '4':
				MyHouse->ShowResidents();
				a = _getch();
				break;
			case '5':
				run = false;
				break;
			default:
				break;
			}
		}
	} while (run);
}


void doorAccess(DS2HouseResidents* MyHouse) {
	char fingerRead;
	char toContinue;
	bool runDoor = true;
	do {
		system("cls");
		cout << "Finger: a-z     -     Doorbell:  Espacebar        -       Atempt to open: Del.        -       Back: Esc" << std::endl
			<< "Select an action";
		char action = _getch();
		if ((action >= 'a' && action <= 'z') || (action >= 'A' && action <= 'Z')) {
			bool OpenDoor = false;
			int userAtempt = -1;
			userAtempt = MyHouse->FindResident(action);
			if (userAtempt != -1) {
				cout << "Please enter your PIN. ";
				string PAtempt;
				cin >> PAtempt;
				if (MyHouse->VerifyResidentPIN(userAtempt, PAtempt)) {
					bool OpenDoor = true;
					cout << "The door is open";
					toContinue = _getch();
				}
			}
		}
		else if (action == 27) 
			runDoor = false;
	} while (runDoor);
}