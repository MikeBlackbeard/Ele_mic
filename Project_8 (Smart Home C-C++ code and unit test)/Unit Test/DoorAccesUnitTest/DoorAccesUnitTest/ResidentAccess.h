#pragma once

#include <iostream>
#include <windows.h>
#include <time.h>
#include "Resident.h"
#include "DS2HouseResidents.h"

#define KEYPAD 0
#define CONFIRM_FINGER 1
#define LOCK_KEYPAD 2
#define SECOND_SEC_LVL 3
#define NFC_CONF 4
#define PIN_CONF 5
#define NEW_PIN 6
#define UNLOCK 7
#define EXIT 8

int keypad(DS2HouseResidents* MyHouse, char* action, int* userAtempt, int* falseInput, char opt1, string opt2);
int confirm_finger(DS2HouseResidents* MyHouse, char* action, int* userAtempt, int* falseInput, char opt1, string opt2);
int lockKeypad(DS2HouseResidents* MyHouse, char* action, int* userAtempt, int* falseInput, char opt1, string opt2);
int secondSecLvl(DS2HouseResidents* MyHouse, char* action, int* userAtempt, int* falseInput, char opt1, string opt2);
int NFCConf(DS2HouseResidents* MyHouse, char* action, int* userAtempt, int* falseInput, char opt1, string opt2);
int PINConf(DS2HouseResidents* MyHouse, char* action, int* userAtempt, int* falseInput, char opt1, string opt2);
int newPin(DS2HouseResidents* MyHouse, char* action, int* userAtempt, int* falseInput, char opt1, string opt2);
int unlock(DS2HouseResidents* MyHouse, char* action, int* userAtempt, int* falseInput, char opt1, string opt2);
void doorLoop(DS2HouseResidents* MyHouse);