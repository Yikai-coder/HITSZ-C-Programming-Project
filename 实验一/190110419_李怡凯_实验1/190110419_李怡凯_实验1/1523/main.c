#include <stdio.h>
#include <stdlib.h>

int main()
{
    char c;
    int i;
    short int si;
    short s;
    float f;
    double d;

    printf("Please input char: ");
    scanf("%c",&c);
    printf("char c=%c.The size of it is %d.\n",c,sizeof(char));

    printf("Please input int: ");
    scanf("%d",&i);
    printf("int i=%d.The size of it is %d.\n",i,sizeof(int));

    printf("Please input short: ");
    scanf("%d",&s);
    printf("short s=%d.The size of it is %d.\n",s,sizeof(short));

    printf("Please input short int: ");
    scanf("%d",&si);
    printf("short int s=%d.The size of it is %d\n",s,sizeof(short int));

    printf("Please input float: ");
    scanf("%f",&f);
    printf("float f=%f.The size of it is %f.\n",f,sizeof(float));

    printf("Please input double: ");
    scanf("%ld",&d);
    printf("double d=%ld.The size of it is %d.\n",d,sizeof(double));


    return 0;
}
