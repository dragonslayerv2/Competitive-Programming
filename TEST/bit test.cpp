#include<stdio.h>
#include<string.h>
#define MAX 1000000
int isprime[MAX/32+2];

#define isSet(n) isprime[n>>5]&(1<<(n&31))
#define unset(n) isprime[n>>5] &= ~(1<<(n&31));

void sieve()
{
    int i,j;
    for(i=0;i<MAX/32+2;i+=3)
    {
            isprime[i]=681740840;       
            isprime[i+1]=-1977048438;
            isprime[i+2]=-1568003934;
    }
    for(i=5;i*i<=MAX;i+=2)
                           if(isSet(i))
                             {
                                        for(j=i*i;j<=MAX;j+=i)
                                                unset(j);
                             }
}
int main()
{
    sieve();
    for(int i=0;i<MAX;i++)
    {
            if(isSet(i)) printf("%d\n",i);
    }
    
    return 0;
}
