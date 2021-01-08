#include "ResidentAccess.h"

int keypad(DS2HouseResidents* MyHouse, char* action)
{
	int status = KEYPAD;
	system("cls");
	cout << "Finger: a-z                Back: Esc" << std::endl
		 << "Select an action";
	*action = _getch();
	if (*action == 27)
		return EXIT;
	else
		return CONFIRM_FINGER;
}

int confirm_finger(DS2HouseResidents* MyHouse, char* action, int* userAtempt, int* falseInput)
{
	if ((*action >= 'a' && *action <= 'z') || (*action >= 'A' && *action <= 'Z'))
	{
		*userAtempt = -1;
		*userAtempt = MyHouse->FindResident(*action);
		if (*userAtempt != -1)
		{
			*falseInput = 0;
			return SECOND_SEC_LVL;
		}
		else
			++*falseInput;
		if (*falseInput < 5)
			return KEYPAD;
		else
			return LOCK_KEYPAD;
	}
}

int lockKeypad(int* falseInput) 
{
	int timer = 0;
	for (int i = 0; i < 5; i++) {
		system("cls");
		cout << "The keypad is locked. it will be unlocked in: " << 5 - i << " seconds. ";
		Sleep(1000);
	}
	*falseInput = 0;
	return KEYPAD;
}

int secondSecLvl(DS2HouseResidents* MyHouse, char* action)
{
	system("cls");
	cout << "1. to enter PIN " << endl
		<< "2. to enter NFC " << endl
		<< "3. to generate random PIN " << endl
		<< "Select an option. ";
	char option;
	cin >> option;
	switch (option)
	{
	case '1':
		return PIN_CONF;
	case '2':
		return NFC_CONF;
	case '3':
		return NEW_PIN;
	default:
		return KEYPAD;
	}
}

int NFCConf(DS2HouseResidents* MyHouse, char* action, int* userAtempt, int* falseInput)
{
	cout << "\nPlease enter your PIN. ";
	string NAtempt;  //to store the PIN that the user tried to open the door
	cin >> NAtempt;
	if (MyHouse->VerifyResidentNFC(*userAtempt, NAtempt))
	{
		*falseInput = 0;
		return UNLOCK;
	}
	else
		++* falseInput;
	if (*falseInput < 3)
		return SECOND_SEC_LVL;
	else
		return LOCK_KEYPAD;
}

int PINConf(DS2HouseResidents* MyHouse, char* action, int* userAtempt, int* falseInput)
{
	cout << "\nPlease enter your NFC. ";
	string PAtempt;  //to store the PIN that the user tried to open the door
	cin >> PAtempt;
	if (MyHouse->VerifyResidentPIN(*userAtempt, PAtempt))
	{
		*falseInput = 0;
		return UNLOCK;
	}
	else
		++* falseInput;
	if (*falseInput < 3)
		return SECOND_SEC_LVL;
	else
		return LOCK_KEYPAD;
}
int newPin()
{

	return KEYPAD;
}

int unlock()
{
	cout << "The door is open. ";
	char toContinue = _getch();
	return KEYPAD;
}

void doorLoop(DS2HouseResidents* MyHouse)
{
	int accessStatus = KEYPAD;
	bool run = true;
	char action;
	int userAtempt = -1;
	int falseInput = 0;
	do
	{
		switch (accessStatus)
		{
		case KEYPAD:
			accessStatus = keypad(MyHouse, &action);
			if (accessStatus == EXIT)
				run = false;
			break;
		case CONFIRM_FINGER:
			accessStatus = confirm_finger(MyHouse, &action, &userAtempt, &falseInput);
			break;
		case LOCK_KEYPAD:
			accessStatus = lockKeypad(&falseInput);
			break;
		case SECOND_SEC_LVL:
			accessStatus = secondSecLvl(MyHouse, &action);
			break;
		case PIN_CONF:
			accessStatus = PINConf(MyHouse, &action, &userAtempt, &falseInput);
			break;
		case NFC_CONF:
			accessStatus = NFCConf(MyHouse, &action, &userAtempt, &falseInput);
			break;
		case UNLOCK:
			accessStatus = unlock();
			break;
		case NEW_PIN:
			accessStatus = newPin();
			break;
		default:
			break;
		}
	} while (run);
}
