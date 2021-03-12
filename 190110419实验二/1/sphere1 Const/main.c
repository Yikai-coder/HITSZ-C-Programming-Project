#include <stdio.h>
#include <stdlib.h>
#include<math.h>

int main(void)
{
    float r,S,V;
    const float pi=3.1415926;

    printf("Please input the radius: ");
    scanf("%f",&r);
    S=4*pi*pow(r,2);
    V=4*pi*pow(r,3)/3;
    printf("S=%.2f,V=%.2f",S,V);

    return 0;
}
