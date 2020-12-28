// revi.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include"Employee.h"
using namespace std; 

int main()
{
    
    
    sales  s1("ahmed", 120, 5000, 50000, 0.10); 
    Engineer e1("ali", 150, 7000,"Software", 5, 10, 50);
    
    s1.print(); 
    s1.get_totalSalary();
    e1.get_totalSalary();
    e1.print();
    /* empPoint = &s1; 
    empPoint->get_totalSalary();
    empPoint->print(); 
    empPoint = &e1;
    empPoint->get_totalSalary();
    empPoint->print();*/ 
    return 0; 
}


