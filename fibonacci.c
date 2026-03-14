#include<stdio.h>
#include<stdbool.h>

int main()
{
    //Fibonacci Series
    int a=-1,b=1,c,n;
    printf("Enter the fibonacci series max range : ");
    scanf("%d",&n);
    c=a+b;
    printf("%d %d ",a,b);
    while(c<=n)
    {
        printf("%d ",c);
        a=b;
        b=c;
        c=a+b;
    }


    return 0;
}
