#include<stdio.h>

inline long long fibo(int n)
{
    long long a=1,b=a;
    long long temp;
    for(int i=0;i<n-2;i++)
    {
        temp=a+b;
        a=b;
        b=temp;
    }
    return b;
}
int main()
{
    printf("%lld",fibo(100));
}
