#pragma once

#include <iostream>
#include <windows.h>
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

int keypad(DS2HouseResidents* MyHouse, char* action);
int confirm_finger(DS2HouseResidents* MyHouse, char* action, int* userAtempt, int* falseInput);
int lockKeypad(int* falseInput);
int secondSecLvl(DS2HouseResidents* MyHouse, char* action);
int NFCConf(DS2HouseResidents* MyHouse, char* action, int* userAtempt, int* falseInput);
int PINConf(DS2HouseResidents* MyHouse, char* action, int* userAtempt, int* falseInput);
int newPin();
int unlock();
void doorLoop(DS2HouseResidents* MyHouse);