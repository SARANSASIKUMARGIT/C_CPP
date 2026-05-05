#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>

#define FILE_NAME "student_details.txt"    //FILE NAME MACRO
bool isRecordLoaded=false;
int count=0;
struct Student{
    int id;
    char name[20];
    float cgpa;
};

struct Student *records=NULL;

void read();  //function to read files from the file
void search();  //function to search records from the file
void add();    //function to add record to the file
void edit();    //function to edit the existing record of the file
void loadRecord2Struct();  //function to store the data of each line into the structure
void showStruct();    //To display the data stored in the structure

void main(/*Saran SK*/)
{
    int ch;
    do{
        printf("\n\t1.List Records\n\t2.Add Record\n\t3.Search Record\n\t4.Edit Record\n\t5.Exit\n\tEnter your Choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                read();
                break;
            case 2:
                add();
                break;
            case 3:
                search();
                break;
            case 4:
                edit();
                // loadRecord2Struct();
    //             for(int i=0;i<count;++i)
    // printf("%d--%s--%f\n",(records+i)->id,(records+i)->name,(records+i)->cgpa);
                break;
            case 5:
                break;
            default:
                printf("Enter a valid choice\n");
        }
        printf("ch == %d",ch);
    }while(ch!=5);
    if(records)
    free(records);
}

void saveChanges2File()
{
    FILE* fp=fopen(FILE_NAME,"w");
    for(int i=0;i<count;++i)
        fprintf(fp,"%d,%s,%f\n",(records+i)->id,(records+i)->name,(records+i)->cgpa);
    fclose(fp);
}

void loadRecord2Struct()
{
    int temp_id;
    char temp_name[20];
    float temp_cgpa;
    FILE *fp=fopen(FILE_NAME,"r");
    if(fp==NULL)
    {
        printf("File Opening Failed..\n");
        return;
    }
    while(fscanf(fp,"%d,%[^,],%f\n",&temp_id,temp_name,&temp_cgpa)==3)
    {
        if(!isRecordLoaded)
        {
        records=(struct Student*)malloc((++count)*sizeof(struct Student));
        isRecordLoaded=true; 
        }
        else
        records=(struct Student*)realloc(records,(++count)*sizeof(struct Student));   
        (records+(count-1))->id=temp_id;
        (records+(count-1))->cgpa=temp_cgpa;
        strcpy((records+(count-1))->name,temp_name);    
    }
    // for(int i=0;i<count;++i)
    // printf("%d--%s--%f\n",(records+i)->id,(records+i)->name,(records+i)->cgpa);
    fclose(fp);
}

void showStruct()
{
    for(int i=0;i<count;++i)
    printf("%d--%s--%f\n",(records+i)->id,(records+i)->name,(records+i)->cgpa);
}

void edit()
{
    int ch,target_id,index=-1;
    char temp_name[20];
    float temp_cgpa;
    if(!isRecordLoaded)
    loadRecord2Struct();
    printf("------------------------------------------------\n");
    showStruct();
    printf("------------------------------------------------\n");
    printf("Enter the ID of the record to be edit : ");
    scanf("%d",&target_id);
    for(int i=0;i<count;++i)
    {
        if(((records+i)->id)==target_id)
        {
            index=i;
            break;
        }
    }
    if(index!= -1)
    {
        printf("%d,%s,%f\n",(records+index)->id,(records+index)->name,(records+index)->cgpa);
        printf("\n\t1.ID\n\t2.Name\n\t3.CGPA\n\tWhat do you want to edit : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
                printf("Enter the new ID : ");
                scanf("%d",&target_id);
                (records+index)->id=target_id;
                printf("Updated Successfully\n");
            break;
            case 2:
                printf("Enter the new Name : ");
                while((ch=getchar())!=EOF && ch!='\n');
                fgets(temp_name,sizeof(temp_name),stdin);
                temp_name[strlen(temp_name)-1]='\0';
                strcpy((records+index)->name,temp_name);
                printf("Updated Successfully\n");
            break;
            case 3:
                printf("Enter the new CGPA : ");
                scanf("%f",&temp_cgpa);
                (records+index)->cgpa=temp_cgpa;
                printf("Updated Successfully\n");
            break;
            default:
                printf("Invalid Choice ..\n");
        }
        saveChanges2File();
    }
    else 
        printf("Record with ID %d not found ...\n",target_id);
}

void search()
{
    int ch,temp_id,target_id,buf_clear;
    bool isFound=false;
    char temp_name[20],target_name[20];
    float temp_cgpa,target_cgpa;
    FILE* fp=fopen(FILE_NAME,"r");
    do{
        printf("Search by \n\t1.Id\n\t2.Name\n\t3.GPA\n\tEnter your Choice : ");
        scanf("%d",&ch);
        switch(ch)
        {
            case 1:
            printf("Enter ID to Search : ");
            while((ch=getchar())!=EOF&&ch!='\n');
            scanf("%d",&target_id);
            while(fscanf(fp,"%d,%20[^,],%f\n",&temp_id,temp_name,&temp_cgpa)==3)
            {
                if(temp_id==target_id)
                {
                    printf("\n%d,%s,%f\n",temp_id,temp_name,temp_cgpa);
                    isFound=true;
                    break;
                }
            }
            printf("%s",(isFound)?"Search Found..\n":"Search Not Found..\n");
            isFound=false;
            fclose(fp);
            break;
            case 2:
            printf("Enter the Name to Search : ");
            while((buf_clear=getchar())!=EOF && buf_clear!='\n');
            fgets(target_name,sizeof(target_name),stdin);
            target_name[strlen(target_name)-1]='\0';
            while(fscanf(fp,"%d,%[^,],%f\n",&temp_id,temp_name,&temp_cgpa)==3)
            {
                if(strcmp(temp_name,target_name)==0)
                {
                    isFound=true;
                    printf("\n%d,%s,%f\n",temp_id,temp_name,temp_cgpa);
                    break;
                }
            }
            printf("%s",(isFound)?"Search Found..\n":"Search Not Found..\n");
            isFound=false;
            fclose(fp);
            break;
            case 3:
            printf("Enter the CGPA to search : ");
            scanf("%f",&target_cgpa);
            while(fscanf(fp,"%d,%[^,],%f\n",&temp_id,temp_name,&temp_cgpa)==3)
            {
                if(temp_cgpa==target_cgpa)
                {
                    isFound=true;
                    printf("\n%d,%s,%f\n",temp_id,temp_name,temp_cgpa);
                    break;
                }
            }
            printf("%s",(isFound)?"Search Found..\n":"Search Not Found..\n");
            isFound=false;
            fclose(fp);
            default:
            break;
        }
    }while(ch!=1&&ch!=2&&ch!=3);
    fclose(fp);
}

void read()
{
    char buf[40];
    FILE* fp=fopen(FILE_NAME,"r");
    count=0;
    if(fp==NULL)
    {
        printf("File Opening Failed ..\n");
        return;
    }
    while(fgets(buf,sizeof(buf),fp)!=NULL){
    fprintf(stdout,"%s",buf);
    ++count;
    }
    fclose(fp);
}

void add()
{
    int ch,temp_id;
    char temp_name[20];
    float temp_gpa;
    if(!isRecordLoaded)
    loadRecord2Struct();
    FILE* fp=fopen(FILE_NAME,"a");
    printf("Enter the ID : ");
    scanf("%d",&temp_id);
    while((ch=getchar())!=EOF&&ch!='\n');
    printf("Enter the Name : ");
    fgets(temp_name,sizeof(temp_name),stdin);
    printf("Enter the CGPA : ");
    scanf("%f",&temp_gpa);
    temp_name[strlen(temp_name)-1]='\0';
    printf("ch now = %d\n",ch);
    ch = fprintf(fp,"\n%d,%s,%.2f",temp_id,temp_name,temp_gpa);
    if(ch>0)
    {
    printf("Record Added Succesfully\n");
    records=(struct Student*)realloc(records,(++count)*sizeof(struct Student));
        if(records==NULL)
            printf("Memory allocation failed..\n");
        else
        {
            (records+(count-1))->id=temp_id;
            strcpy((records+(count-1))->name,temp_name);
            (records+(count-1))->cgpa=temp_gpa;
        }
    }
    else
    printf("Record Adding Failed : %d\n",ch);
    fclose(fp);
    saveChanges2File();
}


