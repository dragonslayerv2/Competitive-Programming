#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#define MAX 5000000
int isprime[1<<18];
#define isSet(n) isprime[n>>5]&(1<<(n&31))
#define unset(n) isprime[n>>5] &= ~(1<<(n&31))




void sieve()
{
     int i;
    memset(isprime,-1,sizeof(isprime));
    unset(0);
    unset(1);
    for(i=4;i<MAX;i+=2)
                       unset(i);

    for(i=3;i*i<=MAX;i+=2)
                           if(isSet(i))
                             {
                                        for(int j=i*i;j<=MAX;j+=i)
                                                unset(j);
                             }
}
int main()
{
    sieve();
}
