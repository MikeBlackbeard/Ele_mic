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
		std::cout << "      ***************************************" << std::endl;
		std::cout << "      ***            USER MENU            ***" << std::endl;
		std::cout << "      ***************************************" << std::endl << std::endl;
		std::cout << "            1. Create a new user." << std::endl;
		std::cout << "            2. Deleta a user." << std::endl;
		std::cout << "            3. Edit user." << std::endl;
		std::cout << "            4. View resident list." << std::endl;
		std::cout << "            5. Return to user menu." << std::endl;
		std::cout << "            Select an option. ";
		std::string menuOption;
		std::cin >> menuOption;
		std::cin.clear();
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
		std::cout << "Finger: a-z     -     Doorbell:  Espacebar        -       Atempt to open: Del.        -       Back: Esc" << std::endl
			<< "Select an action";
		char a = _getch();

		switch (a)
		{
		case 27:
			runDoor = false;
			break;
		default:
			break;
		}
		/*
		int fingerUser = MyHouse->FindResident(fingerRead);
		if (fingerUser != -1) {
			std::cout << "1 To use PIN code" << std::endl
				<< "2 to use NFC" << std::endl
				<< "3 to generate a new random code" << std::endl
				<< "select an option: ";
			std::string enterOption;
			std::cin >> enterOption;
			std::cin.clear();
			if (enterOption.size() == 1) {
				std::cout << "Enter your PIN code: ";
				char enterPIN[6];
				std::cin >> enterPIN;
				if (MyHouse->VerifyResidentPIN(fingerUser, enterPIN)) {
					std::cout << "Door open." << std::endl <<
						"press any key to continue. ";
					toContinue = _getch();
				}
				else {
					std::cout << "Incorrect PIN, door stays closed. ";
					toContinue = _getch();
				}
			}
		}*/
	} while (runDoor);
}