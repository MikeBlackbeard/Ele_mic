#include "Room.h"
#include"Bulb.h"
#include <fstream>

Room::Room()
{

}

bool Room::checkRoom(string nameAtempt)
{
	if (nameAtempt == RoomID)
		return true;
	else
		return false;
}

void Room::room(string newRoom)
{

		RoomID = newRoom;		

}

string Room::saveRoom()
{
	string toSave;
	toSave = RoomID;
	toSave.append(" ");
	return toSave;
}


void Room::addBulb()
{
	string newBulb;
	cout << "Enter Bulb Name: " << endl;
	cin >> newBulb;
	bool free = true;
	for (int i = 0; i < Lamps.size(); i++)
		if (Lamps[i].checkBulb(newBulb)) {
			free = false;
			break;
		}
	if (free) {
		Bulb bulb;
		bulb.bulb(newBulb);
		Lamps.push_back(bulb);
	}
	else {
		cout << "Bulb already exists. ";
		char toContinue = _getch();
	}
}

void Room::accessBulb()
{ 
	string bulbAtempt;
	Bulb bulb;
	cout << "please enter bulb name" << endl;
	cin >> bulbAtempt;
	int getBulb = FindBulbName(bulbAtempt);
	if (getBulb != -1) //
	{
		cout << "you are in Bulb :" << bulbAtempt<< endl;
		bool ok = true;
		do {
			system("cls");
			cout << "      ***************************************" << endl;
			cout << "      ***            Bulb control            ***" << endl;
			cout << "      ***************************************" << endl << endl;
			cout << "            1. Turn on " << endl;
			cout << "            2. Turn Off" << endl;
			cout << "            3. check state" << endl;
			cout << "            4. Edit Name" << endl;
			cout << "            5. back " << endl;
			cout << "            Select an option. ";
			string menuOption;
			cin >> menuOption;
			string bulbname;
			cin.clear();
			if (menuOption.length() == 1) {
				switch (menuOption[0])
				{
				case '1':
					bulb.lightOn(); 
					break;
				case '2':
					bulb.lightOff();
					break;
				case '3':
					bulb.PrintState();
					break;
				case '4':
					bulb.EditBulbName();
					break;
				case '5':
					ok = false;
					break;
				default:
					break;
				}
			}
		} while (ok);
	} //end if that check password you can use an else to say that the password is incorrect
}

void Room::deleteBulb()
{
	cout << "please enter the Bulb  you want to delete: ";
	string deleteBulb;
	cin >> deleteBulb;
	int bulbTodelete = -1;
	bulbTodelete = FindBulbName(deleteBulb);
	if (bulbTodelete != -1) {
		bool rundelete = true;
		char toContinue;
		do {
			cout << "The bulb " << Lamps[bulbTodelete].printBulb() << " will be deleted." <<
				"press Y to continue or press N to cancel. ";
			string deleteOption; //we read the option to confirm to delete
			cin >> deleteOption;
			if (deleteOption.size() == 1) { //we only continue if the option is one character long
				switch (deleteOption[0])
				{
				case 'y':
				case 'Y': //if the option is yes we delete the user
					Lamps.erase(Lamps.begin() + bulbTodelete);
					cout << "The Bulb " << deleteBulb << " has been deleted. " << endl <<
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
		cout << "The User room name is incorrect. \n Press any key to continue. ";
		char a = _getch();
	}
}

int Room::FindBulbName(string nameAtepmt)
{
	for (int i = 0; i < Lamps.size(); i++) {
		if (Lamps[i].checkBulb(nameAtepmt))
			return i;
	}
	return -1;
}

void Room::loadRoom(string load_RoomID)

{
	RoomID = load_RoomID;
	
}


void Room::showbulb()
{
	for (int i = 0; i < Lamps.size(); i++)
	{
		std::cout << std::endl << "Bulb" << i + 1 << " " << Lamps[i].printBulb();
	}
}

string Room::printRoom()
{
	return RoomID;

}


