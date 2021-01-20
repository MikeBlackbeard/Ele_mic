#pragma once
class Visitor
{
private:
	char VisitorPin[6];

public:
	Visitor();
	~Visitor();
	void GetPIN(char RandPin[6]);
};


#include <iostream>
#include <windows.h>
#include <time.h>
#include "visitorApp.h"

#define AV_ACTIVE 0
#define CONFIRM_VISITOR 1
#define GENERATE_CONFIRM_PIN 2
#define DOOR_UNLOCK 3
#define EXIT 4

int avActive();
int confirmVisitor();
int generateConfirmPin();
int unlockDoor();
void exit();
void visitorLoop();


