#include "HVAC.h";
#include <conio.h>;
using namespace std;

void heat(int temp, string name)
{
	
		cout << "Welcome " << name << " The tempertaure is currently " << temp << " therefore it is HEATING" << endl;

		char tocontinue = _getch();
}

void cool(int temp, string name)
{
	if (temp > 25)
	{
		cout << "Welcome " << name << " The tempertaure is currently " << temp << " therefore it is COOLING" << endl;
	}

	else
	{
		char tocontinue = _getch();
	}
}

void standby(int temp, string name)
{
	if ((temp >= 20) || (temp <= 25))
	{
		cout << "Welcome " << name << " The tempertaure is currently " << temp << " therefore it is STANDBY" << endl;
	}

	else
	{
		char tocontinue = _getch();
	}
}

void HVACloop() {
	cout << "Welcome to our HVAC System" << endl;
	cout << "Please enter your name: " << endl;
	string name;
	cin >> name;
	cout << name <<" Please What is the current room temperature: " << endl;
	int temp;
	cin >> temp;

	int status = READ_TEMP;
	bool programRun = true;
	do
	{
		switch (status)
		{
		case READ_TEMP:
			if (temp < 20) {
				status = HEATING;
			}
			else if (temp > 25) {
				status = COOLING;
			}
			else {
				status = STANDBY; //The system will neither cool nor heat because its in the normal room temp
			}
			break;
		case HEATING:
			heat(temp, name);
			break;
		case COOLING:
			cool(temp, name);
			break;
		case STANDBY:
			standby(temp, name);
			break;
		default:
			break;
		}
	} while (programRun);
		

}

