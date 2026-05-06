#include<stdio.h>
#include<stdlib.h>
#include<string.h>

int count_length(char*); //program to calculate the length of the string using pointer *

void main(/* Saran SK */)
{
    char buf[30];
    printf("Enter the String to find its length : ");
    fgets(buf,sizeof(buf),stdin);
    printf("Length of %s = %d\n",buf,count_length(buf));
}

int count_length(char* str)
{
    int len=0;
    while(*(str+len)!='\0'&&*(str+len)!='\n')
        ++len;
    return len;
}
