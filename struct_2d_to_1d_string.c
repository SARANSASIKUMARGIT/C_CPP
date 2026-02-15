#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct double_pointer_string    //structure that stores 2d character array **double pointer of char type
{
    char **char_array;
    int len;
};

struct char_pointer         //structure that stores single char pointer from **double pointer 
{                           //from struct double_pointer_string
    char *char_array;
    int len;
};

void store_as_single_pointer(struct double_pointer_string *dp,struct char_pointer *cp,int len)
{
    //function that stores char* pointers from struct double_pointer_string to objects of char_pointer each
    for(int i=0;i<len;++i)
    {
        (cp+i)->char_array=(char*)malloc((strlen(*((dp->char_array)+i))*sizeof(char))+1);   //allocating size for the char* pointer 
        strcpy((cp+i)->char_array,*((dp->char_array)+i));
        (cp+i)->len=strlen((cp+i)->char_array);
    }
}

void output_single_pointers(struct char_pointer *cp,int len)
{
    for(int i=0;i<len;++i)
    {
        fprintf(stdout,"%s --> %d\n",(cp+i)->char_array,(cp+i)->len);     //outputing the data members of variables of output_single_pointers 
        printf("------------------------------------------------------------\n"); //to standard output stream
    }
}                                                            

void main()
{
    int double_len=0;
    char buffer[40],*double_string[10];
    struct double_pointer_string *dp_obj=NULL;
    struct char_pointer *cp_obj=NULL;
    FILE *file_pointer=fopen("student_copy.txt","r");               //opening the file to be read
    if(file_pointer==NULL)                                          //checks whether the file is not opened 
    {
        printf("Unable to open the file ....");
        exit(1);
    }
    while((fgets(buffer,sizeof(buffer),file_pointer))!=NULL)        //reading the lines of the file and copying to buffer string
    {
        buffer[strlen(buffer)-1]=(buffer[strlen(buffer)-1]=='\n')?'\0':buffer[strlen(buffer)-1];  //replacing the newline character at the end with null terminator
        double_string[double_len]=(char*)malloc(strlen(buffer)+1); //allocating memory for each pointer in the *char array
        strcpy(double_string[double_len++],buffer);                 //copying the content of buffer into i'th pointer in *char array
    }
    dp_obj=(struct double_pointer_string*)malloc(sizeof(struct double_pointer_string));//allocating memory for both double_pointer_string and char_pointer variables
    dp_obj->char_array=(char**)malloc(double_len*sizeof(char*));
    dp_obj->len=double_len;
    cp_obj=(struct char_pointer*)malloc(double_len*sizeof(struct char_pointer));
    for(int i=0;i<double_len;++i)
    {
        *((dp_obj->char_array)+i)=(char*)malloc((strlen(double_string[i])*sizeof(char))+1);//allocating memory for char* in char_pointer
        strcpy(*((dp_obj->char_array)+i),double_string[i]);                                //copying the i'th string to char* in i'th char_pointer
    }
    store_as_single_pointer(dp_obj,cp_obj,double_len);      //calling function to store single pointer from 2d array of pointer in double_pointer_string
    output_single_pointers(cp_obj,double_len);              //calling for outputing the data of members of each variables of struct char_pointer

    fclose(file_pointer);

}
