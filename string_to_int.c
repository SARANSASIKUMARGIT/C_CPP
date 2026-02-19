#include<stdio.h>  
#include<string.h> 
#include<stdlib.h> 
 
//program to convert char array (string) to integer

int char_to_int(char* str,int n)
{
    int num=0;
    for(int i=0;i<n;++i)
    {
        num*=10;
        num+=(int)(48-((int)*(str+i)));
    }
    return num;
}

void main()
{
    char str[10];
    printf("Enter the string : ");
    scanf("%[^\n]",str);
    printf("Int conversion of char array is : %d",char_to_int(str,strlen(str)));
    
}
