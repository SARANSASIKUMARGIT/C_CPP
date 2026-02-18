#include<stdio.h>   
#include<stdlib.h> 
 
struct student{                             //struct student
    int rollno,rank,marks;
    char name[20];
};

int compare(const void* a,const void* b)     //custom comparison function that swaps the order of object if mark a < mark b
{
    if((((struct student*)a)->marks)>(((struct student*)b)->marks)) //typecasting the void* to type student* then deferencing the member 'marks'
    return 0;
    else return 1;       //swaps the order if mark current < mark next
};

void main()
{
    int n,c;
    struct student *obj=NULL;
    printf("Enter the number of students : ");
    scanf("%d",&n);
    obj=(struct student*)malloc(n*sizeof(struct student));//dynamic memory allocation for n blocks of student objects
    if(obj==NULL)
    {
        printf("Memory Allocation Failed ...");
        exit(1);
    }
    for(int i=0;i<n;++i)                    //getting data input from user for each struct student variable
    {
        printf("------------------------------------\n");
        printf("Roll No %d : ",i);
        scanf("%d",&((obj+i)->rollno));
        while( c=getchar()!='\n' && c!=EOF);
        printf("Name %d : ",i);
        scanf("%[^\n]",((obj+i)->name));
        printf("Marks %d : ",i);
        scanf("%d",&((obj+i)->marks));
        printf("------------------------------------\n");
    }
    qsort(obj,n,sizeof(struct student),compare);        //passing the base address of student pointer to swap the structure variable 
    printf("Ranking of Students : \n");                 //by customer comparison function
    for(int i=0;i<n;++i)
    {
        (obj+i)->rank=i+1;
        //displaying the result by ranking (asc)
        printf("%d. %d\t%s\t%d\n",(obj+i)->rank,(obj+i)->rollno,(obj+i)->name,(obj+i)->marks);
    }
    
}
