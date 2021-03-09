#include "ResidentAccess.h"

#include <stdio.h>
#include <stdlib.h>

//each transition at least once
int testEventSequence[] = { CONFIRM_FINGER ,LOCK_KEYPAD, NEW_PIN,NFC_CONF,UNLOCK,SECOND_SEC_LVL,PIN_CONF };
char firstIterSequence[] = { 'd' ,'t', 'y','m','y','w','m' };
int secondIterSequence[] = { 3,  6  ,  2,  0,  9,  5,  0 };
int thirdIterSequence[] = { 3,  6  ,  2,  0,  9,  5,  3 };
int actionControl[] = { '1', '1', '1', '1', '1', '1', '1', };
std::string secondActionControl = "asdf";
//length of test sequence
int testSequenceLenght = sizeof(testEventSequence) / sizeof(testEventSequence[0]);
//expected output
int exptectedOutputTestEventSequence[] = { KEYPAD, KEYPAD, KEYPAD, UNLOCK, KEYPAD, PIN_CONF, LOCK_KEYPAD };
//and further tests...each state at least once
int testEventSequence2[] = { LOCK_KEYPAD,UNLOCK };

//storing the test result
int testOutputTestEventSequence[] = { 0,0,0,0,0,0,0 };
int countErrors = 0;

//function for testing the OneBitPredictor - validation test
void validationTestRun();
//print the test result
void printTestResult();

void LoadUsers(DS2HouseResidents* MyHouse);


int main(void) {
	validationTestRun();
	printTestResult();

	return EXIT_SUCCESS;
}



int accessStatus = KEYPAD; //current state, initial state is not taken

void control(int event, DS2HouseResidents* MyHouse, char* action, int* userAtempt, int* falseInput, char opt1, string opt2) {
	switch (event)
	{
	case KEYPAD:
		accessStatus = keypad(MyHouse, action, userAtempt, falseInput, opt1, opt2);
		if (accessStatus == EXIT)
		break;
	case CONFIRM_FINGER:
		accessStatus = confirm_finger(MyHouse, action, userAtempt, falseInput, opt1, opt2);
		break;
	case LOCK_KEYPAD:
		accessStatus = lockKeypad(MyHouse, action, userAtempt, falseInput, opt1, opt2);
		break;
	case SECOND_SEC_LVL:
		accessStatus = secondSecLvl(MyHouse, action, userAtempt, falseInput, opt1, opt2);
		break;
	case PIN_CONF:
		accessStatus = PINConf(MyHouse, action, userAtempt, falseInput, opt1, opt2);
		break;
	case NFC_CONF:
		accessStatus = NFCConf(MyHouse, action, userAtempt, falseInput, opt1, opt2);
		break;
	case UNLOCK:
		accessStatus = unlock(MyHouse, action, userAtempt, falseInput, opt1, opt2);
		break;
	case NEW_PIN:
		accessStatus = newPin(MyHouse, action, userAtempt, falseInput, opt1, opt2);
		break;
	default:
		break;
	}
}

// get current state
int getState() {
	return accessStatus;
}



//test implementation
void validationTestRun() {
	//test loop...
	DS2HouseResidents MyHouse;
	LoadUsers(&MyHouse);
	for (int testIndex = 0; testIndex < 7; testIndex++) {
		control(testEventSequence[testIndex], &MyHouse, &firstIterSequence[testIndex], &secondIterSequence[testIndex], &thirdIterSequence[testIndex], actionControl[testIndex], secondActionControl);
		if (getState() == exptectedOutputTestEventSequence[testIndex]) {
			testOutputTestEventSequence[testIndex] = 1;
		}
		else {
			testOutputTestEventSequence[testIndex] = 0;
			countErrors++;
		}

	}
}

void printTestResult() {
	if (countErrors) {
		printf("%d error(s) identified.\n", countErrors);
		for (int i = 0; i < testSequenceLenght; i++) {
			if (!testOutputTestEventSequence[i]) {
				printf("Error at event count %d. \n", i);
				printf("Expected state for event %d is %d\n", testEventSequence[i], exptectedOutputTestEventSequence[i]);
			}
		}
	}
	else {
		printf("No errors identified!\n");
	}
}


void LoadUsers(DS2HouseResidents* MyHouse)
{
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