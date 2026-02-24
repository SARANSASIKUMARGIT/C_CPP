#include<iostream>
using namespace std;

void call_by_reference(int &x, int y)
{
    x=x+100;            //changes made to x also impact in variable a , as x is an alias of varibale a (both a and x share same memory address)
    y=x+y+100;          //changes made to y does not impact the value of b , as the value of b is only copied to the formal parameter y
}

int main()
{
    int a,b;
    cout<<"Enter a : ";
    cin>>a;
    cout<<"Enter b : ";
    cin>>b;
    cout<<"Values before function call : "<<a<<" "<<b<<endl;
    call_by_reference(a,b); //here a is called by its reference (alias) and b is called by its value
    cout<<"Values after function call : "<<a<<" "<<b<<endl;

}
