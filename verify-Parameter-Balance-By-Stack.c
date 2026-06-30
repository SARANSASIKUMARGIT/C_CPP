#include<stdio.h>
#include<stdbool.h>
#include<stdlib.h>
#include<string.h>

/* Saran SK */

//Node for storing the top Node and stack length
struct balancingStack
{
    struct node* topNode;
    int len;
};

//Node that stores data and memory address of next node
struct node
{
    char symbol;
    struct node* linkPtr;
};

struct balancingStack stack={NULL,0};      //Initializing the node

int checkBalanceofParanthesis(char symbol)  //Function to check whether the corresponding opening bracket is on the top of the stack
{
    if(stack.topNode==NULL)
        return 0;
    if(symbol==')' && (stack.topNode)->symbol=='(')
        return 1;
    if(symbol=='}' && (stack.topNode)->symbol=='{')
        return 1;
    if(symbol==']' && (stack.topNode)->symbol=='[')
        return 1;
    return 0;
}

void pushNode(char s)  //Function to push node to the top of the stack
{
    struct node *newNode = (struct node*)malloc(sizeof(struct node));
    newNode->symbol=s;
    stack.len++;
    if(stack.topNode==NULL)
    {
        stack.topNode=newNode;
        newNode->linkPtr=NULL;
        return;
    }
    newNode->linkPtr=stack.topNode;
    stack.topNode=newNode;
}

void popNode()      //Function to remove the top node of the stack
{
    if(stack.topNode==NULL)
        return ;
    struct node* tempNode=stack.topNode;
    stack.topNode=(stack.topNode)->linkPtr;
    free(tempNode);
}

void main()
{
    char buf[30],c;
    printf("Enter the expression to check it's balance : ");
    fgets(buf,sizeof(buf),stdin);       //Inputing the infix notation from user
    buf[strlen(buf)-1]='\0';
    for(int i=0;i<strlen(buf);++i)
    {       //Loop that traverse the infix string and check for balance of parameter
        c=buf[i];
        printf("%c ",c);
        if(c=='(' || c=='{' || c=='[')
        {
            pushNode(c);
        }
        else if(c=='}' || c==')' || c==']')
        {
            if(checkBalanceofParanthesis(c))
            {
                printf("Balanced \n");
                popNode();
            }
            else
            printf("UnBalanced \n");
        }
    }

    //Printing the result of Parameter Balance
    if(stack.topNode==NULL)
        printf("\n\t--- Expression Paranthesis is Balanced ---\n");
    else
        printf("\n\t--- Expression Paranthesis is UnBalanced ---\n");
}
