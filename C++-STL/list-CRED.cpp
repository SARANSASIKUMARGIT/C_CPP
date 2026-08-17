#include<iostream>
//#include<bits/stdc++.h>
#include<vector>
#include<list>
#include<algorithm>     //contains declaration of find() method
using namespace std;

                /*    Saran SK     */

/*
    List is a Sequence Container in C++ STL where the elements are arranged in the order they are inserted.
    Internally , List is a Doubly Linked List. The only difference between vector and list
    List container do not have find() as it's member function , but 
    find() method can be used from the <algorithm> library,
    Associative Containers have find() as their member function but Sequence Containers should use find() from <algorithm> library,
    List do not support random accessing because it is not a contiguous memory like vector,array

    Time Complexity : O(1) for erase and insertion if iterator is known, O(N) for insertion at middle of the list if iterator not known,
                      O(N) for accessing an element in average case if iterator not known,
                      O(1) for insertion at front and end
                      But to find the iterator of an element the time complexity for average case is O(N)
*/


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
        cin.ignore();           //clearing input buffer before inputing a new string 
        getline(cin,name);
        studentData.push_back({num,name});              // student.emplace(num,name);   can also be used instead
    }

    int choice;
    do{
        cout<<"\t1. ADD\n\t2. SEARCH BY ID\n\t3. DELETE\n\t4. PRINT RECORDS\n\t5. EXIT\n\tEnter your choice : ";
        cin>>choice;
        auto it = studentData.begin();              // fixed
        switch(choice)
        {
            case 1:
                cout<<"Enter Student ID to add       : ";
                cin>>num;
                cout<<"Enter the name of the student : ";
                cin.ignore();                   //clearing input buffer
                getline(cin,name);
                studentData.emplace_back(num,name);         //constructing the object directly into the list instead of creating a copy and pushing into the list
                break;
            case 2:
                cout<<"Enter the student ID to find : ";
                cin>>num;
                it = studentData.begin();
                for(it=studentData.begin(); it != studentData.end(); ++it)              //traversing the list from begin() to one place before the end() iterator
                {
                    if((*it).first==num)
                    {
                        cout<<"Student Found \n";
                        cout<<"Student ID   : "<<(*it).first<<endl;                 //dereferencing the iterator and accessing the first and second value of the pair<int,string> container
                        cout<<"Student Name : "<<(*it).second<<endl;
                        break;
                    }
                }
                if(it==studentData.end())
                    cout<<"Student Not Found "<<endl;
                break;
            case 3:
                cout<<"Enter the Student ID to delete : ";
                cin>>num;
                it = find_if(studentData.begin(),studentData.end(), [num](const pair<int,string> &p){ return num==p.first;});          // find the element in list 'studentData' where the first == num (key to search)
                if(it!=studentData.end())
                {
                    studentData.erase(it);              //if iterator found , then erase the element by passing the iterator of the element to be removed/erased
                    cout<<"Student Deleted Successfully\n";
                }
                else
                    cout<<"Student Not Found\n";
                break;
            case 4:
                for(auto a : studentData)                           //for each loop for displaying all pairs in the list<pair<int,string>>
                    cout<<a.first << " " << a.second <<endl;
                break;
            case 5:
                 cout<<"Thank You\n";
                 break;
            default:
                cout<<"Please enter a valid choice "<<endl;
        }


    }while(choice!=5);
    

    return 0;
}


