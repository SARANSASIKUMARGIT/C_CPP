#include<iostream>
using namespace std;

int& reference(int &a,int b)        //function that returns the reference(address) of a variable
{
    a=a*b;
    return a;
}

int main()
{
    int a,b,c;
    cin>>a>>b;
    cout<<"Before Reference Call A : "<<a<<" B : "<<b<<endl;
    reference(a,b)=100;
    cout<<"After Reference Call A : "<<a<<" B : "<<b<<endl;


    return 0;
}

