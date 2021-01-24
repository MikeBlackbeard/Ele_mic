#pragma once

#include <iostream>
using namespace std;

#define READ_TEMP 0
#define HEATING 1
#define COOLING 2/
#define STANDBY 3

int readTemp();
void heat(int temp, string name);
void cool(int temp, string name);
void standby(int temp, string name);
void HVACloop();

