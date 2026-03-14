#include<stdio.h>
#include<stdbool.h>
//C Program for Prime number checking from series 4 to N
int main()
{
    int n;
    bool isPrime=true;
    printf("Enter the range of numbers : ");
    scanf("%d",&n);                  //inputing the maximum range from user
    for(int i=4;i<=n;++i)
    {   
        isPrime=true;
        for(int j=2;j<=(i/2);++j)
        {
            if(i%j==0)
            {
                isPrime=false;
                break;
            }
        }
        if(isPrime)          //checking if the number in current iteration is a prime
        printf("%d\t",i);
    }


    return 0;
}
