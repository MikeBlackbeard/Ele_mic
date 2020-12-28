

#include <iostream>
using namespace std; 

class rectangle {
private :

    float length;
    float width; 

public :

    void setlength(float l)
    {
        if (l >= 0)
            length = l;
        else
            cout << "wrong value " << endl; 
    }

    float getlength()
    {
        return length; 
    }

    void setwidth(float w)
    {
        if (w>=0)
        width = w; 
        else 
            cout << "wrong value " << endl;

    }

    float getwidth()
    {
        return width; 
    }

    float getarea(float a, float b)
    {
        return a * b; 
    }

};

int main()
{
   rectangle box;
   box.setlength(40.3);
   box.setwidth(30.4); 
   cout << "the area is " << box.getarea(40,30); 

    return 0; 
}