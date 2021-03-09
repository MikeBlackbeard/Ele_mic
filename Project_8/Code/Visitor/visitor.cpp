#include <iostream>
#include <time.h>
#include <stdlib.h>

#define AVACTIVE 0
#define CONFIRMVISITOR 1
#define GENERATEPIN 2
#define DOORUNLOCK 3
#define CONFIRMPIN 4
using namespace std;

int status = AVACTIVE;
int temppin = 0;

int main()
{
    for(;;)
    {
        srand(time(0));
            switch (status)
       {
       case AVACTIVE:
           cout << "Press a enter when visitor is at the door. ";
            char a;
            cin >> a;
            status = CONFIRMVISITOR;
        break;
        case CONFIRMVISITOR:
            cout << "Press Y if the visitor is known or N if unknown. ";
            char b;
            cin >> b;
            if(b == 'y' || b == 'Y')
                status = GENERATEPIN;
            else
                status = AVACTIVE;
        break;
        case GENERATEPIN:
            temppin = rand() % 1000000;
            cout << "temporal PIN: " << temppin << endl;
            status = CONFIRMPIN;
        break;
            case CONFIRMPIN:
            int enterpin;
            cout << "Enter the PIN. ";
            cin >> enterpin;
            if(enterpin == temppin)
                status = DOORUNLOCK;
            else
                status = AVACTIVE;
        break;
        case DOORUNLOCK:
            cout << "the door is open. Press any key to continue. ";
            status = AVACTIVE;
        default:
        break;
        }
    }
    return 0; 
}