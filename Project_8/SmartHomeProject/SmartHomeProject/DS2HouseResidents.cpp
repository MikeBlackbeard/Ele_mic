#include "DS2HouseResidents.h"


DS2HouseResidents::DS2HouseResidents() {

}

DS2HouseResidents::~DS2HouseResidents() {

}

void DS2HouseResidents::AddResident() {
	string userName;
	std::cout << "Enter your User Name: ";
	std::cin >> userName;  //we read a user name
	bool free = true;
	for (int i = 0; i < resident.size(); i++)
		if (resident[i].checkName(userName)) { //if the name already exists we enter this if
			free = false; //we set free to false to say that the name is already used
			break; //we break the for to save resources
		}
	if(free){ //if free is still free we can create a new user we the name that we read
		Resident newresident; //here we create a new resident
		newresident.addResident(userName); //here we initialize the resident
		resident.push_back(newresident); //push_back adds the new resident to the end of the vector 
		saveDatabase();	//do not refer to this, is only to save the new data
	}
	else {
		cout << "User name already exists. ";
		char toContinue = _getch();
	}
}

void DS2HouseResidents::ShowResidents() {  //we use this function to be able to see the residents that we already have in the system
	for (int i = 0; i < resident.size(); i++) {
		std::cout << std::endl << "Resident " << i + 1 << " " << resident[i].printResident();
	}
}

void DS2HouseResidents::DeleteResident() {
	cout << "please enter the User Name of the user that you want to delete: ";
	string deleteuser;
	cin >> deleteuser; //we read a user name
	int usertodelete = -1;
	usertodelete = FindResidentName(deleteuser);  //if the name exists we get a number different to -1
	if (usertodelete != -1) {  //we enter this function if the user name exists
		bool rundelete = true;
		char toContinue;
		do {
			cout << "The user " << resident[usertodelete].printResident() << " will be deleted." <<
				"press Y to continue or press N to cancel. ";
			string deleteOption; //we read the option to confirm to delete
			cin >> deleteOption;
			if (deleteOption.size() == 1) { //we only continue if the option is one character long
				switch (deleteOption[0])
				{
				case 'y':
				case 'Y': //if the option is yes we delete the user
					resident.erase(resident.begin() + usertodelete);
					std::cout << "The user " << deleteuser << " has been deleted. " << std::endl <<
						"Press any key to continue. ";
					toContinue = _getch();
					rundelete = false; //in this case we exit the loop
					break;
				case 'n':
				case 'N': //if the option is no we abort
					std::cout << "Action cancelled." << std::endl << "Press any key to continue. ";
					toContinue = _getch();
					rundelete = false; //in this case we also exit the loop
					break;
				default:
					break;
				}
			}
		} while (rundelete); //we only stay in the loop if the delete option is not Yer or No
	}
	else {
		std::cout << "The User Name is incorrect. \n Press any key to continue. ";
		char a = _getch();
	}
	saveDatabase();
}


//this function needs to be updated
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


//the next functions search into the list of residents to return a position where they are or -1 if they are not found
int DS2HouseResidents::FindResident(char FingerRead) {
	for (int i = 0; i < resident.size(); i++) {
		if (resident[i].checkFingerPrint(FingerRead))
			return i;
	}
	return -1;
}

int DS2HouseResidents::FindResidentName(string nameAtepmt) {
	for (int i = 0; i < resident.size(); i++) {
		if (resident[i].checkName(nameAtepmt))
			return i;
	}
	return -1;
}

bool DS2HouseResidents::VerifyPassword(int NResident, string passwordAtempt)
{
		if (resident[NResident].checkPassword(passwordAtempt))
			return true;
		return false;
	}
	

//The bool function retunr true is the correct or false if is not they will call a function into resident to return the value
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