#pragma once
#include "Person.h"
class Student :public Person
{
private:
	int level;
	float GPA;
	string dep;

public:
	void set_level(int l)
	{
		level = l;
	}
	void set_GPA(int g)
	{
		GPA = g;
	}
	void set_dep(string d)
	{
		dep = d;
	}

	string get_dep() {
		return dep; 
	}
	void display()
	{
		Person::display();
		cout << "the student leve is " << level << "GPA" << GPA << endl;
	}
}; 