#include "DS2HouseResidents.h"


DS2HouseResidents::DS2HouseResidents() {

}

DS2HouseResidents::~DS2HouseResidents() {

}

void DS2HouseResidents::AddResident() {
	Resident newresident;
	resident.push_back(newresident);
}

void DS2HouseResidents::ShowResidents() {
	for (int i = 0; i < resident.size(); i++) {
		std::cout << std::endl << "Resident " << i + 1 << " " << resident[i].printResident();
	}
}

void DS2HouseResidents::DeleteResident() {
	std::cout << "please enter the User Name of the user that you want to delete: ";
	std::string deleteuser;
	std::cin >> deleteuser;
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
			std::cout << "The user " << resident[usertodelete].printResident() << " will be deleted." <<
				"press Y to continue or press N to cancel. ";
			std::string deleteOption;
			std::cin >> deleteOption;
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

bool DS2HouseResidents::VerifyResidentPIN(int NResident, char enterPIN[6]) {
	if (resident[NResident].checkPIN(enterPIN))
		return true;
	return false;
}

bool DS2HouseResidents::VerifyResidentNFC(int NResident, std::string NFCAtempt) {
	if (resident[NResident].checkNFC(NFCAtempt))
		return true;
	return false;
}