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
void control(int event);

int state = BulbOn;//intital state 

int testEventSequence[] = { SwOff,SwOn,SwOn, SwOff,SwOff }; //Event

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



	for (int testIndex = 0; testIndex < 5; testIndex++) {
		control(testEventSequence[testIndex]);
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

void control(int event)
{

	switch (state)
	{

	case BulbOn:
		if (event == SwOff)
		{
			state = BulbOff;
		}
		break;

	case BulbOff:

		if (event == SwOn)
		{
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


