#pragma once
#include<string>
#include<iostream>
using namespace std; 
class Person
{
private : 
	string name;
	string gender; 
	float age; 

public : 
	Person();
	Person(string n, string g, float a);
	void set_age(float a); 
	float get_age();
	void set_name(string n);
	string get_name();
	void set_gender(string g);
	string get_gender();
	void display();
	




};

