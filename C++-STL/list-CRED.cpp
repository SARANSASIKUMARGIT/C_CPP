#include<iostream>
#include<vector>
#include<algorithm>     //contains declaration of find() method
using namespace std;

                /*    Saran SK     */


int main()
{
    list< pair<int,string> > studentData;
    int n,num;
    string name;

    cout<<"Enter the number of students : ";
    cin >> n;
    for(int i=0;i<n;++i)
    {
        cout<<"Enter Student "<<i<<" ID   : ";
        cin>> num;
        cout<<"Enter Student "<<i<<" Name : ";
        cin>>name;
        studentData.push_back({num,name});              // student.emplace(num,name);   can also be used instead
    }

    int choice;
    do{
        cout<<"\t1. ADD\n\t2. SEARCH BY ID\n\t3. DELETE\n\t4. EXIT\n\tEnter your choice : ";
        cin>>choice;
        

    }while(choice!=4);
    

    return 0;
}


