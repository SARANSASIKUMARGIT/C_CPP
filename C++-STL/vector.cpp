#include<iostream>
#include<vector>
#include<algorithm>     //contains declaration of find() method
using namespace std;

                /*    Saran SK     */

/*
    A Vector is a Dynamic Array which can grows or shrinks its capacity.
    It is implemented as an Template Class in C++ , it's definition are written in C++ Standard Template Library
    
    General Syntax :        
                vector<dataType> name;
*/

int main()
{
    vector<int> v1;             //declaring vector without any capacity (default capacity)
    vector<int> v2(5);          //declaring vector with capacity 5
    vector<int> v3(3,0);        //declaring vector with 3 elements of value 0 = {0,0,0}
    vector<int> v4={10,23,11,100,125};      //declaring vector with initializer list

    //displaying size and capacity of the vectors
    cout<<v1.size()<<" "<<v2.size()<<" "<<v3.size()<<" "<<endl;
    cout<<v1.capacity()<<" "<<v2.capacity()<<endl;;

    //pushing elements at the end of the vectors
    v1.push_back(10);
    v1.push_back(20);
    v2.push_back(11);
    v2.push_back(15);
    v3.push_back(11);
    v3.emplace_back(12);            //emplace_back() is similar to push_back() but instead constructs the object directly into the end of the vector,
                                    //  not creating a copy and adding it to the end of vector like push_back()

    //finding an element by find() method within the given range of iterators, returns iterator of the found element , if not found return end()
    auto it=find(v3.begin(),v3.end(),20);
    if(it==v3.end())
        cout<<"Element not found in vector 3"<<endl;
    else
        cout<<"Element found at vector 3"<<endl;

    it=find(v3.begin(),v3.end(),11);
    if(it==v3.end())
        cout<<"Element not found in vector 3"<<endl;
    else
        cout<<"Element found at vector 3";

    //erasing the elements in vector by value or by iterator of the element to be deleted (using find())
    v3.erase(v3.begin());
    //Safe erase , checks if searching element is present in the vector, if not found find() returns v2.end()
    auto findIterator=find(v2.begin(),v2.end(),11);
    if(findIterator!=v2.end())      //element to be deleted is found at the vector
        v2.erase(findIterator);

    //inserting elements at specified iterator position
    v2.insert(v2.begin()+1,100);
    v3.insert(v3.begin()+2,2,100);          //inserts value 100 to vector3 2 times at iterator positon v3.begin()+2 = 2

    //resizing the capacity of the vector
    v2.resize(20);
    cout<<"v2 capacity : "<<v2.capacity()<<endl;

    //displaying the vector by for loop from range v1.begin() to before v1.end()
    for(it=v1.begin();it!=v1.end();it++)
        cout<<*it<<" ";
    cout<<endl;

    //displaying the vector by const reference (read-only access, avoids copying the element from the vector as it is a reference variable)
    for(const auto &i : v2)
        cout<<i<<" ";               //here 'i' is an element of vector not an iterator so can print directly without dereferencing*
    cout<<endl;

    //displaying using for each loop
    for(auto it : v3)
        cout<<it<<" ";              //'it' is an integer variable , not an iterator , so no need to derefernce *
    cout<<endl;

    //check if vector3 is empty
    if(v3.empty())
        cout<<"v3 is empty "<<endl;
    else 
        cout<<"v3 is not empty , size : "<<v3.size()<<" capacity : "<<v3.capacity()<<endl;

    //clearing all the elements in the vector 
    v1.clear();
    v2.clear();
    v3.clear();
    //displaying the size and capacity of all the vectors after clearing their elements
    cout<<"Size after Clear : "<<v1.size()<<" "<<v2.size()<<" "<<v3.size()<<endl;
    cout<<"Capacity after Clear : "<<v1.capacity()<<" "<<v2.capacity()<<" "<<v3.capacity()<<endl;

    return 0;
}


