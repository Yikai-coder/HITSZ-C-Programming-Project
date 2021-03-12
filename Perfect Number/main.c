#include <stdio.h>
#include <stdlib.h>

int main()
{
    int m,n,a=1,i=2;
    printf("Please enter a number:");
    scanf("%d",&m);\
    n=m;
    do{
        if(m%i==0)
        {
           m=m/i;
           a=a+i;
        }
        else
        {
            i++;
        }
    }while(i<=n);
    if(a==n)
    {
        printf("It's a perfect number!");

    }
    else
    {
        printf("It's not a perfect number.");
    }
    return 0;

}
