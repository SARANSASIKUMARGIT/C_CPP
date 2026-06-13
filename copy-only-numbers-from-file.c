#include<stdio.h>
#include<stdbool.h>
//C program to copy only numbers from one file to another by Saran SK

/*
Sample Source File Content : 
    sarn1243djkfe4 ijfe dj33jkjf 99 33 3i9i1i3

Sample Destination File Content : 
    1243,4,33,99,33,3,9,1,3,
*/

void main()
{
    char delimeter=',',c;
    bool numberStreak=false;
    FILE *sourceFile=fopen("student_copy.txt","r");
    FILE *destinationFile=fopen("student_source.txt","w");
    while((c=getc(sourceFile))!=EOF)
    {
        if(c>=48 && c<=57) //if the character is a number
        {
            if(numberStreak)    //if the number is a continous chain eg 1544 not 23d4
            putc(c,destinationFile);    //write number into destination
            else
            {
                numberStreak=true;      // if a number is found after a non-numerical character
                putc(c,destinationFile);
            }
        }
        else
        {
            if(numberStreak)    //if a non-numerical character is found after continous number sequence
            {
                numberStreak=false;     //manipulating streak as false as the streak is broken
                putc(delimeter,destinationFile);        //separating the number in destination file with delimeter
            }
        }
    }
    if(c==EOF && numberStreak)          //if after a number streak the file ends then add delimeter at end
    fputc(delimeter,destinationFile);
    fclose(sourceFile);                     //closing both the file pointer to avoid memory leak
    fclose(destinationFile);
    
}
