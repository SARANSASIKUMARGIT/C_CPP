//Two Dimensional Array using Pointers in C
#include<stdio.h>
#include<stdlib.h>

void main()
{
    int row,column,**matrix=NULL,**tmatrix=NULL;
    printf("Enter the number of rows : ");
    scanf("%d",&row);
    printf("Enter the number of columns : ");
    scanf("%d",&column);
    matrix=(int**)malloc(row*sizeof(int*));
    if(matrix==NULL)
    {
        printf("Matrix Row Memory Allocation Failed..\n");;
        exit(1);
    }
    for(int i=0;i<row;++i)
    {
        *(matrix+i)=(int*)malloc(column*sizeof(int));
        if(*(matrix+i)==NULL)
        {
            printf("Matrix Column Allocation Failed...");
            exit(1);
        }
    }
    for(int i=0;i<row;++i)
        for(int j=0;j<column;++j)
        {
            printf("[%d][%d] : ",i,j);
            scanf("%d",*(matrix+i)+j);
        }
        
    for(int i=0;i<row;++i)
    {
        for(int j=0;j<column;++j)
        printf("%d  ",*(*(matrix+i)+j));
        printf("\n");
    }
    //Create Transpose Matrix
    tmatrix=(int**)malloc(column*sizeof(int*));
    if(tmatrix==NULL)
    {
        printf("Transpose Matrix Row Memory Allocation Failed ..");;
        exit(1);
    }
    for(int i=0;i<column;++i)
    {
        *(tmatrix+i)=(int*)malloc(row*sizeof(int));
        if(tmatrix[i]==NULL)
        {
            printf("Transpose Matrix Column Memory Allocation Failed ..");
            exit(1);
        }
    }
    //Transpose Original Matrix by assigning its value to new matrix
    for(int i=0;i<row;++i)
        for(int j=0;j<column;++j)
            *(*(tmatrix+j)+i)=*(*(matrix+i)+j);
    //Displaying the Transpose Matrix
    printf("\n");
    for(int i=0;i<column;++i)
    {
        for(int j=0;j<row;++j)
        printf("%d  ",*(*(tmatrix+i)+j));
        printf("\n");
    }       
    
    exit(1);
    
}
