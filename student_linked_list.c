#include<stdio.h>
#include<stdlib.h>

struct student_list{
    int rank;
    char name[20];
    struct student_list *next;
};

void main()
{
    int n,c;
    printf("Enter the number of students : ");
    scanf("%d",&n);
    struct student_list *o=(struct student_list*)malloc(n*sizeof(struct student_list));
    struct student_list *temp=NULL;
    if(o==NULL)
    exit(0);
    for(int i=0;i<n;++i)
    {
        printf("Name %d : ",i);
        while((c=getchar())!=EOF && c!='\n');
        scanf("%[^\n]",(o+i)->name);
        printf("Rank %d :  ",i);
        scanf("%d",&((o+i)->rank));
        if(i != n-1)
        (o+i)->next=(o+i+1);
        else 
        (o+i)->next=NULL;
    }
    printf("----------------------------------------------------------\n");
    for(int i=0;i<n;++i)
    printf("%d %s ->",(o+i)->rank,(o+i)->name);
    printf("\n----------------------------------------------------------\n");

}
