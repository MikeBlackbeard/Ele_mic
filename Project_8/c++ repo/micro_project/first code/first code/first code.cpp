

#include <iostream>
#include"car.h"
#include<string>
#include"calculator.h"
using namespace std; 

int main()
{

	calculator c1; 
	cout << "this is version 1\t" <<        c1.add(3, 7) << endl; 
	cout << "this is version 2\t" <<      c1.add(3, 7,10) << endl;
	cout << "this is version 4\t" <<      c1.add("hello", "Marwa") << endl;
	cout << "this is version 3\t" <<c1.add(4,5.6) << endl;


	

}

