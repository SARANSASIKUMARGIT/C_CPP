#include<stdio.h>
#include<stdlib.h>
#include<string.h>

void sort(int*,int,char*);      //Function declaration

void main()
{
    char choice_of_sorting[6];
    int n,*arr=NULL;
    printf("Enter the no of elements : ");
    scanf("%d",&n);
    arr=(int*)malloc(n*sizeof(int));        //dynamic memory allocation of n integer space in memory and returning the starting/base memory address to the pointer variable 
    if(arr==NULL){      //checking if Dynamic Memory Allocation Fails
    printf("Dynamic Memory Allocation Fails\n");
    exit(1);        //calls exit() method with value 1 to exit the program execution in runtime
    }
    for(int i=0;i<n;++i)
    {
        printf("Enter %d th element : ",i);      //Getting each element of array as input 
        scanf("%d",arr+i);
    }
    printf("\n\tEnter\n\tASC -Sorting in Ascending Order\n\tDESC - Sorting in Descending Order\n\tDefault Order is DESC if input is not ASC\n\tEnter : ");
    scanf("%s",choice_of_sorting);      //getting ASC or DESC
    sort(arr,n,choice_of_sorting);      //calling Custom Sort Method
    printf("Array after Sorting : ");
    for(int i=0;i<n;++i)
        printf("%d  ",*(arr+i));
    printf("\n");

}

void sort(int* arr,int n,char* asc_or_desc)
{
    int temp;
    switch(strcmp(asc_or_desc,"ASC")==0)        //evaluates to 1 when asc_or_desc == ASC
    {
        //Code for Ascending Order
        case 1:
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n-1;++j)
            {
                if(*(arr+j)>*(arr+j+1))
                {
                    temp=*(arr+j);
                    *(arr+j)=*(arr+j+1);
                    *(arr+j+1)=temp;
                }
            }
        }
        break;
        default:
        //Code for Descending Order
        for(int i=0;i<n;++i)
        {
            for(int j=0;j<n-1;++j)
            {
                if(*(arr+j)<*(arr+j+1))
                {
                    temp=*(arr+j);
                    *(arr+j)=*(arr+j+1);
                    *(arr+j+1)=temp;
                }
            }
        }
    }
}

