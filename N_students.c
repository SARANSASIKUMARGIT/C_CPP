#include<stdio.h>
#include<stdlib.h>

typedef struct {    //defining the structure with alias "students"
    long reg_no;
    char *name,grade;
    int marks;
}students;

int main()
{
    int n;
    char c;
    printf("Enter the total number of students : ");
    scanf("%d",&n);                                         //getting the number of students
    students *s=(students*)malloc(n*sizeof(students));      //allocating memory for n blocks of struct "students"
    for(int i=0;i<n;++i)
    {                                                       //getting data from user for every student
        printf("Reg no %d : ",i+1);
        scanf("%ld",&((s+i)->reg_no));
        while(((c=getchar())!='\n')&&c!=EOF);
        (s+i)->name=(char*)malloc(20*sizeof(char));
        printf("Name %d : ",i+1);
        scanf("%[^\n]",(s+i)->name);
        while((c=getchar())!='\n'&&(c!=EOF));
        printf("Grade %d : ",i+1);
        scanf("%c",&((s+i)->grade));
        printf("Marks %d : ",i+1);
        scanf("%d",&((s+i)->marks));
    }

    for(int i=0;i<n;++i)
    {                                       //printing the data of each student's variable
        fprintf(stdout,"Reg No %d : %d\nName %d : %s\nGrade %d : %c\nMarks %d : %d\n",i+1,(s+i)->reg_no,i+1,(s+i)->name,i+1,(s+i)->grade,i+1,(s+i)->marks);
        printf("------------------------------------------------------------\n");
    }


    return 0;
}
