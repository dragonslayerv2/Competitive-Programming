#include<stdio.h>
int main()
{
    int i=1;
    long long sum1=0;
    long long sum2=0;
    for(int i=1;i<=100;i++)
    {
            sum1+=i*i;
            sum2+=i;
    }
    sum2*=sum2;
    printf("%lld",-1*sum1+sum2);
    getchar();
}
