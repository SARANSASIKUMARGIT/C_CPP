#include<stdio.h>
#include<string.h>
#include<stdlib.h>     
             
struct char_linked_list{
    char c;
    struct char_linked_list *next;
};

void main()
{
    int n;
    printf("Enter the size of linked list : ");
    scanf("%d",&n);
    char string[n],palindrome_string[n];        //declaring two strings of length n
    struct char_linked_list *obj=(struct char_linked_list*)malloc(n*sizeof(struct char_linked_list)); //allocates memory for n linked list at runtime
    for(int i=0;i<n;++i)
    {
        getchar();
        printf("char %d : ",i);
        (obj+i)->c=getc(stdin);         //storing char in each linked list using getc() method from standard input stream
        (obj+i)->next=(i!=n-1)?(obj+i+1):NULL;
        string[i]=(obj+i)->c;
        palindrome_string[(n-1)-i]=(obj+i)->c;
    }
    string[n]=palindrome_string[n]='\0';//terminating the end of the string with an null terminator
    if(strcmp(string,palindrome_string)==0) //checks if palindrome or not true if strcmp() returns 0(equal)
    fprintf(stdout,"Linked list data is palindrome");
    else if(strcmp(string,palindrome_string)>0)//positve s1>s2
    fprintf(stdout,"String 1 is greater ..");
    else                                        //negative s1<s2
    fputs("String 2 is greater",stdout);
    
}
