#include<stdio.h>
#include<string.h>
#include<stdlib.h>

struct Student
{
    int id;
    char name[30];
    float score;
};

void main(/*Saran SK*/)
{
    int n;
    struct Student *s=NULL;
    printf("Enter the number of students : ");
    scanf("%d",&n);
    s=(struct Student*)malloc(n*sizeof(struct Student));        //dynamic memory allocation of n number of struct 'Student' at runtime
    if(!s)
    {
        printf("Memory allocation failed .");
        exit(1);
    }
    for(int i=0;i<n;++i)        //Getting data from user for every Structure
    {
        printf("\nStudent %d : \n",i);
        printf("\tID  :  ");
        scanf("%d",&((s+i)->id));
        while(getchar()!='\n');
        printf("\tNAME  :  ");
        fgets((s+i)->name,sizeof((s+i)->name),stdin);
        (s+i)->name[strlen((s+i)->name)-1]=((s+i)->name[strlen((s+i)->name)-1]=='\n')?'\0':(s+i)->name[strlen((s+i)->name)-1];  //removing newline character \n at end if present
        printf("\tFLOAT  :  ");
        scanf("%f",&((s+i)->score));
    }

    //Opening a binary file to write
    FILE *binaryPointer=fopen("student.dat","wb");      
    if(!binaryPointer)      //if file opening failed
    {
        printf("Binary File opening failed ..");
        exit(1);
    }
    fwrite(s,sizeof(struct Student),n,binaryPointer);   //Writing the structure s (binary data) to the binary file pointed by binaryPointer
    fclose(binaryPointer);      //closing the binary file stream opened
    binaryPointer=NULL;

    //Reading the Binary file 
    binaryPointer=fopen("student.dat","rb");        //opening the binary file for reading
    if(!binaryPointer)          //if file opening failed
    {
        printf("Binary File Opening to read failed ..");
        exit(1);
    }
    struct Student s1[n]; //declaration 'n' number of structure Variables to read and store the data from the binary File
    fread(s1,sizeof(struct Student),n,binaryPointer);   //Reading from the binary file to the structure array s1, s1 represents the base address of the structure array
    for(int i=0;i<n;++i)
    {
        printf("\n\tID%d  :  %d,\n\tNAME  :  %s,\n\tSCORE  :  %f\n",i,s1[i].id,s1[i].name,s1[i].score); //Printing the data in the structure variable read from the binary file
    }
    


    
}

