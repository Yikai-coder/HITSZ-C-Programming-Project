#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 30
#define M 18
void ReadScore(long number[N],char name[N][M],float score[N],int n)
{
    int count=1;
    while(count<=n)
    {
        printf("Please enter the number:");
        scanf("%ld",&number[count-1]);
        printf("Please enter the name:");
        getchar();
        gets(name[count-1]);
        printf("Please enter the score:");
        scanf("%f.",&score[count-1]);
        if(number[count-1]>0&&score[count-1]-0>1e-6)
        {
            count++;

        }
        else
        {
            printf("Something is wrong.Please enter again!\n");

        }

    }
}
float GetTotal(float score[N],int n)                       //求总分
{
    float total=0;
    int count=1;
    for (count=1;count<=n;count++)
    {
        total+=score[count-1];
    }
    return total;
}
float GetAverage(float total,int n)                           //求平均分
{
    float average;
    average=(float)total/n;
    return average;
}
void DescendingScore(long number[N],char name[N][M],float score[N],int n)
{
    int count,j;
    float tempscore;
    long tempnumber;
    char tempname[M];
    for(count=1;count<=n-1;count++)
    {
        for(j=0;j<=n-1-count;j++)
        {
            if(score[j]<score[j+1])
            {
                tempscore=score[j];
                tempnumber=number[j];
                strcpy(tempname,name[j]);
                score[j]=score[j+1];
                number[j]=number[j+1];
                strcpy(name[j],name[j+1]);
                score[j+1]=tempscore;
                number[j+1]=tempnumber;
                strcpy(name[j+1],tempname);
            }
        }
    }
}


void AscendingScore(long number[N],char name[N][M],float score[N],int n)
{
    int count,j;
    float tempscore;
    long tempnumber;
    char tempname[M];
    for(count=1;count<=n-1;count++)
    {
        for(j=0;j<=n-1-count;j++)
        {
            if(score[j]>score[j+1])
            {
                tempscore=score[j];
                tempnumber=number[j];
                strcpy(tempname,name[j]);
                score[j]=score[j+1];
                number[j]=number[j+1];
                strcpy(name[j],name[j+1]);
                score[j+1]=tempscore;
                number[j+1]=tempnumber;
                strcpy(name[j+1],tempname);
            }
        }
    }

}
void AscendingNumber(long number[N],char name[N][M],float score[N],int n)
{
    int count,j;
    float tempscore;
    long tempnumber;
    char tempname[M];
    for(count=1;count<=n-1;count++)
    {
        for(j=0;j<=n-1-count;j++)
        {
            if(number[j]>number[j+1])
            {
                tempscore=score[j];
                tempnumber=number[j];
                strcpy(tempname,name[j]);
                score[j]=score[j+1];
                number[j]=number[j+1];
                strcpy(name[j],name[j+1]);
                score[j+1]=tempscore;
                number[j+1]=tempnumber;
                strcpy(name[j+1],tempname);
            }
        }
    }
}
void DirectionaryName(long number[N],char name[N][M],float score[N],int n)
{
    int count,j;
    float tempscore;
    long tempnumber;
    char tempname[M];
    for(count=1;count<=n-1;count++)
    {
        for(j=0;j<=n-1-count;j++)
        {
            if(strcmp(name[j],name[j+1])>0)
            {
                tempscore=score[j];
                tempnumber=number[j];
                strcpy(tempname,name[j]);
                score[j]=score[j+1];
                number[j]=number[j+1];
                strcpy(name[j],name[j+1]);
                score[j+1]=tempscore;
                number[j+1]=tempnumber;
                strcpy(name[j+1],tempname);
            }
        }
    }
}
void SearchNumber(long number[N],char name[N][M],float score[N],int n)
{
     int i,true=0,find=0;
     long inputnumber;
     printf("Please enter the number you want to search:");
     scanf("%ld",&inputnumber);
     for(i=0;i<=n;i++)
     {
         if(number[i]==inputnumber)
         {
              printf("%ld %s %.1f\n",inputnumber,name[i],score[i]);
              find=1;
         }

     }
     if(!find)
     {
         printf("I can't find him/her.\n");
     }
}
void SearchName(long number[N],char name[N][M],float score[N],int n)
{
    int i,true=0,find=0;
    char inputname[M];
    printf("Please enter the name you want to search:");
    getchar();
    gets(inputname);
    for(i=0;i<=n;i++)
     {
         if(strcmp(name[i],inputname)==0)
         {
              printf("%ld %s %.1f\n",number[i],name[i],score[i]);
              find=1;
         }

     }
     if(!find)
     {
         printf("I can't find him/her.\n");
     }
}
void Analysis(long number[N],char name[N][M],float score[N],int n)
{
    int A=0,B=0,C=0,D=0,E=0;
    int count;
    DescendingScore(number,name,score,n);
    for(count=1;count<=n;count++)
    {
        if(score[count-1]-60<1e-6)
            E++;
        if(score[count-1]-60>=1e-6&&score[count-1]-70<1e-6)
            D++;
        if(score[count-1]-70>=1e-6&&score[count-1]-80<1e-6)
            C++;
        if(score[count-1]-80>=1e-6&&score[count-1]-90<1e-6)
            B++;
        if(score[count-1]-90>=1e-6)
            A++;
    }
    printf("There are %d people performed excellent in this exam.\n",A);
    printf("There are %d people performed well in this exam.\n",B);
    printf("There are %d people performed common in this exam.\n",C);
    printf("There are %d people just pass this exam.\n",D);
    printf("There are %d people failed in this exam.\n",E);


}
void Print(long number[N],char name[N][M],float score[N],int n)
{
    int count;
    for(count=1;count<=n;count++)
    {
        printf("%ld %s %.1f\n",number[count-1],name[count-1],score[count-1]);
    }
}
void menu(long number[N],char name[N][M],float score[N],int n)
{

    int choice;
    float average,total;
    printf("1.Input record\n");
    printf("2.Calculate total and average score of course\n");
    printf("3.Sort in descending order by score\n");
    printf("4.Sort in ascending order by score\n");
    printf("5.Sort in ascending order by number\n");
    printf("6.Sort in dictionary order by name\n");
    printf("7.Search by number\n");
    printf("8.Search by name\n");
    printf("9.Statistic analysis\n");
    printf("10.List record\n");
    printf("0.Exit\n");
    printf("Please enter your choice\n");
    scanf("%d",&choice);
    switch(choice)
    {
        case 1: ReadScore(number,name,score,n);
                menu(number,name,score,n);

        case 2: total=GetTotal(score,n);
                average=GetAverage(total,n);
                printf("total=%.1f,average=%.3f\n",total,average);
                menu(number,name,score,n);

        case 3: DescendingScore(number,name,score,n);
                Print(number,name,score,n);
                menu(number,name,score,n);

        case 4: AscendingScore(number,name,score,n);
                Print(number,name,score,n);
                menu(number,name,score,n);

        case 5: AscendingNumber(number,name,score,n);
                Print(number,name,score,n);
                menu(number,name,score,n);
        case 6: DirectionaryName(number,name,score,n);
                Print(number,name,score,n);
                menu(number,name,score,n);

        case 7: SearchNumber(number,name,score,n);
                Print(number,name,score,n);
                menu(number,name,score,n);
        case 8: SearchName(number,name,score,n);
                menu(number,name,score,n);
        case 9: Analysis(number,name,score,n);
                menu(number,name,score,n);

        case 10: total=GetTotal(score,n);
                average=GetAverage(total,n);
                Print(number,name,score,n);
                printf("total=%.1f,average=%f\n",total,average);
                menu(number,name,score,n);

        case 0: exit(0);





    }
}



int main()
{
    int n;
    float score[N];
    long number[N];
    char name[N][M];



    printf("Number:190110419\nProgram:No.1\n");
    printf("How many students are there in your class:");
    scanf("%d",&n);
    menu(number,name,score,n);


    return 0;
}
