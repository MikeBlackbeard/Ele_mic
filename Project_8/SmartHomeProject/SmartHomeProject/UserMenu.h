#pragma once

//Here we include all the headers that are required in the main file
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

//we include the standard library
using namespace std; 

//in this function we load the information stored the last time that we used the system (not save required since is done automatically)
//do to refer to this function
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


//we use this function if the user want to change any information.
void editUser(DS2HouseResidents* MyHouse) {
	bool run = true;
	//char a;
	do {
		system("cls");
		cout << "      ***************************************" << endl;
		cout << "      ***            EDIT MENU            ***" << endl;
		cout << "      ***************************************" << endl << endl;
		cout << "            1. Chage password." << endl;
		cout << "            2. Chage PIN." << endl;
		cout << "            3. Change NFC." << endl;
		cout << "            5. Return to user menu." << endl;
		cout << "            Select an option. ";
	} while (run);
}


//in the user menu we can create edit or remove residents to the SmartHome system
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


//Here we simulate the door behavior
void doorAccess(DS2HouseResidents* MyHouse) {
	char toContinue;  //this is just to avoid some warnings XD
	bool runDoor = true;  //we run the menu until runDoor is false
	do {
		system("cls");  //clear the screen
		cout << "Finger: a-z     -     Doorbell:  Espacebar        -       Atempt to open: Del.        -       Back: Esc" << std::endl
			<< "Select an action";
		char action = _getch();  //we store any key that the user press
		if ((action >= 'a' && action <= 'z') || (action >= 'A' && action <= 'Z')) {  //we check that the key is a letter
			bool OpenDoor = false;													 //remember that we represent a fingerprint as a letter
			int userAtempt = -1;  // -1 is defined as user not found
			userAtempt = MyHouse->FindResident(action);  //with this function we check in the list of residents if the fingerprint recognized.
			if (userAtempt != -1) {  //if the user was found in the last function we continue, otherwise we exit.
				cout << "\nPlease enter your PIN. ";
				string PAtempt;  //to store the PIN that the user tried to open the door
				cin >> PAtempt;
				if (MyHouse->VerifyResidentPIN(userAtempt, PAtempt)) {  //this function retunrs true if the PIN is correct, flase if is not.
					bool OpenDoor = true;  //if is correct we ope the door
					cout << "The door is open";
					toContinue = _getch();
				} //if the PIN is not correct we just ignore and re-run menu
			} //if the user is = -1 means that was not found and we re -un door
		} //if the key pressed is not a letter we go the the else if
		else if (action == 27) //27 represents the ESC key (remember that this runs in PC sorry for the ones that run macOS :P)
			runDoor = false; //we stop running the dor
	} while (runDoor);
}

//this function needs to be checked by Marwa
void AppAccess(DS2HouseResidents* MyHouse, App* appData)
{
	//App* appData; // I think this should be in the main function and we should send the appData via pointer
	string userAtempt, passwordAtempt; //try to use name of varibles that are clear for all of use,
	//bool oku, okp, run;				   //try to avoid to use only one letter because then we can get confused
	//do {   //chek this do, I dont find a way to exit I commented it because I think is not required
		cout << "please enter you user name" << endl;
		cin >> userAtempt;
		int getUser = -1;
		//check find user in DS2HouseResidents.cpp
		getUser = MyHouse->FindResidentName(userAtempt);
		//then use an if to continue, if you find the resident you ask the password
		if (getUser != -1) //remember that -1 is not found
		{
			cout << "plese enter your password";
			cin >> passwordAtempt;
			//use a function similar to VerifyResidentPIN
			if (MyHouse->VerifyResidentPIN(getUser, passwordAtempt)) //change the function I put it only to example
			{ // I move the room menu here
				bool ok = true;
				do {
					system("cls");
					cout << "      ***************************************" << endl;
					cout << "      ***            ROOM MENU            ***" << endl;
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
						case '1': //to this part refer to the add resident function in line 74
							cout << "enter room name" << endl; //do not read the name here, you will lose the data
							cin >> roomname;
							appData->addRoom(roomname);
							break;
						case '2':
							cout << "enter room name" << endl; //same, make a full function where you will ask a name, also in that function you can print all the rooms that we already have
							cin >> roomname;
							appData->logRoom(roomname);
							break;

						case '3':
							cout << "enter room name" << endl; //refer to the delete resident in line 78
							cin >> roomname;
							appData->deleteRoom(roomname);
							break;
						case '4':
							ok = false;
							break;

						default:
							break;
						}
					}
				} while (ok);
			} //end if that check password you can use an else to say that the password is incorrect
		} //end if that check the name of the user, you can add an else to say that the user doesn't exist
	//} while (!run); end of the while that I commented
};
