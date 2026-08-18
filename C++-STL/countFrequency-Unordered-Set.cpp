#include<bits/stdc++.h>
//#include<algorithm>     //contains declaration of find() method
using namespace std;

                /*    Saran SK     */

/*
    C++ Program to calculate the Frequency of each element in an array using Unordered Map (Hash Table),
    An Unordered Map does not sort elements based on key value, 
    it stores elements based only on the hash value of each key , by mapping the hash value of every key to it's calculated bucket index in the hash table,
    Bucket Index = hash(key) % Bucket_Count
*/


int main()
{
    int n;
    unordered_map<int,int> frequencyMap;                        //declare unordered_map<int,int> 
    cout<<"Enter the number of elements of the array : ";
    cin>>n;
    frequencyMap.reserve(n);                                    //reserving capacity for 'n' number of elements
    int *array = NULL;
    try{
        array=new int[n];                                      //allocating dynamic array at heap memory at runtime 
    }catch(bad_alloc &e)
    {
        //if exception occured
        cout<<"Memory allocation failed . Try Again "<<endl;
        return 1;
    }
    for(int i=0;i<n;++i)                            //inputing array element's value
    {
        cout<<"Enter Element "<<i<< " : ";
        cin>>array[i];
    }

    for(int i=0;i<n;++i)
        frequencyMap[array[i]]++;                   //incrementing the value of current element (key) in the map , if no key exist before the value is set to 0 by default

    for(const auto &m : frequencyMap)                   //get key-value pair as reference instead of copying it
        cout<< "Occurence of "<< m.first << " : " << m.second <<endl;               //printing the key-value(count) pair from the unordered_map by for each loop, by taking each pair one by one

    delete[] array;         //deallocating the dynamic array 


    return 0;
}


