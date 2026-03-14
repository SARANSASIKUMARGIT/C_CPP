#include<stdio.h>
#include<stdbool.h>

int main()
{
    //C program to reverse an integer 
    int n1,n2=0;
    printf("Enter the integer : ");
    scanf("%d",&n1);
    while(n1)
    {
        n2=(n2*10)+(n1%10);
        n1/=10;
    }
    printf("Rev : %d",n2);


    return 0;
}
