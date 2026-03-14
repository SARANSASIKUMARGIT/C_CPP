#include<stdio.h>
#include<string.h>
#include<stdlib.h>

int main()
{
    //C program to count number of vowels in a string (character array)
    int string_len,c=0;
    char str[20];
    printf("Enter the string : ");
    scanf("%[^\n]",str);        //getting the string as input until a newline character (for including space in the string)
    for(int i=0;i<strlen(str);++i)
    {
        //checking if a character in a sting is an vowel if so increments the value of variable 'c' by 1
        if(str[i]=='A'||str[i]=='a'||str[i]=='E'||str[i]=='e'||str[i]=='I'||str[i]=='i'||str[i]=='O'||str[i]=='o'||str[i]=='U'||str[i]=='u')
        c++;
    }
    fprintf(stdout,"Vowels Count in %s is %d ",str,c); //equivalent to printf()
    

    return 0;
}
