#include "visitorApp.h";
#include <conio.h>

using namespace std;

void visitor()
{
    cout << "Hello guest, please enter your name: " << endl;
    string name;
    cin >> name;
    cout << "Welcome " << name << " few security checks before we grant you access to the door" << endl;
    cout << endl;

    confirmVisitor();

    //confirmHomeOwnerLocation();  //

    doorUnlocked();
    char tocontinue = _getch();
}

// This function enables the visitor to confirm the Visitor
void confirmVisitor() {
    cout << "The owner is verifying you through the AV system" << endl;
    cout << "==>==>==>==>==>" << endl;
    cout << "==>==>==>==>==>==>==>==>==>==>" << endl;
    cout << "==>==>==>==>==>==>==>==>==>==>==>==>==>==>==>" << endl;
}

// This function enables the visitor to confirm the owners location
bool confirmHomeOwnerLocation() {    
    cout << "Is the owner home? " << "Please type (Y) for yes and (N) for No" << endl;
    char quest1;
    int homeOwner = 0;
    cin >> quest1;
        switch (quest1)
        {
        case 'y':
        case 'Y':
            homeOwner = 1;
            return true;
            break;
        case 'n':
        case 'N':
            homeOwner = 1;
            return false;
            break;
        default:
            homeOwner = 0;
            cout << "Please enter the supposed character";
        }
    return false; // you should try a do - while loop to prevent, because if the key is not y you will always return something and it would be random
}

bool doorUnlocked() {
    if (!confirmHomeOwnerLocation()) {  //I change the code here
        generateAndConfirmPin();
        return false;
    }
    else {   // I deleted the if here
        cout << "The door will be unlocked by the user" << endl;
        doorOpened(true);
        return true;
    }
}

bool generateAndConfirmPin()
{
    srand((int)time(0));
    int r = (rand() % 10000);
    cout << "The pin sent by the owner is " << r << endl;
    int i = 0;
    while (i < 3)
    {
        cout << "Please  enter the pin: " << endl;
        int pin;
        cin >> pin;
        if (r == pin) {
            doorOpened(true);
            return true;
        }
        else if (i < 2)
        {
            cout << "You entered the wrong pin" << endl;
            cout << "This is your " << i + 1 << ". trail" << endl;
        }
        else
        {
            cout << "Invalid input. The door remains closed. ";
            //confirmUnknown();
        }
        i++;

    }
}
void doorOpened(bool doorStatus) 
{
    cout << "DOOR OPENED, you can enter the house";
}