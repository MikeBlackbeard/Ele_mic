#include "Person.h"

Person::Person():name(""),gender(""),age(0)
{
}

Person::Person(string n, string g, float a):name(n),gender(g),age(a)
{
}

void Person::set_age(float a)
{
	age = a; 
}

float Person::get_age()
{
	return age;
}

void Person::set_name(string n)
{
	name = n;
}

string Person::get_name()
{
	return name;
}

void Person::set_gender(string g)
{
	gender = g;
}

string Person::get_gender()
{
	return gender;
}

void Person::display()
{
	cout << "the name is " << name << endl; 
	cout << "the gender is " << gender << endl;
	cout << "the age is " << age << endl;



}

