#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 30
#define M 18
#define K 6
void Initialize(float A[N],int n)
{
    int i;
    for(i=1;i<=n;i++)
    {
        A[i-1]=0;
    }
}
void ReadScore(long number[N],char name[N][M],float score[N][K],int n, int k)
{
    int count1=1,count2;
    while(count1<=n)
    {
        printf("Please enter the number:");
        scanf("%ld",&number[count1-1]);
        printf("Please enter the name:");
        getchar();
        gets(name[count1-1]);
        count2=1;
        while(count2<=k)
        {
            printf("Please enter the score of subject%d:",count2);
            scanf("%f.",&score[count1-1][count2-1]);
            if(score[count1-1][count2-1]-0>1e-6)
            {
                count2++;
            }
            else
            {
                printf("Something is wrong.Please enter again!\n");
            }
        }
        count1++;
    }
}
void GetSubjectTotal(float score[N][K],float SubjectTotal[K],int n,int k)                       //求总分
{
    int i,j;
    for(j=1;j<=k;j++)
    {
        for(i=1;i<=n;i++)
        {
            SubjectTotal[j-1]+=score[i-1][j-1];
        }
    }
}
void GetStudentTotal(float score[N][K],float StudentTotal[N],int n,int k)
{
    int i,j;
    Initialize(StudentTotal,n);
    for(i=1;i<=n;i++)
    {
        for(j=1;j<=k;j++)
        {
            StudentTotal[i-1]+=score[i-1][j-1];
        }
    }
}
void GetAverage(float total[N],float Average[N],int n)                           //求平均分
{
    int i;
    for(i=1;i<=n;i++)
    {
        Average[i-1]=total[i-1]/n;
    }


}
void DescendingScore(long number[N],char name[N][M],float TotalScore[N],float Average[N],float score[N][K],int n,int k)
{
    int count,j,l;
    float tempscore,tempaverage;
    long tempnumber;
    char tempname[M];
    for(count=1;count<=n-1;count++)
    {
        for(j=0;j<=n-1-count;j++)
        {
            if(TotalScore[j]<TotalScore[j+1])
            {
                tempscore=TotalScore[j];
                tempaverage=Average[j];
                tempnumber=number[j];
                strcpy(tempname,name[j]);
                TotalScore[j]=TotalScore[j+1];
                number[j]=number[j+1];
                strcpy(name[j],name[j+1]);
                TotalScore[j+1]=tempscore;
                Average[j+1]=tempaverage;
                number[j+1]=tempnumber;
                strcpy(name[j+1],tempname);
                for(l=0;l<=k-1;l++)
                {
                    tempscore=score[j][l];
                    score[j][l]=score[j+1][l];
                    score[j+1][l]=tempscore;
                }
            }
        }
    }
}


void AacendingScore(long number[N],char name[N][M],float TotalScore[N],float Average[N],float score[N][K],int n,int k)
{
    int count,j,l;
    float tempscore,tempaverage;
    long tempnumber;
    char tempname[M];
    for(count=1;count<=n-1;count++)
    {
        for(j=0;j<=n-1-count;j++)
        {
            if(TotalScore[j]>TotalScore[j+1])
            {
                tempscore=TotalScore[j];
                tempaverage=Average[j];
                tempnumber=number[j];
                strcpy(tempname,name[j]);
                TotalScore[j]=TotalScore[j+1];
                number[j]=number[j+1];
                strcpy(name[j],name[j+1]);
                TotalScore[j+1]=tempscore;
                Average[j+1]=tempaverage;
                number[j+1]=tempnumber;
                strcpy(name[j+1],tempname);
                for(l=0;l<=k-1;l++)
                {
                    tempscore=score[j][l];
                    score[j][l]=score[j+1][l];
                    score[j+1][l]=tempscore;
                }
            }
        }
    }
}
void AscendingNumber(long number[N],char name[N][M],float TotalScore[N],float Average[N],float score[N][K],int n,int k)
{
    int count,j,l;
    float tempscore,tempaverage;
    long tempnumber;
    char tempname[M];
    for(count=1;count<=n-1;count++)
    {
        for(j=0;j<=n-1-count;j++)
        {
            if(number[j]>number[j+1])
            {
                tempscore=TotalScore[j];
                tempaverage=Average[j];
                tempnumber=number[j];
                strcpy(tempname,name[j]);
                TotalScore[j]=TotalScore[j+1];
                number[j]=number[j+1];
                strcpy(name[j],name[j+1]);
                TotalScore[j+1]=tempscore;
                Average[j+1]=tempaverage;
                number[j+1]=tempnumber;
                strcpy(name[j+1],tempname);
                for(l=0;l<=k-1;l++)
                {
                    tempscore=score[j][l];
                    score[j][l]=score[j+1][l];
                    score[j+1][l]=tempscore;
                }
            }
        }
    }
}
void DirectionaryName(long number[N],char name[N][M],float TotalScore[N],float Average[N],float score[N][K],int n,int k)
{
    int count,j,l;
    float tempscore,tempaverage;
    long tempnumber;
    char tempname[M];
    for(count=1;count<=n-1;count++)
    {
        for(j=0;j<=n-1-count;j++)
        {
            if(strcmp(name[j],name[j+1])>0)
            {
                tempscore=TotalScore[j];
                tempaverage=Average[j];
                tempnumber=number[j];
                strcpy(tempname,name[j]);
                TotalScore[j]=TotalScore[j+1];
                number[j]=number[j+1];
                strcpy(name[j],name[j+1]);
                TotalScore[j+1]=tempscore;
                Average[j+1]=tempaverage;
                number[j+1]=tempnumber;
                strcpy(name[j+1],tempname);
                for(l=0;l<=k-1;l++)
                {
                    tempscore=score[j][l];
                    score[j][l]=score[j+1][l];
                    score[j+1][l]=tempscore;
                }
            }
        }
    }
}
void SearchNumber(long number[N],char name[N][M],float TotalScore[N],float Average[N],float score[N][K],int n,int k)
{
     int i,j,find=0;
     long inputnumber;
     printf("Please enter the number you want to search:");
     scanf("%ld",&inputnumber);
     for(i=1;i<=n;i++)
     {
         if(number[i-1]==inputnumber)
         {
            find=1;
            printf("%ld %s ",number[i-1],name[i-1]);
            for(j=1;j<=k;j++)
            {
                printf("%.1f ",score[i-1][j-1]);
            }
            printf("%.1f %.3f\n",TotalScore[i-1],Average[i-1]);
         }

     }
     if(!find)
     {
         printf("I can't find him/her.\n");
     }
}
void SearchName(long number[N],char name[N][M],float TotalScore[N],float Average[N],float score[N][K],int n,int k)
{
    int i,j,find=0;
    char inputname[M];
    printf("Please enter the name you want to search:");
    getchar();
    gets(inputname);
    for(i=1;i<=n;i++)
    {
         if(strcmp(name[i-1],inputname)==0)
         {
            find=1;
            printf("%ld %s ",number[i-1],name[i-1]);
            for(j=1;j<=k;j++)
            {
                printf("%.1f ",score[i-1][j-1]);
            }
            printf("%.1f %.3f\n",TotalScore[i-1],Average[i-1]);
         }
    }
     if(!find)
     {
         printf("I can't find him/her.\n");
     }
}
void Analysis(float score[N][K],int n,int k)
{
    float A=0,B=0,C=0,D=0,E=0;
    int count,count1;
    for(count1=1;count1<=k;count1++)
    {
        A=0;
        B=0;
        C=0;
        D=0;
        E=0;
        for(count=1;count<=n;count++)
        {
            if(score[count-1][count1-1]-60<1e-6)
                E++;
            if(score[count-1][count1-1]-60>=1e-6&&score[count-1][count1-1]-70<1e-6)
                D++;
            if(score[count-1][count1-1]-70>=1e-6&&score[count-1][count1-1]-80<1e-6)
                C++;
            if(score[count-1][count1-1]-80>=1e-6&&score[count-1][count1-1]-90<1e-6)
                B++;
            if(score[count-1][count1-1]-90>=1e-6)
                A++;
        }
        printf("Subject%d\n",count1);
        printf("Excellent:%.0f  %.3f%\n",A,(A/n)*100);
        printf("Good:     %.0f  %.3f%\n",B,(B/n)*100);
        printf("Well:     %.0f  %.3f%\n",C,(C/n)*100);
        printf("Common:   %.0f  %.3f%\n",D,(D/n)*100);
        printf("Fail:     %.0f  %.3f%\n",E,(E/n)*100);
    }



}
void Print(long number[N],char name[N][M],float TotalScore[N],float Average[N],float score[N][K],int n,int k)
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        printf("%ld %s ",number[i-1],name[i-1]);
        for(j=1;j<=k;j++)
        {
            printf("%.1f ",score[i-1][j-1]);
        }
        printf("%.1f %.3f\n",TotalScore[i-1],Average[i-1]);
    }
}
void menu(long number[N],char name[N][M],float score[N][K],int n, int k)
{

    int choice,count1;
    float SubjectTotal[K],SubjectAverage[K];
    float StudentTotal[N],StudentAverage[N];
    Initialize(SubjectTotal,k);
    Initialize(SubjectAverage,k);
    Initialize(StudentTotal,n);
    Initialize(StudentAverage,n);
    while(1)
    {
        printf("1.Input record\n");
        printf("2.Calculate total and average score of every course\n");
        printf("3.Calculate total and average score of every student \n");
        printf("4.Sort in descending order by total score of every student\n");
        printf("5.Sort in ascending order by total score of every student \n");
        printf("6.Sort in ascending order by number \n");
        printf("7.Sort in dictionary order by name \n");
        printf("8.Search by number\n");
        printf("9.Search by name \n");
        printf("10.Statistic analysis for every course \n");
        printf("0.Exit\n");
        printf("Please enter your choice\n");
        scanf("%d",&choice);
        switch(choice)
        {
            case 1: ReadScore(number,name,score,n,k);
                    break;                              //Input score
            case 2: GetSubjectTotal(score,SubjectTotal,n,k);
                    GetAverage(SubjectTotal,SubjectAverage,n);
                    for(count1=1;count1<=k;count1++)
                    {
                        printf("Subject%d Total=%.1f Average=%.3f\n",count1,SubjectTotal[count1-1],SubjectAverage[count1-1]);
                    }
                    break;

            case 3: GetStudentTotal(score,StudentTotal,n,k);
                    GetAverage(StudentTotal,StudentAverage,k);
                    Print(number,name,StudentTotal,StudentAverage,score,n,k);
                    break;


            case 4: GetStudentTotal(score,StudentTotal,n,k);
                    GetAverage(StudentTotal,StudentAverage,k);
                    DescendingScore(number,name,StudentTotal,StudentAverage,score,n,k);
                    Print(number,name,StudentTotal,StudentAverage,score,n,k);
                    break;


            case 5: GetStudentTotal(score,StudentTotal,n,k);
                    GetAverage(StudentTotal,StudentAverage,k);
                    AacendingScore(number,name,StudentTotal,StudentAverage,score,n,k);
                    Print(number,name,StudentTotal,StudentAverage,score,n,k);
                    break;


            case 6: GetStudentTotal(score,StudentTotal,n,k);
                    GetAverage(StudentTotal,StudentAverage,k);
                    AscendingNumber(number,name,StudentTotal,StudentAverage,score,n,k);//Sort in ascending order by number
                    Print(number,name,StudentTotal,StudentAverage,score,n,k);
                    break;


            case 7: GetStudentTotal(score,StudentTotal,n,k);
                    GetAverage(StudentTotal,StudentAverage,k);
                    DirectionaryName(number,name,StudentTotal,StudentAverage,score,n,k);
                    Print(number,name,StudentTotal,StudentAverage,score,n,k);
                    break;

            case 8: GetStudentTotal(score,StudentTotal,n,k);
                    GetAverage(StudentTotal,StudentAverage,k);
                    SearchNumber(number,name,StudentTotal,StudentAverage,score,n,k);
                    break; //Search by number

            case 9: GetStudentTotal(score,StudentTotal,n,k);
                    GetAverage(StudentTotal,StudentAverage,k);
                    SearchName(number,name,StudentTotal,StudentAverage,score,n,k);
                    break;//Search by name


            case 10: Analysis(score,n,k);
                     break;
            case 11: GetStudentTotal(score,StudentTotal,n,k);
                     GetAverage(StudentTotal,StudentAverage,k);
                     Print(number,name,StudentTotal,StudentAverage,score,n,k);
                     printf("\n");
                     GetSubjectTotal(score,SubjectTotal,n,k);
                     GetAverage(SubjectTotal,SubjectAverage,n);
                     for(count1=1;count1<=k;count1++)
                     {
                         printf("Subject%d Total=%.1f Average=%.3f\n",count1,SubjectTotal[count1-1],SubjectAverage[count1-1]);
                     }
                     break;
            case 0: exit(0);
        }
    }
}



int main()
{
    int n,k;
    float score[N][K];
    long number[N];
    char name[N][M];



    printf("Number:190110419\nProgram:No.1\n");
    printf("How many students are there in your class:");
    scanf("%d",&n);
    printf("How many classes do you have a class:");
    scanf("%d",&k);
    menu(number,name,score,n,k);


    return 0;
}

