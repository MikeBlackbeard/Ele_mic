#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>
#include <cctype>
#include <cstring>
#include "AttemptToOpen.h"

void visitor();
void confirmVisitor();
bool confirmHomeOwnerLocation();
bool doorUnlocked();
bool generateAndConfirmPin();
void doorOpened(bool doorStatus);
