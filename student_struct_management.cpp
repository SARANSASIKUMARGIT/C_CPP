#include<iostream>
using namespace std;

//Student Data Management Program using Structure 
//Dynamic Memory allocation in C++

struct Student  //Defining the Structure
{
    int regno,no_of_subjects,*marks;
    string name;
    float cgpa;
};

int main(/*Saran SK*/)
{
    int n;
    struct Student *s=NULL;
    cout<<"Enter the total number of students : ";
    cin>>n;
    s=new struct Student[n];            //Dynamic Memory allocation of 'n' Structure Student
    if(s==NULL)
    {
        cout<<"Dynamic Memory Allocation Failed\n";
        exit(1);                        //terminating the program with 1 return value on dynamic memory allocation failure
    }
    for(int i=0;i<n;++i)
    {
        //Getting Details of every Student from user
        cout<<"REGNO "<<i+1<<" : ";     
        cin>>(s+i)->regno;
        cout<<"NAME "<<i+1<<" : ";
        cin>>(s+i)->name;
        cout<<"CGPA "<<i+1<<" : ";
        cin>>(s+i)->cgpa;
        cout<<"No of Subjects for Student "<<i+1<<" : ";
        cin>>(s+i)->no_of_subjects;
        (s+i)->marks=new int[(s+i)->no_of_subjects];        //dynamic memory allocation of 'no_of_subjects' integers for marks of each student
        for(int j=0;j<(s+i)->no_of_subjects;++j)
        {
            cout<<"\tMark "<<j<<" of Student "<<i+1<<" : ";
            cin>>*(((s+i)->marks)+j);                       //inputing each mark of the student and store in the heap memory allocated
        }
    }

    for(int i=0;i<n;++i)
    {
        //Displaying the Details of Every Student 
        cout<<"\n--------------------------------------------------------------\n";
        cout<<"REGNO "<<i+1<<" : "<<(s+i)->regno<<endl;
        cout<<"NAME "<<i+1<<" : "<<(s+i)->name<<endl;
        cout<<"CGPA "<<i+1<<" : "<<(s+i)->cgpa<<endl;
        cout<<"No of Subjects for Student "<<i+1<<" : "<<(s+i)->no_of_subjects<<endl;
        for(int j=0;j<(s+i)->no_of_subjects;++j)
            cout<<"\tMark "<<j<<" of Student "<<i+1<<" : "<<*(((s+i)->marks)+j);
    }


    return 0;
}

