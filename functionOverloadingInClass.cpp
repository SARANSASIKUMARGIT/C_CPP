#include<iostream>
using namespace std;

class Math
{
    //Function Overloading in Class in C++
    public:
    Math(){cout<<"Constructor Called \n";}
    void sum(int a,int b)
    {
        cout<<"Integer Sum : "<<a+b<<endl;
    }
    void sum(float a ,float b)
    {
        cout<<"Float Sum : "<<a+b<<endl;
    }
    void sum(float a,int b)
    {
        cout<<"Float+Int Sum : "<<a+b<<endl;
    }
    ~Math(){cout<<"Destructor Called\n";}
};

int main(/*Saran SK*/)
{
    Math o;
    o.sum(10,20);           //sum(int,int) called  'f' literal is used to denote the value is of type 'float'  
    o.sum(10.0f,20);        //sum(float,int) called
    o.sum(11.0f,19.0f);    //sum(float,float) called 

    return 0;
}

