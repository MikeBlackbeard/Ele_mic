
#include "calculator.h"

int calculator::add(int n1, int n2)
{
    return n1+n2;
}

int calculator::add(int n1, int n2, int n3)
{
    return n1+n2+n3;
}

float calculator::add(float n1, float n2)
{
    float f = n1 + n2; 
    return f;
}

string calculator::add(string a, string b)
{
    return a+ " " +b ;
}

calculator::calculator():
{
}

calculator::~calculator()
{
}

int calculator::calculator(int a, int b):n1(a),n2(b)
{

}
