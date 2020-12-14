#include "Resident.h"
#include<string>
using namespace std;
//Create a Resident user
Resident::Resident() {
	std::cout << "New user created" << std::endl;
	uniqueNFC = 0;
	createUserName();
	createPassword();
	addFingerPrint();
	changeUniqueCode();
	changeNFCCode();
}


//Distroy a Resident user
Resident::~Resident() {
	std::cout << "Resident deleted" << std::endl;
}

void Resident::addFingerPrint() {
	std::cout << "Please enter your new finger: ";
	std::cin >> fingerPrint;
}

void Resident : createPassword();
{
  int l_case=0, u_case=0, digit=0;//flags
  string str; //password
  cout<<"Enter password,min 8 digits and contain at least one lowercase ,one uppercase ,one number"<<endl;
  
  cin>>str;
  int l=str.length(); //length
  
  for(int i=0;i<l;i++)  //check lowe,upper,digit
  {
    if(islower(str[i]))
      l_case=1;
    if(isupper(str[i]))
      u_case=1;
    if(isdigit(str[i]))
      digit=1;
  
  }
  
  if(l_case && u_case && digit && l>=8)
    cout<<"Strong password."<<endl;
  else
    cout<<"Weak password"<<endl;
}


void Resident::changeUniqueCode() {
	if (uniqueCode == 0) {
		std::cout << "Please enter you new personal PIN: ";
		std::cin >> uniqueCode;
	}
	else {
		std::cout << "Please enter your current code: ";
		int checkcode;
		std::cin >> checkcode;
		if (checkcode == uniqueCode) {
			std::cout << "Please enter your new personal code: ";
			std::cin >> uniqueCode;
		}
		else {
			std::cout << "The code is incorrect.";
		}
	}
}

void Resident::changeNFCCode() {

}
void Resident::deactivateSystem() {

}

void Resident::changePassword() {

}

void Resident::createUserName() {
	std::cout << "please enter you user name: ";
	std::cin >> uniqueUser;
}

void Resident::alowVisitor() {
	std::cout << "Please enter your user name: ";
	std::cin >> uniqueUser;
}
