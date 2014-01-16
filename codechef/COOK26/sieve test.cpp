#include<stdio.h>
#include<string.h>
#include<conio.h>
#define MAX 5000000
int isprime[MAX/32];

#define isSet(n) isprime[n>>5]&(1<<(n&31))
#define unset(n) isprime[n>>5] &= ~(1<<(n&31))

void sieve()
{
    int i,j,x;
    memset(isprime,-1,sizeof(isprime));
    unset(0);
    unset(1);
    unset(4);
    for(i=10;i<=MAX;i++)
    {
                        unset(i);
    }
    for(i=6;i*i<MAX-5;i+=6)
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
}
int main()
{
    sieve();
    printf("%d",isSet(35));
    getch();
    return 0;
}
