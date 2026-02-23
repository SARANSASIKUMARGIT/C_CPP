#include<stdio.h>

int main()
{
    int file_len;
    FILE *file_pointer=fopen("student_details.txt","r");        //opening text file "student_details" in read mode
    if(file_pointer==NULL)                                      //check whether if file opening failed
    {
        printf("File cannot be opened .. error ");
        return 1;
    }
    fseek(file_pointer,0,SEEK_END);                             //moving the cursor to the end of the file pointer
    file_len=ftell(file_pointer);                               //getting the value of the current position of the cursor in the file pointer
    printf("The length of the file is : %d",file_len);          //displaying the lenght of the file stored in the variable in previous line
    fclose(file_pointer);                                       //closing the file pointer for preventing data leakage or some undefined behaviour
    return 0;
}
