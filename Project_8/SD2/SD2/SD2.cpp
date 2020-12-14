#include "UserMenu.h"


int main()
{
    DS2HouseResidents MyHouse;
    bool run = true;
    do {
        system("cls");
        std::cout << "      ***************************************" << std::endl;
        std::cout << "      ***            MAIN MENU            ***" << std::endl;
        std::cout << "      ***************************************" << std::endl << std::endl;
        std::cout << "            1. User menu." << std::endl;
        std::cout << "            2. To the door" << std::endl;
        std::cout << "            3. Exit." << std::endl;
        std::cout << "            Select an option: ";
        std::string menuOption1;
        std::cin >> menuOption1;
        std::cin.clear();
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
                run = false;
                break;
            default:
                break;
            }
        }
    } while (run);
    //std::cout << "The resident finger print is " << NewRes1.fingerPrint << std::endl;
}
