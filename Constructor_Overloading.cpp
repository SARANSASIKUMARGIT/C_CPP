#include<iostream>
using namespace std;
//C++ program for Constructor Overloading (Polymorphism - Many Forms with Same name)
class BaseClass{
private:
    int x=0;
public:
    int id;
    BaseClass()
    {
        cout<<"Default Constructor called"<<endl;
    }
    BaseClass(int x)
    {
        this->x=x;
        cout<<"Parameterized Constructor Called"<<endl;
    }
    BaseClass(BaseClass& obj)
    {
        this->id=obj.id;
        cout<<"Copy Constructor Called"<<endl;
    }
    BaseClass operator=(BaseClass& obj)
    {
        this->id=obj.id;
        cout<<"Copy Assignment Constructor Called"<<endl;
    }
    ~BaseClass()
    {
        cout<<"Destructor called to clear resources of this class"<<endl;
    }
    void display_data()
    {
        cout<<"ID = "<<id<<" , X = "<<x<<" \n";
    }
};


int main()
{
    BaseClass o1,o2(5);
    BaseClass o3=o2,o4;
    o4=o3;
    return 0;
}

/* 
OUTPUT : 
Default Constructor called
Parameterized Constructor Called
Copy Constructor Called
Default Constructor called
Copy Assignment Constructor Called
Destructor called to clear resources of this class
Destructor called to clear resources of this class
Destructor called to clear resources of this class
Destructor called to clear resources of this class
Destructor called to clear resources of this class
*/
