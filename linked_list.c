#include<stdio.h>
#include<stdlib.h>

struct linked_list{
    int data;
    struct linked_list *next;
};

void main()
{
    int n;
    printf("Enter the number of nodes : ");
    scanf("%d",&n);
    struct linked_list *obj=(struct linked_list*)malloc(n*sizeof(struct linked_list));
    if(obj==NULL)
    {
        printf("Memory allocation failed ...");
        exit(0);
    }
    for(int i=0;i<n;++i)
    {
        printf("Data %d : ",i);
        scanf("%d",&((obj+i)->data));
        if(i !=n-1)
        (obj+i)->next=(obj+i+1);
        else
        (obj+i)->next=NULL;
    }
    printf("\n---------------------------\n");
    for(int i=0;i<n;++i)    
    printf("%d -> ",(obj+i)->data);
    printf("\n---------------------------\n");
}
