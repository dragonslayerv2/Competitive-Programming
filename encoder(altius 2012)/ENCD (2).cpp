#include<stdio.h>
#include<string.h>
#define MAX 1111111

int isprime[MAX/32+2];

#define isSet(n) isprime[n>>5]&(1<<(n&31))
#define unset(n) isprime[n>>5] &= ~(1<<(n&31));


long long p(int a,int n,int MOD)
{
    if(n==0) return 1;
    
    long long x=p(a,n/2,MOD);
    if(n%2==0) 
               return (x*x)%MOD;
    else
               return (x*x*a)%MOD;
}

void sieve()
{
    int i,j;
    memset(isprime,-1,sizeof(isprime));
    unset(0);
    unset(1);
    unset(4);

    for(i=6;i<=MAX;i+=6)
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
    int n;
    while(1)
    {
          scanf("%d",&n);
          if(n==0) break;
          if(n==3)                {printf("%d is normal.",n); continue;}
          if(isSet(n)) {printf("%d is normal.\n",n); continue;}
          else
              {
                       int flag=0;
                       for(int i=2;i<n;i++)
                       {
                               if((int)p(i,n,n)!=i) flag=1; 
                       }
                       if(flag==1)
                                  {printf("%d is normal.",n); continue;}
                       else
                                  {printf("The number %d is a Carmichael number.\n",n);continue;}
              }
}
    return 0;
}
