#pragma once
#include <iostream>
#include <string>
#include <vector>
#include "Resident.h"
#include "DS2HouseResidents.h"
#include"App.h"
#include <conio.h>
#include <fstream>
#include"Resident.h"
#include"DS2HouseResidents.h"
using namespace std; 


void LoadUsers(DS2HouseResidents* MyHouse) {
	Resident newResident;
	char load_fingerPring;
	string load_NFC;
	string load_PIN;
	string load_password;
	string load_username;
	ifstream load_file("Database.txt");
	while (load_file >> load_fingerPring >> load_NFC >> load_PIN >> load_password >> load_username) {
		newResident.loadResident(load_fingerPring, load_NFC, load_PIN, load_password, load_username);
		MyHouse->loadResident(newResident);
	}
}



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
				cout << "\nPlease enter your PIN. ";
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
void AppAccess(Resident* r)
{
	App use; 
	string n, p;
	bool oku, okp, run;
	do {
		cout << "please enter userName" << endl;
		cin >> n;
		oku = r->checkName(n);
		cout << "please enter password" << endl;
		cin >> p;
		okp = r->checkPassword(p);
		if (oku == 1 && okp == 1)
		{
			bool ok = true;

			do {
				system("cls");
				cout << "      ***************************************" << endl;
				cout << "      ***            Room MENU            ***" << endl;
				cout << "      ***************************************" << endl << endl;
				cout << "            1. Create a new room." << endl;
				cout << "            2. Access a room." << endl;
				cout << "            3. Delete a room" << endl;
				cout << "            4. back " << endl;
				cout << "            Select an option. ";
				string menuOption;
			    cin >> menuOption;
				string roomname;
				cin.clear();
				if (menuOption.length() == 1) {
				switch (menuOption[0])
					{
					case '1':
				
						cout << "enter room name" << endl;
						cin >> roomname; 
						use.addRoom(roomname); 
						break;
					case '2':
			
						cout << "enter room name" << endl;
						cin >> roomname;
						use.logRoom(roomname);
						break;
	
					case '3':
						cout << "enter room name" << endl;
						cin >> roomname;
						use.deleteRoom(roomname); 
						break;
				
					case '4':
						ok = false;
						break;

					default:
						break;
					}
				}
			} while (ok);
			run = 1;
		}
		else run=0;
	} while (!run);

};
