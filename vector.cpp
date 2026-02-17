#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
    int n,num;
    vector<int> arr;
    cout<<"Enter the size of the array : ";
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cout<<"Arr "<<i<<" : ";
        cin>>num;
        arr.push_back(num);
    }

    for(int i: arr)
    cout<<i<< " ";

}
