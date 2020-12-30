#include "App.h"
using namespace std; 

App::App() {

}

void App::AddRoom()
{
	string newRoom;
	cout << "Enter Room Name: "<<endl ;
	cin >> newRoom;  
	bool free = true;
	for (int i = 0; i < roomList.size(); i++)
		if (roomList[i].checkRoom(newRoom)) { 
			free = false; 
			break; 
		}
	if (free) { 
		Room room;
		room.room(newRoom); 
		roomList.push_back(room); 
	}
	else {
		cout << "room already exists. ";
		char toContinue = _getch();
	}
}

		



void App::EnterRoom()
{
	string roomAtempt; 
	Room roomBulb;
	cout << "please enter room name" << endl;
	cin >> roomAtempt;
	int getRoom = FindRoomName(roomAtempt); 
	if (getRoom != -1) //if user  found
	{
		cout << "you are in room :"<<roomAtempt << endl;
		bool ok = true;
		do {
			system("cls");
			cout << "      ***************************************" << endl;
			cout << "      ***            ROOM control            ***" << endl;
			cout << "      ***************************************" << endl << endl;
			cout << "            1. Create a new bulb." << endl;
			cout << "            2. Access a bulb." << endl;
			cout << "            3. Delete a bulb" << endl;
			cout << "            4. Create a new Window." << endl;
			cout << "            5. Access a Window." << endl;
			cout << "            6. Delete a Window" << endl;
			cout << "            7. back " << endl;
			cout << "            Select an option. ";
			string menuOption;
			cin >> menuOption;
			string roomname;
			cin.clear();
			if (menuOption.length() == 1) {
				switch (menuOption[0])
				{
				case '1':
					roomBulb.addBulb();
					break;
				case '2':
					roomBulb.accessBulb();
					break;
				case '3':
					roomBulb.deleteBulb();						
					break;
				/*case '4':
					appData->AddRoom();
					break;
				case '5':
					cout << "enter room name" << endl; //same, make a full function where you will ask a name, also in that function you can print all the rooms that we already have
					cin >> roomname;
					appData->EnterRoom(roomname);
					break;
				case '6':
					appData->deleteRoom();
					break;*/
				case '7':
					ok = false;
					break;
				default:
					break;
				}
			}
		} while (ok);
	}
	else {
		cout << "The room does not exist. ";
		char toContinue = _getch();
	}
}
	

void App::deleteRoom() 
{
	cout << "please enter the Room Name  you want to delete: ";
	string deleteroom;
	cin >> deleteroom; 
	int roomTodelete = -1;
	roomTodelete = FindRoomName(deleteroom);  
	if (roomTodelete != -1) {  
		bool rundelete = true;
		char toContinue;
		do {
			cout << "The room " << roomList[roomTodelete].printRoom() << " will be deleted." <<
				"press Y to continue or press N to cancel. ";
			string deleteOption; //we read the option to confirm to delete
			cin >> deleteOption;
			if (deleteOption.size() == 1) { //we only continue if the option is one character long
				switch (deleteOption[0])
				{
				case 'y':
				case 'Y': //if the option is yes we delete the user
					roomList.erase(roomList.begin() + roomTodelete);
					cout << "The room " << deleteroom << " has been deleted. " << endl <<
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

int App::FindRoomName(string nameAtepmt)
{
	for (int i = 0; i < roomList.size(); i++) {
		if (roomList[i].checkRoom(nameAtepmt))
			return i;
	}
	return -1;
	
}

void App::saveRoom(Room newRoom)
{
	roomList.push_back(newRoom);
}