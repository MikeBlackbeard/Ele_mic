#include "DS2HouseResidents.h"


DS2HouseResidents::DS2HouseResidents() {

}

DS2HouseResidents::~DS2HouseResidents() {

}

void DS2HouseResidents::AddResident() {
	string userName;
	std::cout << "Enter your User Name: ";
	std::cin >> userName;
	bool free = true;
	for (int i = 0; i < resident.size(); i++)
		if (resident[i].checkName(userName)) {
			free = false;
			break;
		}
	if(free){
		Resident newresident;
		newresident.addResident(userName);
		resident.push_back(newresident);
		saveDatabase();	
	}
	else {
		cout << "User name already exists. ";
		char toContinue = _getch();
	}
}

void DS2HouseResidents::ShowResidents() {
	for (int i = 0; i < resident.size(); i++) {
		std::cout << std::endl << "Resident " << i + 1 << " " << resident[i].printResident();
	}
}

void DS2HouseResidents::DeleteResident() {
	cout << "please enter the User Name of the user that you want to delete: ";
	string deleteuser;
	cin >> deleteuser;
	int usertodelete = -1;
	for (int i = 0; i < resident.size(); i++) {
		if (deleteuser == resident[i].printResident()) {
			usertodelete = i;
			break;
		}
	}
	if (usertodelete != -1) {
		bool rundelete = true;
		char toContinue;
		do {
			cout << "The user " << resident[usertodelete].printResident() << " will be deleted." <<
				"press Y to continue or press N to cancel. ";
			string deleteOption;
			cin >> deleteOption;
			if (deleteOption.size() == 1) {
				switch (deleteOption[0])
				{
				case 'y':
				case 'Y':
					resident.erase(resident.begin() + usertodelete);
					std::cout << "The user " << deleteuser << " has been deleted. " << std::endl <<
						"Press any key to continue. ";
					toContinue = _getch();
					rundelete = false;
					break;
				case 'n':
				case 'N':
					std::cout << "Action cancelled." << std::endl << "Press any key to continue. ";
					toContinue = _getch();
					rundelete = false;
					break;
				default:
					break;
				}
			}
		} while (rundelete);
	}
	else {
		std::cout << "The User Name is incorrect. \n Press any key to continue. ";
		char a = _getch();
	}
	saveDatabase();
}

void DS2HouseResidents::EditResident() {
	std::cout << "please enter the User Name of the user that you want to edit: ";
	std::string edituser;
	std::cin >> edituser;
	int usertoedit = -1;
	for (int i = 0; i < resident.size(); i++) {
		if (edituser == resident[i].printResident()) {
			usertoedit = i;
			break;
		}
	}
	if (usertoedit != -1) {
		bool runEdit = true;
		char toContinue;
		do {
			std::cout << "1. Change password." << std::endl
				<< "2. Change PIN code" << std::endl
				<< "3. Change NFC" << std::endl
				<< "4. Add new finger print " << std::endl
				<< "5. Return to User Menu" << std::endl
				<< "Select an option. ";
			std::string editOpt;
			std::cin >> editOpt;
			if (editOpt.size() == 1) {
				switch (editOpt[0])
				{
				case '1':
					resident[usertoedit].changePassword();
					break;
				case '2':
					resident[usertoedit].changePIN();
					break;
				case '3':
					resident[usertoedit].changeNFC();
					break;
				case '4':
					resident[usertoedit].createFingerPrint();
					break;
				case '5':
					runEdit = false;
				default:
					break;
				}
			}
		} while (runEdit);
	}
	else {
		std::cout << "The User Name is incorrect. \n Press any key to continue. ";
		char a = _getch();
	}
}

int DS2HouseResidents::FindResident(char FingerRead) {
	for (int i = 0; i < resident.size(); i++) {
		if (resident[i].checkFingerPrint(FingerRead))
			return i;
	}
	return -1;
}

bool DS2HouseResidents::VerifyResidentPIN(int NResident, string enterPIN) {
	if (resident[NResident].checkPIN(enterPIN))
		return true;
	return false;
}

bool DS2HouseResidents::VerifyResidentNFC(int NResident, std::string NFCAtempt) {
	if (resident[NResident].checkNFC(NFCAtempt))
		return true;
	return false;
}

void DS2HouseResidents::loadResident(Resident newResident) {
	resident.push_back(newResident);
}

void DS2HouseResidents::saveDatabase() {
	ofstream save_file("Database.txt", ios::out);
	for (int i = 0; i < resident.size(); i++)
		save_file << resident[i].saveResident() << endl;
}