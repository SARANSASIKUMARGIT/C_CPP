#include<bits/stdc++.h>
using namespace std;

                /*    Saran SK     */
/*    
    A Pair is a Container in C++ that stores two elements of same or different data type. It is a Standard Template Library(STL) provided by C++ to provide developers with built-in methods,containers,objects for development of software easily,
    Syntax : pair<DataType1, DataType2> variableName;
    In this program , I've performed Two Dimensional Array Input and Output Operation by an Array of pair<int,int> DataType instead of a[][] approach.
*/

int main()
{
    int n,value;
    pair<int,int> twoDimensionalArray[100];             //Allocating 100 memory space for array at compile time and Type of Array = pair<int,int>
    cout<<"Enter the number of rows of the n*2 array : ";
    cin>>n;
    for(int i=0;i<n;++i)
    {
        cout<<"Enter arr["<<i<<"]["<<0<<"] : ";
        cin>>value;
        twoDimensionalArray[i].first=value;            //Assigning value to first element of the pair of i'th element of the array
        cout<<"Enter arr["<<i<<"]["<<1<<"] : ";
        cin>>value;
        twoDimensionalArray[i].second=value;           //Assigning value to second element of the pair of i'th element of the array
    }

    cout<<"[ ";
    for(int i=0;i<n;++i)                        //Printing the value of array of pair<int,int> by element by element by traversing the array
    {
        cout<<"["<<twoDimensionalArray[i].first<<","<<twoDimensionalArray[i].second<<"] , ";
    }
    cout<<"]";

    return 0;
}


