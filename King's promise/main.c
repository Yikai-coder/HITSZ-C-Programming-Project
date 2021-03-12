#include <stdio.h>
#include <stdlib.h>
long double GetAmount(int a);
long double GetVolumn(double amount);

int main()
{
    long double amount;
    long double volume;
    int a=64;
    amount=GetAmount(a);
    volume=GetVolumn(amount);
    printf("The king should gave him %Lf grains of wheat\n",amount);
    printf("It will cover %Lf cubic meter",volume);

    return 0;
}
long double GetAmount(int a)
{
    long double m;
    if(a==1)
    {
        m=1;

    }
    else
    {
        m=GetAmount(a-1)*2+1;
    }
    return m;
}
 long double GetVolumn(double amount)
{
    long double V;
    V=amount/1.42e8;
    return V;
}
