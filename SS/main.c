#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#define N 30
#define M 18
#define K 6
#define O 100
typedef struct student
{
    long number;
    char name[M];
    float score[K];
    float total;
    float average;
}STUDENT;
typedef struct subject
{
    float score[N];
    float total;
    float average;
}SUBJECT;

int ReadScore(STUDENT stu[N],SUBJECT sub[K],int n,int k,int SucceedRead)
{
    int count1=SucceedRead+1,count2;
    char choice;
    while(count1<=n)
    {
        while(1)
        {
            printf("Please enter the number of student%d:",count1);
            scanf("%ld",&stu[count1-1].number);
            if(stu[count1-1].number>0)
                break;
            else
                printf("Please enter again!\n");
        }
        printf("Please enter the name:");
        getchar();
        gets(stu[count1-1].name);
        count2=1;
        while(count2<=k)
        {
            printf("Please enter the score of subject%d:",count2);
            scanf("%f.",&stu[count1-1].score[count2-1]);
            if(stu[count1-1].score[count2-1]-0>1e-6)
            {
                sub[count2-1].score[count1-1]=stu[count1-1].score[count2-1];
                count2++;
            }
            else
            {
                printf("Something is wrong.Please enter again!\n");
            }
        }
        count1++;
        SucceedRead++;
        printf("Do you want to quit (Y/N)?");
        getchar();
        scanf("%c",&choice);
        if(choice=='y'||choice=='Y')
            break;
        printf("\n");
    }
    return SucceedRead;
}
void GetSubjectTotalandAverage(SUBJECT sub[K],int n,int k)                       //求总分
{
    int i,j;

    for(j=1;j<=k;j++)
    {
        sub[j-1].total=0;
        sub[j-1].average=0;
        for(i=1;i<=n;i++)
        {
            sub[j-1].total+=sub[j-1].score[i-1];
        }
        sub[j-1].average=sub[j-1].total/n;
    }
}
void GetStudentTotalandAverage(STUDENT stu[N],int n,int k)
{
    int i,j;
    for(i=1;i<=n;i++)
    {
        stu[i-1].total=0;
        stu[i-1].average=0;
        for(j=1;j<=k;j++)
        {
            stu[i-1].total+=stu[i-1].score[j-1];
        }
        stu[i-1].average=stu[i-1].total/k;
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
void DescendingScore(STUDENT stu[N],int n,int k)
{
    int count,j;
    STUDENT tempstu;
    for(count=1;count<=n-1;count++)
    {
        for(j=0;j<=n-count-1;j++)
        {
            if(stu[j].total<stu[j+1].total)
            {
                tempstu=stu[j];
                stu[j]=stu[j+1];
                stu[j+1]=tempstu;
            }
        }
    }

}
void AscendingScore(STUDENT stu[N],int n,int k)
{
    int count,j;
    STUDENT tempstu;
    for(count=1;count<=n-1;count++)
    {
        for(j=0;j<=n-count-1;j++)
        {
            if(stu[j].total>stu[j+1].total)
            {
                tempstu=stu[j];
                stu[j]=stu[j+1];
                stu[j+1]=tempstu;
            }
        }
    }
}
void AscendingNumber(STUDENT stu[N],int n,int k)
{
     int count,j;
     STUDENT tempstu;
    for(count=1;count<=n-1;count++)
    {
        for(j=0;j<=n-count-1;j++)
        {
            if(stu[j].number>stu[j+1].number)
            {
                tempstu=stu[j];
                stu[j]=stu[j+1];
                stu[j+1]=tempstu;
            }
        }
    }
}
void DirectionaryName(STUDENT stu[N],int n,int k)
{
    int count,j;
    STUDENT tempstu;
    for(count=1;count<=n-1;count++)
    {
        for(j=0;j<=n-count-1;j++)
        {
            if(strcmp(stu[j].name,stu[j+1].name)>0)
            {
                tempstu=stu[j];
                stu[j]=stu[j+1];
                stu[j+1]=tempstu;
            }
        }
    }
}
void SearchNumber(STUDENT stu[N],int n,int k)
{
     int i,j,find=0;
     long inputnumber;
     printf("Please enter the number you want to search:");
     scanf("%ld",&inputnumber);
     for(i=1;i<=n;i++)
     {
         if(stu[i-1].number==inputnumber)
         {
            find=1;
            printf("Number   Name      ");
            for(j=1;j<=k;j++)
            {
                printf("Subject%d ",j);
            }
            printf("Total Average\n");
            printf("%-8ld %-11s ",stu[i-1].number,stu[i-1].name);
            for(j=1;j<=k;j++)
            {
                printf("%-8.1f ",stu[i-1].score[j-1]);
            }
            printf("%-5.1f %-5.3f\n",stu[i-1].total,stu[i-1].average);
        }
        printf("\n");
    }
    if(!find)
        {
            printf("I can't find him/her.\n");
        }
        printf("\n");
}
void SearchName(STUDENT stu[N],int n,int k)
{
    int i,j,find=0;
    char inputname[M];
    printf("Please enter the name you want to search:");
    getchar();
    gets(inputname);
    for(i=1;i<=n;i++)
    {
         if(strcmp(inputname,stu[i-1].name)==0)
         {
            find=1;
            printf("Number   Name      ");
            for(j=1;j<=k;j++)
            {
                printf("Subject%d ",j);
            }
            printf("Total Average\n");
            printf("%-8ld %-11s ",stu[i-1].number,stu[i-1].name);
            for(j=1;j<=k;j++)
            {
                printf("%-8.1f ",stu[i-1].score[j-1]);
            }
            printf("%-5.1f %-5.3f\n",stu[i-1].total,stu[i-1].average);
        }
        printf("\n");
    }
    if(!find)
        {
            printf("I can't find him/her.\n");
        }
        printf("\n");
}
void Analysis(STUDENT stu[N],int n,int k)
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
            if(stu[count-1].score[count1-1]-60<1e-6)
                E++;
            if(stu[count-1].score[count1-1]-60>=1e-6&&stu[count-1].score[count1-1]-70<1e-6)
                D++;
            if(stu[count-1].score[count1-1]-70>=1e-6&&stu[count-1].score[count1-1]-80<1e-6)
                C++;
            if(stu[count-1].score[count1-1]-80>=1e-6&&stu[count-1].score[count1-1]-90<1e-6)
                B++;
            if(stu[count-1].score[count1-1]-90>=1e-6)
                A++;
        }
        printf("Subject%d\n",count1);
        printf("Excellent:%.0f  %.3f%%\n",A,(A/n)*100);
        printf("Good:     %.0f  %.3f%%\n",B,(B/n)*100);
        printf("Well:     %.0f  %.3f%%\n",C,(C/n)*100);
        printf("Common:   %.0f  %.3f%%\n",D,(D/n)*100);
        printf("Fail:     %.0f  %.3f%%\n",E,(E/n)*100);
        printf("\n");
    }
    printf("\n");
}
void Print(STUDENT stu[N],int n,int k)
{
    int i,j;
    printf("Number   Name      ");
    for(j=1;j<=k;j++)
    {
        printf("Subject%d   ",j);
    }
    printf("Total Average\n");
    for(i=1;i<=n;i++)
    {
        printf("%-8ld %-11s ",stu[i-1].number,stu[i-1].name);
        for(j=1;j<=k;j++)
        {
            printf("%-8.1f ",stu[i-1].score[j-1]);
        }
        printf("%-5.1f %-5.3f\n",stu[i-1].total,stu[i-1].average);
    }
    printf("\n");
}
void WritetoFile(STUDENT stu[],int n)
{
    FILE *fp;
    char FileName[O];
    int success;
    getchar();
    printf("Please enter the filename:");
    gets(FileName);
    if((fp=fopen(FileName,"a"))==NULL)
    {
        printf("Fail!");
        exit(0);
    }
    success=fwrite(stu,sizeof(STUDENT),n,fp);
    printf("%d file(s) are written in.\n",success);
    fclose(fp);
}
int ReadFile(STUDENT stu[],int n)
{
    FILE *fp;
    char FileName[O];
    int success;
    long begin,end,length;
    getchar();
    printf("Please enter the filename:");
    gets(FileName);
    if((fp=fopen(FileName,"r"))==NULL)
    {
        printf("Fail!");
        exit(0);
    }
    fseek(fp,0,SEEK_END);
    end=ftell(fp);
    fseek(fp,0,SEEK_SET);
    begin=ftell(fp);
    length=(end-begin)/sizeof(fp);
    success=fread(stu,sizeof(STUDENT),length,fp);
    printf("%d file(s) are read.\n",success);
    fclose(fp);
    return success;
}
void menu(STUDENT stu[N],SUBJECT sub[K],int n, int k)
{

    int choice,count1,SucceedRead=0;
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
        printf("11.List\n");
        printf("12.Write to the file\n");
        printf("13.Read from a file\n");
        printf("0.Exit\n");
        printf("Please enter your choice\n");
        scanf("%d",&choice);
        printf("\n");
        switch(choice)
        {
            case 1: SucceedRead=ReadScore(stu,sub,n,k,SucceedRead);
                    break;                              //Input score
            case 2: GetSubjectTotalandAverage(sub,SucceedRead,k);
                    for(count1=1;count1<=k;count1++)
                    {
                        printf("Subject%d Total=%.1f Average=%.3f\n",count1,sub[count1-1].total,sub[count1-1].average);
                    }
                    printf("\n");
                    break;

            case 3: GetStudentTotalandAverage(stu,SucceedRead,k);
                    Print(stu,n,k);
                    break;


            case 4: GetStudentTotalandAverage(stu,SucceedRead,k);
                    DescendingScore(stu,SucceedRead,k);
                    Print(stu,SucceedRead,k);
                    break;


            case 5: GetStudentTotalandAverage(stu,SucceedRead,k);
                    AscendingScore(stu,SucceedRead,k);
                    Print(stu,SucceedRead,k);
                    break;


            case 6: GetStudentTotalandAverage(stu,SucceedRead,k);
                    AscendingNumber(stu,SucceedRead,k);
                    Print(stu,SucceedRead,k);
                    break;
            case 7: GetStudentTotalandAverage(stu,n,k);
                    Print(stu,n,k);
                    break;

            case 8: GetStudentTotalandAverage(stu,SucceedRead,k);
                    SearchNumber(stu,SucceedRead,k);
                    break; //Search by number

            case 9: GetStudentTotalandAverage(stu,SucceedRead,k);
                    SearchName(stu,SucceedRead,k);
                    break; //Search by number


            case 10: Analysis(stu,SucceedRead,k);
                     break;
            case 11: GetStudentTotalandAverage(stu,SucceedRead,k);
                     Print(stu,SucceedRead,k);
                     printf("\n");
                     GetSubjectTotalandAverage(sub,SucceedRead,k);
                     for(count1=1;count1<=k;count1++)
                     {
                         printf("Subject%d Total=%.1f Average=%.3f\n",count1,sub[count1-1].total,sub[count1-1].average);
                     }
                     break;
            case 12: WritetoFile(stu,SucceedRead);
                     break;
            case 13: SucceedRead=ReadFile(stu,n);
                     GetStudentTotalandAverage(stu,SucceedRead,k);
                     Print(stu,SucceedRead,k);
                     break;
            case 0: exit(0);
        }
    }
}



int main()
{
    int n,k;
    STUDENT stu[N];
    SUBJECT sub[K];



    printf("Number:190110419\nProgram:No.1\n");
    printf("How many students are there in your class:");
    scanf("%d",&n);
    printf("How many classes do you have a exam:");
    scanf("%d",&k);
    menu(stu,sub,n,k);


    return 0;
}

