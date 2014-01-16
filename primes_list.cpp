#include<stdio.h>
#include<math.h>
#define LIMIT 5000000

int primes[500000]={2,3};
int k=1;
void genprime()
{
    int i,j,x;
     for(i=5;i<LIMIT;i+=2)
     {
             int flag=0;
             x=sqrt(i);
             for(j=0;primes[j]<=x&&j<=k;j++)
             {
                     if(i%primes[j]==0)
                     {
                                   flag=1;
                                   break;
                     }
             }
             if(flag==0)
             {          k++;
                        primes[k]=i;
             }
     }
}
int main()
{
    genprime();
    return 0;
}
