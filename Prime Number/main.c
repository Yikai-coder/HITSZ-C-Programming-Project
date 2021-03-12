#include <stdio.h>
#include <stdlib.h>
#include <math.h>
int JudgePrime(int m);
void Factoring(int m);
int main()
{
    int m,t;
    printf("Please enter a number:");
    scanf("%d",&m);
    if(m<=0||m==1)
    {
         printf("It's 1 or negative number.");
         exit(0);
    }
    t=JudgePrime(m);
    if(t==1)
    {
        printf("It is a prime number.");
    }
    else
    {
         printf("It's not a prime number.");
         Factoring(m);
    }
    return 0;
}
int JudgePrime(int m)
{
    int a,b,i;
    a=sqrt(m);
    for(i=2;i<=a;i++)
    {
        if(m%i!=0)
        {
            b=1;
            continue;
        }
        else
        {   b=0;
            break;
        }
    }
    return b;
}
void Factoring(int m)
{
    int i=2,count=0;
    printf("%d=",m);
    do{
        if(m%i==0)
        {
           m=m/i;
           count++;
           if(count==1)
           {
               printf("%d",i);
           }
           else
           {
               printf("*%d",i);
           }
        }
        else
        {
            i++;
        }
    }while(i<=m);


}


