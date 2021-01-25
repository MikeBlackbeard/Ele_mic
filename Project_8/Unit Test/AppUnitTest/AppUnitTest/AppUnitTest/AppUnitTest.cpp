#include <stdio.h>
#include <stdlib.h>
#include "ToTheApp.h"
#include"App.h"
#include"Bulb.h"

#define SwOn 100  //events 
#define SwOff 200 



using namespace std;

//fun 
int getstate();
void control(int event, DS2HouseResidents* MyHouse, App* appData, Bulb* bulb);
void LoadAppInfo(App* appData);

int state = BulbOn;//intital state 

int testEventSequence[] = { BulbOff,BulbOn,BulbOn, BulbOff,BulbOff }; //Event

//length of test sequence
int testSequenceLenght = sizeof(testEventSequence) / sizeof(testEventSequence[0]);

//expected output
int exptectedOutputTestEventSequence[] = { BulbOff, BulbOn,BulbOn,BulbOff,BulbOff };  //expected o/p



//storing the test result
int testOutputTestEventSequence[] = { 0,0,0,0,0,0,0 }; 
int countErrors = 0;

//function for testing the light - validation test
void validationTestRun();
//print the test result
void printTestResult();


int main(void) {
	validationTestRun();
	printTestResult();
	return EXIT_SUCCESS;
}

//test implementation
void validationTestRun() {

	DS2HouseResidents MyHouse;
	App appData;
	Bulb bulb; 	

	for (int testIndex = 0; testIndex < 5; testIndex++) {
		control(testEventSequence[testIndex], &MyHouse, &appData, &bulb);
		if (getstate() == exptectedOutputTestEventSequence[testIndex]) {
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

void control(int event, DS2HouseResidents* MyHouse, App* appData, Bulb* bulb)
{
	int state = BulbOn;
		switch (state)
		{
		case MobileApp:
			state = Mobile_App(MyHouse, appData);
			if (state == EXIT)
				break;
		case ConfirmUserPass:
			state = Confirm_UserPass(MyHouse, appData);
			break;
		case RoomAccess:
			state = Room_fun(MyHouse, appData);
			break;
		case LighteningSystem:
			state = Lightening_system(MyHouse, appData);
			break;
		case BulbOn:
			if (event==SwOff)
			{
				Bulb_Off(bulb);
				state = BulbOff;
			}
			break;

		case BulbOff:

			if (event==SwOn)
			{
				Bulb_On(bulb);
				state = BulbOn;
			}
				default:
			break;
		}
	}



//get current state
int getstate()
{
	return state;
}

void LoadAppInfo(App* appData)
{
	Room roomList;
	string load_RoomID;
	Bulb load_Lamps;
	string load_BulbID;
	bool load_BulbState;
	ifstream load_file("App.txt");
	while (load_file >> load_RoomID >> load_BulbID >> load_BulbState)
	{

		roomList.loadRoom(load_RoomID);
		load_Lamps.loadBulb(load_BulbID, load_BulbState);
		appData->loadRoom(roomList);
	}

}
