#include <iostream>
#include "visitorApp.h"

#define CONFIRM_UNKNOWN 0
#define ACTIVATE_ALARM_SYSTEM 1
#define VISITOR 2
#define EXIT 3

int confirmStatus = CONFIRM_UNKNOWN;

using namespace std;

int confirmUnknown()
{
      cout <<"New open attempt detected. do you want to activate the alarm system? (Y/N)";
      char input;
      cin >> input;
      if (input == 'y'|| input == 'Y')
        return ACTIVATE_ALARM_SYSTEM;
      else
            return VISITOR;
}



int doorOpenAtempt ()
{
    switch (confirmStatus)
    {
    case CONFIRM_UNKNOWN:
        confirmStatus = confirmUnknown();
        break;
    case ACTIVATE_ALARM_SYSTEM:
         cout <<" The alarm system is activated. ";
         confirmStatus = EXIT;
         break;
         case VISITOR:
         cout << " Sending to Visitor.";
         visitor();
         confirmStatus = EXIT;
         break;
    default:
        break;
    }
    return 0;
}        

        