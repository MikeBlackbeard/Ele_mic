#pragma once
/**
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cstring>
//#include "atemptoopen.h"

void visitor();
void confirmVisitor();
bool confirmHomeOwnerLocation();
bool doorUnlocked();
bool generateAndConfirmPin();
void doorOpened(bool doorStatus); **/

#include <iostream>
#include <windows.h>
#include <time.h>

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

