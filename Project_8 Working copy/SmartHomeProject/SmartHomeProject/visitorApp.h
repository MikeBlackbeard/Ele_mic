#pragma once

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
void doorOpened(bool doorStatus);
