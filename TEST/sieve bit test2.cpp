#include<stdio.h>
#include<string.h>
#define MAX 5000000
int isprime[MAX/32+1];

#define isSet(n) isprime[n>>5]&(1<<(n&31))
#define unset(n) isprime[n>>5] &= ~(1<<(n&31))




void sieve()
{
     int i,j;
    memset(isprime,-1,sizeof(isprime));
    unset(0);
    unset(1);
    unset(4);

    for(i=6;i<MAX;i+=6)
    {
            unset(i);
            unset(i+2);
            unset(i+3);
            unset(i+4);
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
    return 0;
}
