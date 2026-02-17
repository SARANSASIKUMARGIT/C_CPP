#include<stdio.h>   
#include<stdlib.h> 
             
void sort(int*,int);            //function declaration

void main()
{
    int n,*arr=NULL;
    printf("Enter the size of the array : ");
    scanf("%d",&n);                                 //get n as input
    arr=(int*)malloc(n*sizeof(int));                //allocates n int size memory at run time
    if(arr==NULL)
    {
        printf("Memory Allocation Failed ....");    //executes if dynamic allocation fails
        exit(1);
    }
    for(int i=0;i<n;++i)                            //array input
    {
        printf("arr %d : ",i);
        scanf("%d",arr+i);
    }
    printf("Array before sorting : ");
    for(int i=0;i<n;++i)
    printf("%d ",*(arr+i));
    sort(arr,n);                                    //calling sort() function for sorting the array
    printf("\nArray After sorting : ");
    for(int i=0;i<n;++i)
    printf("%d ",*(arr+i));
}

void sort(int* arr,int n)       //function definition
{
    int min,temp,min_index;
    for(int s_index=0;s_index<n;++s_index)      //from 0 to n
    {
        min=*(arr+s_index);                     //sets element at index s_index as minimum initially
        min_index=s_index;                      //sets min_index as s_index initially
        for(int j=s_index;j<n;++j)
        {
            if(min>*(arr+j))                    //checks if j'th element of arr is less than min value
            {
                min=*(arr+j);                   //if so then assign min=value of j'th element of arr
                min_index=j;                    //set minimum index as current j
            }
        }
        temp=*(arr+s_index);                    //swap the current s_index element to the element at index min_index
        *(arr+s_index)=*(arr+min_index);
        *(arr+min_index)=temp;
    }
}
