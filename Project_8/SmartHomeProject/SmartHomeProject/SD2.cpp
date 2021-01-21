#include "UserMenu.h"  //in UserMenu we have all the functions related to the system is the only header that we include since in the header
                        //we include any other related header file
#include"ToTheApp.h"

//Main function this is the first one that is going to run and from here.
int main()
{
    srand(time(NULL));
    DS2HouseResidents MyHouse;  //In this variable we store all the information about the system, including the residents
    App appData;  
    Bulb bulb; 
    

    bool run = true; // will allow the system to run in a loop until we chose to exit
    LoadUsers(&MyHouse); //Here we load all the user information that we crated the last time that we used the system
    LoadAppInfo(&appData);

    do { // the loop begins
        system("cls"); // Clear the screen

        //from here the menu
        cout << "      ***************************************" << endl;
        cout << "      ***            MAIN MENU            ***" << endl;
        cout << "      ***************************************" << endl << endl;
        cout << "            1. User menu." << endl;
        cout << "            2. To the door" << endl;
        cout << "            3. To the App." << endl;
        cout << "            4. Visitor" << endl;
        cout << "            5. Exit." << endl;
        cout << "            Select an option: ";
        string menuOption1;  //we use a string to store the option so the system wont crash
        cin >> menuOption1; //reading the user selection
        cin.clear();  //we clear any information that is in the bufer (i.e if the user uses spaces in the input)
        if (menuOption1.length() == 1) {  //from here we do acces the user option
            switch (menuOption1[0])
            {
            case '1':
                userMenu(&MyHouse);  //go the the user menu
                break;
            case '2':
                doorLoop(&MyHouse);  //simulate the door behavior 
                break;
            case '3':
                AppAccess(&MyHouse, &appData,&bulb);  //simulate the app behavior
                break;
            case '4':
                visitor();
                break;
            case '5':
                run = false;  // we make run false so next loop wont run and we exit the program
                break;
            default:
                break;
            }
        }
    } while (run);
}
