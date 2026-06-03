//Singly LinkedList Program in C
#include<stdio.h>
#include<stdlib.h>

struct node{
    int value;
    struct node* nextptr;
};
struct node* start=NULL;
struct node* end=NULL;

void push_front()
{
    int n;
    printf("Enter the value of the node : ");
    scanf("%d",&n);
    if(start==NULL && end==NULL)
    {
        start=end=(struct node*)malloc(sizeof(struct node));
        start->value=end->value=n;
        start->nextptr=end->nextptr=NULL;
    }
    else{
        struct node* temp_start=start;
        start=(struct node*)malloc(sizeof(struct node));
        start->value=n;
        start->nextptr=temp_start;
    }
    
}

void push_back()
{
    int n;
    printf("Enter the value of node : ");
    scanf("%d",&n);
    if(start==NULL && end==NULL)
    {
        start=end=(struct node*)malloc(sizeof(struct node));
        start->value=end->value=n;
        start->nextptr=end->nextptr=NULL;
    }
    else if(start==end)
    {
        end=(struct node*)malloc(sizeof(struct node));
        start->nextptr=end;
        end->value=n;
        end->nextptr=NULL;
    }
    else
    {
        struct node* temp=end;
        end=(struct node*)malloc(sizeof(struct node));
        end->value=n;
        end->nextptr=NULL;
        temp->nextptr=end;
    }
}

void delete_node()
{
    int n;
    printf("Enter the value to delete : ");
    scanf("%d",&n);
    if(start->value==n)
        start=start->nextptr;
    else{
    struct node* temp=start;
        while(temp->nextptr!=NULL)
        {
            if((temp->nextptr)->value==n)
            {
                temp->nextptr=(temp->nextptr)->nextptr;
                break;
            }    
            temp=temp->nextptr;
        }
    }
}

void print_nodes()
{
    struct node* n=start;
    while(n!=NULL)
    {
        printf("%d -> ",n->value);
        n=n->nextptr;
    }
}

void main()
{
    int ch,n;
    do{
    printf("\t1.Push_Front\n\t2.Push_Back\n\t3.Delete_value\n\t4.Print Value\n\t5.Exit\n\tEnter your choice : ");
    scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                push_front();
                break;
            case 2:
                push_back();
                break;    
            case 3:
                delete_node();
                break;    
            case 4: 
                print_nodes();
                break;
            default:
                break;    
        }
    }while(ch!=5);
    
}
