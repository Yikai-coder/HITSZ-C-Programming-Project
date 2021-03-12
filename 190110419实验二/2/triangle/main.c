#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main()
{
    float a,b,c,S,p;

    printf("Please input the triangle's length of side\n");
    scanf("%f,%f,%f",&a,&b,&c);

    if (a+b>c&&a+c>b&&a>0&&b>0&&c>0)
    {
        p=(a+b+c)/2;
        S=sqrt(p*(p-a)*(p-b)*(p-c));
        printf("Its square is %.2f!",S);
    }

    else
    {
       printf("It can't be a triangle!");
    }



    return 0;
}
