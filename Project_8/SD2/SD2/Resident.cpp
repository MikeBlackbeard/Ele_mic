#include "Resident.h"

Resident::Resident() {
	std::cout << "New Resident created";
	createUserName();
	createPassword();
	createPIN();
	createNFC();
	createFingerPrint();
}

Resident::~Resident() {
	std::cout << "Resident distructed";
}

void Resident::createUserName() {
	std::cout << "Enter your User Name: ";
	std::cin >> userName;
}

void Resident::createPassword() {
	bool passok = false;
	do {
		std::cout << "Enter your password: ";
		std::string firstAtempt;
		std::cin >> firstAtempt;
		std::cout << "Re-enter your password: ";
		std::string secondAtempt;
		std::cin >> secondAtempt;
		if (firstAtempt == secondAtempt) {
			password = firstAtempt;
			passok = true;
		}
		else {
			passok = false;
		}
	} while (!passok);
}

void Resident::createPIN() {
	bool PINok = false;
	do {
		std::cout << "Enter your PIN: ";
		std::string firstAtempt;
		std::cin >> firstAtempt;
		std::cout << "Re-enter your PIN: ";
		std::string secondAtempt;
		std::cin >> secondAtempt;
		if (firstAtempt == secondAtempt) {
			for (int i = 0; i < 6; i++) {
				PIN[i] = firstAtempt[i];
			}
			PINok = true;
		}
		else {
			PINok = false;
		}
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

bool Resident::checkPassword(std::string passAtempt) {
	if (passAtempt == password)
		return true;
	else
		return false;
}

bool Resident::checkPIN(char PINAtempt[6]) {
	if (PINAtempt == PIN)
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