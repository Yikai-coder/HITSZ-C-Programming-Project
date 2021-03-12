#include <stdio.h>
#include <stdlib.h>
#include <time.h>
void GetNumber(int a[10],int b[10],int count1)
{
    srand((int) time(NULL));
    a[count1-1]=rand()%10+1;
    b[count1-1]=rand()%10+1;
}

int main()
{
    int a[10],b[10],count1=1,count2=1,right=0,result,grade=0;


    printf("Number:190110419\nsubject No.4 - program No.1\n");
    for(count1=1;count1<=10;count1++)
    {
        GetNumber(a,b,count1);


        for(count2=1;count2<=3;count2++)
        {
            printf("%d * %d = ? ",a[count1-1],b[count1-1]);
            scanf("%d",&result);
            if(result==a[count1-1]*b[count1-1])
            {
                printf("Right!\n");
                right++;
                break;
            }
            else if(result!=a[count1-1]*b[count1-1])
            {
                if(count2<3)
                    printf("Wrong! Please try again.\n");
                else if(count2==3)
                {
                    printf("Wrong£¡Test  next  subject!\n");
                    break;
                }
            }
        }

    }
    grade=10*right;
    printf("Your grade is %d.Your accurance is %d%%.",grade,grade);

    return 0;
}
