#include<iostream>
#include<algorithm>
using namespace std;

bool custom_comparitor(int a,int b) //custom comparitor function to pass as parameter to sort() to sort array of integers in descending order
{
    if(a>b)     
    return true;        //when a is greater than b no order is changed
    return false;       //if a is smaller than b the order is swapped
}

int main(/*Saran SK*/)
{
    int n,*arr;
    cout<<"Enter the number of elements to : ";
    cin>>n;
    arr=new int[n];
    for(int i=0;i<n;++i)
    {
        cout<<"Enter Element "<<i<<" : ";
        cin>>arr[i];
    }
    cout<<"Dynamic Array before Sorting : ";
    for(int i=0;i<n;++i)
    cout<<arr[i]<<"\t";
    sort(arr,arr+n,custom_comparitor);
    cout<<"\nDynamic Array after Sorting : ";
    for(int i=0;i<n;++i)
    cout<<arr[i]<<"\t";

    return 0;
}
