#pragma once
#include<string>
#include<iostream>
using namespace std; 
class calculator
{
public :
	int add(int n1, int n2);
	int add(int n1, int n2, int n3);
	float add(float n1, float n2);
	string add(string a, string b);
	calculator();
	~calculator(); 

};

