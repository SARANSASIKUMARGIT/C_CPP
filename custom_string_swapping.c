#include<stdio.h>
#include<string.h>

int string_length(char* s)      //custom method to count the length of a string
{
    int l=0;
    while(*(s+l)!='\n'&&*(s+l)!='\0')
        ++l;
    return l;
}

void swap(char *s1,char *s2)            //custom method to swap two strings
{
    int l1=string_length(s1),l2=string_length(s2),index;
    char temp;
    if(l1>l2)               //checking if length of string1 > string2
    {
        index=l1;
        for(int i=l2;i<=l1;++i)     //assingning \0 to each byte of smaller string2 at the end to avoid undefined behaviour during swap operation
            *(s2+i)='\0';
    }
    else                    //checking if length of string2 > string1
    {
        index=l2;
        for(int i=l1;i<=l2;++i)     //assingning \0 to each byte of smaller string1 at the end to avoid undefined behaviour during swap operation
            *(s1+i)='\0';
    }
    //swapping of two character array until the index = lenght of string with greater size 
    for(int i=0;i<=index;++i)
    {
        temp=*(s1+i);
        *(s1+i)=*(s2+i);
        *(s2+i)=temp;
    }
}

void main(/*Saran SK*/)
{
    char string1[30],string2[30];
    printf("Enter the string 1 : ");
    fgets(string1,sizeof(string1),stdin);
    printf("Enter the string 2 : ");
    fgets(string2,sizeof(string2),stdin);
    string1[strlen(string1)-1]=string2[strlen(string2)-1]='\0';         //assign '\0' to end of the string as it would be '\n' as we input the string by fgets()
    printf("Before Swap : \ns1 : %s\ts2 : %s\n",string1,string2);
    swap(string1,string2);                                      //calling swap method with two strings as arguments
    printf("After Swap : \ns1 : %s\ts2 : %s\n",string1,string2);
    
}

