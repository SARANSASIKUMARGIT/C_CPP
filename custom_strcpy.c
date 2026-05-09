#include<stdio.h>
#include<stdlib.h>

int custom_strlen(char*);               //Function Declaration
char* custom_strcpy(char**,char*);

void main(/*Saran SK*/)
{
    char *dest,source[30];
    printf("Enter the Source String : ");
    fgets(source,sizeof(source),stdin);             //Gets the Source String
    printf("String Length : %d\nCopy Status of the String : %s\n",custom_strlen(source),custom_strcpy(&dest,source));   //calls custom strlen & strcpy function
    fprintf(stdout,"Destination String : %s\n",dest);       //prints the destination char array that is copied from source using custom_strcpy() function
}

char* custom_strcpy(char** destination,char* source)        //definiton of custom string copy function
{
    int count=0;
    *destination=(char*)malloc((++count)*sizeof(char));
    if(destination==NULL)
        return "FAILURE";           //return "FAILURE" if function couldn't copy source to destination
    while(*(source+(count-1))!='\0'&&*(source+(count-1))!='\n')
    {
        *(*(destination)+(count-1))=*(source+(count-1));
        *destination=(char*)realloc(*destination,(++count)*sizeof(char));       //reallocation the destination for even more 1 character space dynamically
        if(*destination==NULL)
            return "FAILURE";       //returns "FAILURE" if dynamic reallocation fails.
    }
    *(*destination +(count-1))='\0';

    return "SUCCESS";           //return "SUCCESS" if function successfully copied source to destination
}

int custom_strlen(char* str)        //definiton of custom string length function
{
    int l=0;
    while(*(str+l)!='\0'&&*(str+l)!='\n')++l;       //calculate string length using loop
    return l;
}
