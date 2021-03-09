#include"ToTheApp.h"



int Mobile_App(DS2HouseResidents* MyHouse, App* appData)
{
	
		system("cls");
		cout << "      ***************************************" << endl;
		cout << "      ***            App MENU            ***" << endl;
		cout << "      ***************************************" << endl << endl;
		cout << "            1. Log in " << endl;
		cout << "            2. Return to user menu." << endl;
		cout << "            Select an option ";
		string menuOption;
		cin >> menuOption;
		cin.clear();
		if (menuOption.length() == 1)
		{

			return ConfirmUserPass;
		}
	else
		return EXIT;
}

int Confirm_UserPass(DS2HouseResidents* MyHouse, App* appData)
{

	string userAtempt, passwordAtempt; //user try to access the App
	int getUser = -1;
	bool verified = true;

		cout << "please enter you user name" << endl;
		cin >> userAtempt;
		getUser = MyHouse->FindResidentName(userAtempt); // find user in DS2HouseResidents.cpp
		if (getUser != -1) //if user  found
		{
			cout << "plese enter your password" << endl;
			cin >> passwordAtempt;
			if (MyHouse->VerifyPassword(getUser, passwordAtempt)) //fun to check password
			{ //room menu
				cout << "username and Password found" << endl;
			return RoomAccess;
		}
		else 
				cout << "username and Password found" << endl;
				return MobileApp;
	}
}
int Room_fun(DS2HouseResidents* MyHouse, App* appData)
{
	bool ok = true;
	char a;
	do {
		system("cls");
		cout << "      ***************************************" << endl;
		cout << "      ***            ROOM MENU            ***" << endl;
		cout << "      ***************************************" << endl << endl;
		cout << "            1. Create a new room." << endl;
		cout << "            2. Access a room." << endl;
		cout << "            3. Delete a room" << endl;
		cout << "            4. Room List" << endl;
		cout << "            5. back " << endl;
		cout << "            Select an option. ";
		string menuOption;
		cin >> menuOption;
		string roomname;
		cin.clear();
		if (menuOption.length() == 1) {
			switch (menuOption[0])
			{
			case '1':
				appData->AddRoom();
				return RoomAccess;
				break;
			case '2':
				return LighteningSystem ;
				break;
			case '3':
				appData->deleteRoom();
				return RoomAccess;
				break;
			case '4':
				appData->ShowRoom();
				 a = _getch();
				 return RoomAccess;
				break;
			case '5':
				ok = false;
				break;

			default:
				break;
			}
		}
	} while (ok);
} 

int Lightening_system(DS2HouseResidents* MyHouse,App* appData)
{
	appData->EnterRoom();
	return EXIT;
}

 int Bulb_On(Bulb *bulb)
{
	 bulb->lightOn();
	return EXIT;
}
 int Bulb_Off(Bulb* bulb)
{
	 bulb->lightOn();
	return EXIT;
}


void AppAccess(DS2HouseResidents* MyHouse, App* appData, Bulb* bulb)
{
	int state = MobileApp;
	bool run = true;
	char action;
	string Userenter;
	string PassEnter;
	int userAtempt = -1;
	int falseInput = 0;
	do
	{
		switch (state)
		{
		case MobileApp:
			state = Mobile_App(MyHouse, appData);
			if (state == EXIT)
				run = false;
			break;
		case ConfirmUserPass:
			state = Confirm_UserPass(MyHouse,appData);
			break;
		case RoomAccess:
			state= Room_fun( MyHouse, appData);
			break;
		case LighteningSystem:
			state=Lightening_system(MyHouse,appData);
			break;
		case BulbOn:
			 state=Bulb_On(bulb);
			break;
		case BulbOff:
			state= Bulb_Off(bulb);
			break;
		default:
			break;
		}
	} while (run);
}
