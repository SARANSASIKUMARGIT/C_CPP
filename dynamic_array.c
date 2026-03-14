#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

int main()
{
    //C program to allocate memory for array in runtime using malloc
    int *arr=NULL,n,large,*base_address=NULL;
    printf("Enter the size of the integer array : ");
    scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));
    base_address=arr;               //storing the base address of the allocated memory block
    for(int i=0;i<n;++i)
    {
        printf("Element %d : ",i);
        scanf("%d",arr++);          //inputing the value of each block using memory address of that block using pointer arithemetic
    }

    for(int i=0;i<n;++i)
    printf("%d  ",*base_address++); //displaying the values of each memory block from deferencing the memory address of the array from its base address


    return 0;
}
