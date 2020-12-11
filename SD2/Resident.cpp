#include "Resident.h"


//Create a Resident user
Resident::Resident() {
	std::cout << "New user created" << std::endl;
	uniqueNFC = 0;
	createUserName();
	createPassword();
	addFingerPrint();
	changeUniqueCode();
	changeNFCCode();
}


//Distroy a Resident user
Resident::~Resident() {
	std::cout << "Resident deleted" << std::endl;
}

void Resident::addFingerPrint() {
	std::cout << "Please enter your new finger: ";
	std::cin >> fingerPrint;
}

void Resident::createPassword() {
	std::cout << "please enter your new pasword: ";
	std::cin >> password;
}

void Resident::changeUniqueCode() {
	if (uniqueCode == 0) {
		std::cout << "Please enter you new personal PIN: ";
		std::cin >> uniqueCode;
	}
	else {
		std::cout << "Please enter your current code: ";
		int checkcode;
		std::cin >> checkcode;
		if (checkcode == uniqueCode) {
			std::cout << "Please enter your new personal code: ";
			std::cin >> uniqueCode;
		}
		else {
			std::cout << "The code is incorrect.";
		}
	}
}

void Resident::changeNFCCode() {

}
void Resident::deactivateSystem() {

}

void Resident::changePassword() {

}

void Resident::createUserName() {
	std::cout << "please enter you user name: ";
	std::cin >> uniqueUser;
}

void Resident::alowVisitor() {
	std::cout << "Please enter your user name: ";
	std::cin >> uniqueUser;
}
