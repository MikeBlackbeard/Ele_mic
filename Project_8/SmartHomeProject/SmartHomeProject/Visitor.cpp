#include "Visitor.h"

int avActive()
{
	cout << "Hello guest, please bitte enter your name: " << endl;
	string name;
	cin >> name;
	cout << "Welcome " << name << " few security checks before we grant you access to the door" << endl;
	cout << endl;

	cout << "Dear" << name << "the Audio and Video recording is active" << endl;
	return CONFIRM_VISITOR;
}

int confirmVisitor()
{
	char quest1;
	int homeOwner = 0;
	cout << "Is the owner home? " << "Please type (Y) for yes and (N) for No" << endl;
	cin >> quest1;
	if ((quest1 >= 'a' && quest1 <= 'z') || (quest1 >= 'A' && ^quest1 <= 'Z'))
	{
		if (quest1 == 'y')
		{
			cout << "The owner is verifying you through the AV system" << endl;
			cout << "==>==>==>==>==>" << endl;
			cout << "==>==>==>==>==>==>==>==>==>==>" << endl;
			cout << "==>==>==>==>==>==>==>==>==>==>==>==>==>==>==>" << endl;
			return DOOR_UNLOCK;
		}
		else if (quest1 == 'Y')
		{
			cout << "The owner is verifying you through the AV system" << endl;
			cout << "==>==>==>==>==>" << endl;
			cout << "==>==>==>==>==>==>==>==>==>==>" << endl;
			cout << "==>==>==>==>==>==>==>==>==>==>==>==>==>==>==>" << endl;
			return DOOR_UNLOCK;
		}
		else if (quest1 == 'n')
		{
			return GENERATE_PIN;
		}
		else if (quest1 == 'N')
		{
			return GENERATE_PIN;
		}
		else
		{
			cout << "You did not follow the instruction" << endl;
			return EXIT;
		}
	}
}

int generateConfirmPin() 
{
	srand((int)time(0));
	int r = (rand() % 10000);
	cout << "The pin sent by the owner is " << r << endl;
	int i = 0;
	while (i < 3)
	{
		cout << "Please  enter the pin: " << endl;
		int pin;
		cin >> pin;
		if (r == pin) {
			return DOOR_UNLOCK;
		}
		else if (i < 2)
		{
			cout << "You entered the wrong pin" << endl;
			cout << "This is your " << i + 1 << ". trial" << endl;
		}
		else
		{
			cout << "Invalid input. The door remains closed. ";
			return EXIT;
		}
		i++;
	}
}

int unlockDoor()
{
	cout << "DOOR OPENED, you can enter the house" << endl;
	return EXIT;
}

void exit()
{
	char tocontinue = _getch();
}

void visitorLoop()
{
	int status = AV_ACTIVE;
	bool programRun = true;

	do
	{
		switch (status)
		{
		case AV_ACTIVE:
			status = avActive();
			break;
		case CONFIRM_VISITOR:
			status = confirmVisitor();
			break;
		case GENERATE_CONFIRM_PIN:
			status = generateAndConfirmPin();
			break;
		case DOOR_UNLOCK:
			status = unlockDoor();
			break;
		case EXIT:
			status = exit();
			break;
		}
		default:
			break;
	} while (programRun);
}