#pragma once
#include <iostream>
#include <windows.h>
#include <time.h>

#include"App.h"
#include"Bulb.h"
#include"Room.h"
#include "Resident.h"
#include "DS2HouseResidents.h"

#define MobileApp 0
#define ConfirmUserPass 1
#define RoomAccess 2
#define LighteningSystem 3
#define BulbOn 4
#define BulbOff 5
#define EXIT 8

int Mobile_App(DS2HouseResidents* MyHouse, App* appData);
int Confirm_UserPass(DS2HouseResidents* MyHouse, App* appData);


int Room_fun(DS2HouseResidents* MyHouse, App* appData);
int Lightening_system(DS2HouseResidents* MyHouse, App* appData);
int Bulb_On(Bulb* bulb);
int Bulb_Off(Bulb* bulb);
void AppAccess(DS2HouseResidents* MyHouse, App* appData, Bulb* bulb);
