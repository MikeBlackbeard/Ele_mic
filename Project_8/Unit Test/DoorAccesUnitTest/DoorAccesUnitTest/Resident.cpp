#include "Resident.h"

Resident::Resident() {
	fingerprint = ' ';
}

Resident::~Resident() {
	
}

void Resident::addResident(string newUserName) { //we use newUserName to initialize because in a function before we check that
	userName = newUserName;						 //the user still doesn't exist
	createPassword();
	createPIN();
	createNFC();
	createFingerPrint();
}

void Resident::createUserName() {
	std::cout << "Enter your User Name: ";
	std::cin >> userName;
}

void Resident::createPassword() {
	bool passok = false;
	char toContinue;
	do {
			string passFrisrtAtempt; //Here we store the fisrt attempt of the password
			cout << "Enter password,min 8 digits and contain at least one lowercase, one uppercase, one digit" << endl;
			cin >> passFrisrtAtempt;
			if (passFrisrtAtempt.length() >= 8) //we only continue is the password has at least 8 characters
				if (any_of(passFrisrtAtempt.begin(), passFrisrtAtempt.end(), islower) &&  //we check that is at least one lowercase
					any_of(passFrisrtAtempt.begin(), passFrisrtAtempt.end(), isupper) &&  //we check taht is at least one capital
					any_of(passFrisrtAtempt.begin(), passFrisrtAtempt.end(), isdigit)) {  //we check that is at least one number
					std::cout << "Re-enter your password: "; //if all what was before if ok we continue
					std::string secondAtempt;
					std::cin >> secondAtempt;  // we read the secon atempt to confirm that the password is correct
					if (passFrisrtAtempt == secondAtempt) { // if the two atempts are equal we can continue
						password = passFrisrtAtempt;
						passok = true; // this allow us to exit the function when the password is ok
					}
				}
				else { //if we are missing any of the conditions of the second if
					std::cout << "Your password should contain at least a lowercase, a uppercase and a digit. ";
					toContinue = _getch();
				}
			else { //if we the password is too short
				std::cout << "Your password should be at least 8 characters long. ";
				toContinue = _getch();
			}
	} while (!passok);
}

void Resident::createPIN() {
	bool PINok = false;
	do {
		cout << "Enter your PIN:  (6-digit long) ";
		string firstAtempt; // we store the PIN in a string to avoid user errors
		cin >> firstAtempt;
		if (firstAtempt.size() == 6) { // if the pin is 6-digit long we continue
			if (all_of(firstAtempt.begin(), firstAtempt.end(), isdigit)) { //if all the characters are numbers we continue
				if (firstAtempt[0] == firstAtempt[1] && firstAtempt[0] == firstAtempt[2] && firstAtempt[0] == firstAtempt[3]
					&& firstAtempt[0] == firstAtempt[4] && firstAtempt[0] == firstAtempt[5]) //if all numbers are the same we stop
					cout << "Please use different numbers in your PIN. ";
				else {// if the numbers are not the same we go to the next line
					if ((firstAtempt[0] == firstAtempt[1] + 1 && firstAtempt[0] == firstAtempt[2] + 2 && firstAtempt[0] == firstAtempt[3] + 3
						&& firstAtempt[0] == firstAtempt[4] + 4 && firstAtempt[0] == firstAtempt[5] + 5) ||
						(firstAtempt[0] == firstAtempt[1] - 1 && firstAtempt[0] == firstAtempt[2] - 2 && firstAtempt[0] == firstAtempt[3] - 3
							&& firstAtempt[0] == firstAtempt[4] - 4 && firstAtempt[0] == firstAtempt[5] - 5))//if the numbers are consecutive we stop
						cout << "Please do not use consequtive numbers.";									
					else { //if the numbers are not consecutive we can continue to assign the PIN
						cout << "Re-enter your PIN: "; //we read the PIN again to confirm
						string secondAtempt;
						cin >> secondAtempt;
						if (firstAtempt == secondAtempt) { //if the two PINs are equal we can assign and finis
							PIN = firstAtempt;
							PINok = true; //this allow us to exit the function when the PIN is assigned
						}
					}
				}
			}
			else //if any caracteer is not a number we give back a message
				cout << "Please use only digitis (0 to 9)";
		}
		else //if the PIN is not 6-digit long we give back a message
			cout << "The PIN has to be 6-digit long.";
	} while (!PINok);
}

void Resident::createNFC() {
	std::cout << "Place your NFC chip on the sensor: ";
	std::cin >> NFC;
}

void Resident::createFingerPrint() {
	std::cout << "Place your finger on the sensor: ";
	std::cin >> fingerprint;
}

//all the bool functions here return true is the chek is correct and false if is wrong

bool Resident::checkName(string nameAtempt) {
	if (nameAtempt == userName)
		return true;
	else
		return false;
}

bool Resident::checkPIN(string PINAtempt) {
	if (PINAtempt == PIN)
		return true;
	else
		return false;
}

bool Resident::checkPassword(std::string passAtempt) {
	if (passAtempt == password)
		return true;
	else
		return false;
}

bool Resident::checkNFC(std::string NFCAtempt) {
	if (NFCAtempt == NFC)
		return true;
	else
		return false;
}

bool Resident::checkFingerPrint(char fingerAtempt) {
	if (fingerAtempt == fingerprint)
		return true;
	else
		return false;
}

//all the functions from here check a value from the bool functions, if is correct we call the function to create a new one

void Resident::changePassword() {
	std::cout << "Enter your current password. ";
	std::string passAtempt;
	std::cin >> passAtempt;
	if (checkPassword(passAtempt))
		createPassword();
	else
		std::cout << "Incorrect password. ";
}

void Resident::changePIN() {
	std::cout << "Enter your current PIN. ";
	char PINAtempt[6];
	std::cin >> PINAtempt;
	if (checkPIN(PINAtempt))
		createPIN();
	else
		std::cout << "Incorrect PIN";
}

void Resident::changeNFC() {
	std::cout << "Place your NFC chip on the sensor. ";
	std::string NFCAtempt;
	std::cin >> NFCAtempt;
	if (checkNFC(NFCAtempt))
		createNFC();
	else
		std::cout << "Wrong NFC chip. ";
}

std::string Resident::printResident() {
	return userName;
}


//please do not refer to this two last functions they are used to save the information of the users
void Resident::loadResident(char load_fingerPring, string load_NFC, string load_PIN, string load_password, string load_username) {
	fingerprint = load_fingerPring;
	NFC = load_NFC;
	PIN = load_PIN;
	password = load_password;
	userName = load_username;
}

string Resident::saveResident() {
	string toSave;
	toSave = fingerprint;
	toSave.append(" ");
	toSave.append(NFC);
	toSave.append(" ");
	toSave.append(PIN);
	toSave.append(" ");
	toSave.append(password);
	toSave.append(" ");
	toSave.append(userName);
	return toSave;	
}