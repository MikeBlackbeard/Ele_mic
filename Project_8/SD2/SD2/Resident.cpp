#include "Resident.h"

Resident::Resident() {
	cout << "New Resident created";
	createUserName();
	createPassword();
	createPIN();
	createNFC();
	createFingerPrint();
}

Resident::~Resident() {
	cout << "Resident distructed";
}

void Resident::createUserName() {
	std::cout << "Enter your User Name: ";
	std::cin >> userName;
}

void Resident::createPassword() {
	bool passok = false;
	do {
			int l_case = 0, u_case = 0, digit = 0;//flags
			string str; //password
			cout << "Enter password,min 8 digits and contain at least one lowercase ,one uppercase ,one number" << endl;
			cin >> str;
			int l = str.length(); //length
			for (int i = 0; i < l; i++)  //check lowe,upper,digit
			{
				if (islower(str[i]))
					l_case = 1;
				if (isupper(str[i]))
					u_case = 1;
				if (isdigit(str[i]))
					digit = 1;
			}
			if (l_case && u_case && digit && l >= 8) {
				cout << "Strong password." << endl;
				std::cout << "Re-enter your password: ";
				std::string secondAtempt;
				std::cin >> secondAtempt;
				if (str == secondAtempt) {
					passok = true;
				}
			}	
			else
				cout << "Weak password" << endl;

		/*std::cout << "Enter your password: ";
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
		}*/
	} while (!passok);
}

void Resident::createPIN() {
	bool PINok = false;
	do {
		std::cout << "Enter your PIN:  (6-digit long) ";
		std::string firstAtempt;
		std::cin >> firstAtempt;
		if (firstAtempt.size() == 6) {
			if (std::all_of(firstAtempt.begin(), firstAtempt.end(), isdigit)) {
				if (firstAtempt[0] == firstAtempt[1] && firstAtempt[0] == firstAtempt[2] && firstAtempt[0] == firstAtempt[3]
					&& firstAtempt[0] == firstAtempt[4] && firstAtempt[0] == firstAtempt[5])
					std::cout << "Please use different numbers in your PIN. ";
				else {
					if ((firstAtempt[0] == firstAtempt[1] + 1 && firstAtempt[0] == firstAtempt[2] + 2 && firstAtempt[0] == firstAtempt[3] + 3
						&& firstAtempt[0] == firstAtempt[4] + 4 && firstAtempt[0] == firstAtempt[5] + 5) ||
						(firstAtempt[0] == firstAtempt[1] - 1 && firstAtempt[0] == firstAtempt[2] - 2 && firstAtempt[0] == firstAtempt[3] - 3
							&& firstAtempt[0] == firstAtempt[4] - 4 && firstAtempt[0] == firstAtempt[5] - 5))
						std::cout << "Please do not use consequtive numbers.";
					else {
						std::cout << "Re-enter your PIN: ";
						std::string secondAtempt;
						std::cin >> secondAtempt;
						if (firstAtempt == secondAtempt) {
							PIN = firstAtempt; 
							PINok = true;
						}
					}				
				}				
			}
			else
				std::cout << "Please use only digitis (0 to 9)";
		}
		else
			std::cout << "The PIN has to be 6-digit long.";
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

bool Resident::checkPIN(string PINAtempt) {
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