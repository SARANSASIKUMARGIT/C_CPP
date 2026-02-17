#include<iostream>
#include<algorithm>
using namespace std;

bool compare(int a ,int b)  //custom comparison function 
{
    return(a<b);
}

int main()
{
    int arr[]={10,3,45,1,24,55,32,2};
    cout<<"Array Before Sort : ";
    for(int i : arr)                // for each loop for traversing elements in the array
    cout<<i<<" ";
    sort(arr,arr+8,compare);        //library function for sorting defined in <algorithm>
    cout<<"\n-----------------------------------"<<endl;
    cout<<"Array After Sort : ";
    for(int i : arr)    
    cout<<i<<" ";

}
