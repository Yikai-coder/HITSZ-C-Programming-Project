#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <windows.h>
#define N 10
int GetNumber(void)
{
    int a;
    srand((int)time(NULL));
    a = rand()%10+1;
    return a;
}
void PrintRight(void)
{
    int a;
    srand((int)time(NULL));
    a = rand()%4+1;
    switch (a)
         {
             case 1: printf("Very good!\n");
                     break;
             case 2: printf("Excellent!\n");
                     break;
             case 3: printf("Nice work!\n");
                     break;
             case 4: printf(" Keep up the good work!\n");
                     break;
         }
}
void PrintWrong(void)
{
    int a;
    srand((int)time(NULL));
    a = rand()%4+1;
    switch(a)
    {
        case 1:printf("No. Please try next subject.\n");
           break;
    case 2:printf("Wrong. Be careful.\n");
           break;
    case 3:printf(" Don't give up!\n ");
           break;
    case 4:printf(" Not correct. Keep trying.\n");
           break;
    }
}


int main()
{
    int a,b,result,count,i,answer,right=0;
    float accurance;
    char op;

    printf("Number:190110419\nsubject No.4-program 2\n");
    do{
        for (count=1;count<=10;count++)
        {

           a=GetNumber();
           Sleep(1000);       //创造延时使利用随即函数创造的a，b的值不同
           b=GetNumber();
           srand((int)time(NULL));
           i = rand()%4+1;
           switch(i)
              {
                  case 1:op='+';
                     answer=a+b;
                     break;
              case 2:op='-';
                     answer=a-b;
                    break;
            case 3:op='*';
                   answer=a*b;
                   break;
            case 4:op='/';
                   answer=a/b;
                   break;
              }
        printf("%d %c %d = ?",a,op,b);
        scanf("%d",&result);
        if(result==answer)
        {
           PrintRight();
           right++;

        }
        if(result!=answer)
        {
            PrintWrong();

        }
        }
        accurance=(float)right/10;
        if(accurance-0.75<1e-6)
        {
            printf("Please try it again.\n");
            count=0;
            right=0;
        }
    }while(count<=10);


    return 0;
}
