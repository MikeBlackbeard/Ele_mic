#include "UserMenu.h"



int main()
{
    DS2HouseResidents MyHouse;
    Resident r;
    App use;

    bool run = true;
    LoadUsers(&MyHouse);

    do {
        system("cls");
        cout << "      ***************************************" << endl;
        cout << "      ***            MAIN MENU            ***" << endl;
        cout << "      ***************************************" << endl << endl;
        cout << "            1. User menu." << endl;
        cout << "            2. To the door" << endl;
        cout << "            3. To the App." << endl;
        cout << "            4. Exit." << endl;
        cout << "            Select an option: ";
        string menuOption1;
        cin >> menuOption1;
        cin.clear();
        if (menuOption1.length() == 1) {
            switch (menuOption1[0])
            {
            case '1':
                userMenu(&MyHouse);
                break;
            case '2':
                doorAccess(&MyHouse);
                break;
            case '3':
                AppAccess(&r);

                break;
            case '4':
                run = false;
                break;
            default:
                break;
            }
        }
    } while (run);
    //std::cout << "The resident finger print is " << NewRes1.fingerPrint << std::endl;
}
