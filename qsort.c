#include<stdio.h>
#include<string.h>
#include<stdlib.h>      //qsort() is declared inside <stdlib.h> header

int compare(const void* a,const void* b)    //custom function compare that is called for sorting by user given criteria
{
    if(*((char*)a)>*((char*)b))     //if a custom comparison fucntion returns a positive value then swap occurs on the char array
    return 1;   //+ve value swap occurs
    else
    return -1;//-ve value no changes on the target pointer or array
}                                             

void main()
{
   int n;
   char char_array[30];
   printf("Enter the string : ");
   scanf("%30[^\n]",char_array);
   n=strlen(char_array);
   qsort(char_array,n,sizeof(char),compare);    //the address of the compare fucntion is passed as arguments as the formal parameter is a function pointer
   fputs(char_array,stdout);                //outputing the string to the standard output using fputs() in standard output file stream

}
