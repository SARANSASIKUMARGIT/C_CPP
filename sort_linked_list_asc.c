#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

struct student_list{
    int rank;
    char name[20];
    struct student_list *next;
};  //student linked list node 

void main()
{
    int n,c,min=0;
    bool head_flag=false;
    printf("Enter the number of students : ");
    scanf("%d",&n);
    struct student_list *o=(struct student_list*)malloc(n*sizeof(struct student_list)); //dynamic allocation of nodes of linked list
    struct student_list *curr,*next,*prev,*head;
    curr=next=prev=head=NULL;
    if(o==NULL)
    exit(0);
    for(int i=0;i<n;++i)
    {
        // printf("Name %d : ",i);
        while((c=getchar())!=EOF && c!='\n'); //clearing input buffer for ignoring garbage storage in string 
        // scanf("%[^\n]",(o+i)->name);    //storing characters until a newline \n character in the input buffer (for geting string contains spaces)
        printf("Rank %d :  ",i);
        scanf("%d",&((o+i)->rank));
        (o+i)->next=(i != n-1)?(o+i+1):NULL;  //assigning NULL value to the last node in the linked list
    }
    curr=head=(o);  //assigning address of first structure (o+0) to curr & head structure pointer
    for(int i=0;i<n;++i)
    {
        curr=head;  
        while(curr->next!=NULL)
        {
            if(curr->rank > (curr->next)->rank) //comparing if curr rank > next rank
            {
                next=curr->next;        //manipulating pointing of linked list based on the node value when swapped
                curr->next=(curr->next)->next;
                next->next=curr;
                if(prev==NULL)
                prev=next;
                else
                {
                    prev->next=next;
                    prev=prev->next;
                }
                if(!head_flag)
                {
                    head_flag=true;     
                    head=next;      //to know and store the linked list at which the operation need to be started again from next for loop iteration
                }
            }
            else                    //else block if no swap needed
            {
                if(prev==NULL)
                prev=curr;
                else
                {
                    prev=prev->next;        //moving the previous pointer to the next linking node
                }
                if(!head_flag)
                {
                    head_flag=true;
                    head=curr;
                }
                curr=curr->next;        //moving the current node to node
            }
        }
        head_flag=false;        //reset head_flag to save the start node again in next iteration of while loop
        prev=NULL;              //reset prev value as NULL to store as the iteration starts from the first node (head)
    }

    printf("Sorted Linked List");
    printf("\n-------------------------------------------------------\n");
    while(head!=NULL)
    {
        printf("%d -> ",head->rank);    //printing the sorted linked list from head and moving until NULL is found 
        head=head->next;                //moving to the next linked list
    }
    printf("\n-------------------------------------------------------\n");

}
