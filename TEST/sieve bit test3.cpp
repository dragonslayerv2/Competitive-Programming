#include<stdio.h>
#include<string.h>

#define MAX 5000000
int isprime[MAX/32+2];

#define isSet(n) isprime[n>>5]&(1<<(n&31))
#define unset(n) isprime[n>>5] &= ~(1<<(n&31))

void sieve()
{
    int i,j,x;
    memset(isprime,-1,sizeof(isprime));
    unset(0);
    unset(1);
    unset(4);
    for(i=6;i*i<=MAX;i+=6)
    {

            unset(i);
            unset(i+2);
            unset(i+3);
            unset(i+4);


            x=i+1;
            if(x%5==0) unset(x);
            if(isSet(x))
                             {
                                      for(j=x*x;j<=MAX;j+=x)
                                                unset(j);
                             }
            x=i+5;
            if(x%5==0) unset(x);
            if(isSet(x))
                             {
                                        for(j=x*x;j<=MAX;j+=x)
                                                unset(j);
                             }

    }
        for(;i<=MAX;i+=6)
    {
            unset(i);
            unset(i+2);
            unset(i+3);
            unset(i+4);
            if((i+1)%5==0) unset(i+1);
            if((i+5)%5==0) unset(i+5);
    }

}
int main()
{
    sieve();
    return 0;
}
