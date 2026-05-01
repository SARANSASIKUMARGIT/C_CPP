#include<stdio.h>
#include<string.h>
#include<stdlib.h>

char* create_dynamic_reverse_string(char* str)    /* SARAN SK  */
{
    int len=0,i=0;
    while(*(str+len)!='\n'&&*(str+len)!='\n')++len; //calculating the length of the character array
    --len;
    char *dynamic_reverse_string=(char*)malloc((len+1)*sizeof(char));   //allocating dynamic memory at runtime
    if(dynamic_reverse_string==NULL)return NULL;        //return NULL if dynamic memory allocation fails..
    
    while(len>=0)
    {
        *(dynamic_reverse_string+i)=*(str+len);     //loop that assigns last character of original char array to first character of the reverse char array
        --len;++i;  
    }  
    *(dynamic_reverse_string+i)='\0'; //adding '\0' null terminator character at the end of the char array

    return dynamic_reverse_string;          //returning the memory of char array stored in char*
}

int main()
{
    char str[30],*str_rev=NULL;
    fprintf(stdout,"Enter the string : ");
    fgets(str,sizeof(str),stdin);       //inputing the full lenght string until enter is pressed
    str_rev=(char*)create_dynamic_reverse_string(str);      //returning the memory of reverse char array 
    fprintf(stdout,"The Reverse of %s is %s",str,str_rev);  //printing the reverse dynamic string value to output stream
    

    return 0;
}
