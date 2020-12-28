#include "Resident.h"

Resident::Resident() {
	fingerprint = ' ';
}

Resident::~Resident() {
	cout << "Resident distructed";
}

void Resident::addResident(string newUserName) {
	userName = newUserName;
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
			string passFrisrtAtempt;
			cout << "Enter password,min 8 digits and contain at least one lowercase, one uppercase, one digit" << endl;
			cin >> passFrisrtAtempt;
			if (passFrisrtAtempt.length() >= 8)
				if (any_of(passFrisrtAtempt.begin(), passFrisrtAtempt.end(), islower) &&
					any_of(passFrisrtAtempt.begin(), passFrisrtAtempt.end(), isupper) &&
					any_of(passFrisrtAtempt.begin(), passFrisrtAtempt.end(), isdigit)) {
					std::cout << "Re-enter your password: ";
					std::string secondAtempt;
					std::cin >> secondAtempt;
					if (passFrisrtAtempt == secondAtempt) {
						password = passFrisrtAtempt;
						passok = true;
					}
				}
				else {
					std::cout << "Your password should contain at least a lowercase, a uppercase and a digit. ";
					toContinue = _getch();
				}
			else {
				std::cout << "Your password should be at least 8 characters long. ";
				toContinue = _getch();
			}
	} while (!passok);
}

void Resident::createPIN() {
	bool PINok = false;
	do {
		cout << "Enter your PIN:  (6-digit long) ";
		string firstAtempt;
		cin >> firstAtempt;
		if (firstAtempt.size() == 6) {
			if (all_of(firstAtempt.begin(), firstAtempt.end(), isdigit)) {
				if (firstAtempt[0] == firstAtempt[1] && firstAtempt[0] == firstAtempt[2] && firstAtempt[0] == firstAtempt[3]
					&& firstAtempt[0] == firstAtempt[4] && firstAtempt[0] == firstAtempt[5])
					cout << "Please use different numbers in your PIN. ";
				else {
					if ((firstAtempt[0] == firstAtempt[1] + 1 && firstAtempt[0] == firstAtempt[2] + 2 && firstAtempt[0] == firstAtempt[3] + 3
						&& firstAtempt[0] == firstAtempt[4] + 4 && firstAtempt[0] == firstAtempt[5] + 5) ||
						(firstAtempt[0] == firstAtempt[1] - 1 && firstAtempt[0] == firstAtempt[2] - 2 && firstAtempt[0] == firstAtempt[3] - 3
							&& firstAtempt[0] == firstAtempt[4] - 4 && firstAtempt[0] == firstAtempt[5] - 5))
						cout << "Please do not use consequtive numbers.";
					else {
						cout << "Re-enter your PIN: ";
						string secondAtempt;
						cin >> secondAtempt;
						if (firstAtempt == secondAtempt) {
							PIN = firstAtempt;
							PINok = true;
						}
					}
				}
			}
			else
				cout << "Please use only digitis (0 to 9)";
		}
		else
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