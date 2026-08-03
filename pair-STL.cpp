#include<bits/stdc++.h>
using namespace std;

int main()
{
    int n,value;
    pair<int,int> twoDimensionalArray[n];
    cout<<"Enter the number of rows of the n*2 array : ";
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cout<<"Enter arr["<<i<<"]["<<0<<"] : ";
        cin>>value;
        twoDimensionalArray[i].first=value;
        cout<<"Enter arr["<<i<<"]["<<1<<"] : ";
        cin>>value;
        twoDimensionalArray[i].second=value;
    }

    cout<<"[ ";
    for(int i=0;i<n;++i)
    {
        cout<<"["<<twoDimensionalArray[i].first<<","<<twoDimensionalArray[i].second<<"] , ";
    }
    cout<<"]";

    return 0;
}


