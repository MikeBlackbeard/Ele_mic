#pragma once
#include<string>
#include<iostream>
using namespace std; 

class Employee
{
protected: 
	string name; 
	int emp_id; 
	float salary;

public :
	Employee() :name("unknown "), emp_id(0), salary(0.0) {};
	Employee(string n, int id, float s)
	{
		name = n;
		emp_id = id;
		salary = s;
}

	virtual float get_totalSalary() = 0; 
	virtual void print()
	{
		cout << "name &ID ,salary" << name << emp_id << salary << endl;
	}
};

class sales : public Employee
{
private :
	float gross_sales;
	float commission_rate;

public:
	sales(string n, int id, float s, float gs, float cr) :Employee(n, id, s)
	{
		gross_sales = gs;
		commission_rate = cr;
	}
	float get_totalSalary()
	{
		
		return salary + (gross_sales * commission_rate); 
	 }
	void print()
	{
		Employee::print(); 
		cout << "the gross &commison is " << gross_sales << commission_rate; 
	}
	
};

class Engineer :public Employee
{
private :
	string speciality; 
	int experience;
	int overtime;
	float overtimeHr;

public:

	Engineer(string n, int id, float s, string sp, int exp, int ot, float otHr) :Employee(n, id, s)
	{
		speciality = sp;
		experience = exp;
		overtime = ot;
		overtimeHr = otHr; 
	}

	float get_totalSalary()
	{

		return salary + (overtime * overtimeHr);
	}
	
	void print()
	{
		Employee::print();
		cout << "speci " << speciality << "experience " << experience << "over time " << overtime << "rate" << overtimeHr << endl; 
	}

};