#include<iostream>
using namespace std;
//C++ program to count vowels in a string by iterating the characters in a string by a character pointer 
int main()
{
    int c=0;
    string s;
    char *char_ptr=nullptr;
    cout<<"Enter the string : ";
    cin>>s;
    char_ptr=&s[0];             //char_ptr (char*) pointing the memory of first character of string 's' at index 0
    while(*char_ptr!='\0')
    {
        if(*char_ptr=='A'||*char_ptr=='a'||*char_ptr=='E'||*char_ptr=='e'||*char_ptr=='I'||*char_ptr=='i'||*char_ptr=='O'||*char_ptr=='o'||*char_ptr=='U'||*char_ptr=='u')
        c++;
        char_ptr++;
    }

    cout<<"Number of Vowels in "<<s<<" : "<<c<<endl;

    printf("Remaining character in input buffer : ");   //if any remaining characters exist in the input buffer
    while((c=getchar())!=EOF && c!='\n')
    putchar(c);                                        //display characters present in the input buffer

    return 0;
}

