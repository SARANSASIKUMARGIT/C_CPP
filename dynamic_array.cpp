#include<iostream>
using namespace std;

int main()
{
    //dynamic memory allocation of array in C++
    int *arr=nullptr,n;
    cout<<"Enter the Array Size : ";
    cin>>n;
    arr=new int[n];         //allocating n memory space of integer in runtime
    for(int i=0;i<n;++i)
    {
        cout<<"Element "<<i<<" : ";
        cin>>arr[i];            //getting the array element's value as input 
    }

    for(int i=0;i<n;++i)
    cout<<arr[i]<<"  ";         //displaying the array value to the output stream

    delete[] arr;               //deallocating the memory allocated by new int[n];
    arr=nullptr;                //reassign integer pointer arr as nullptr (null pointer)

    return 0;
}

