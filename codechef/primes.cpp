#include<stdio.h>
#include<math.h>
#include<conio.h>
#define LIMIT 	200000
int primes[LIMIT]={2,3};
int k=1;
void genprime()
{
     for(int i=5;i<LIMIT;i+=2)
     {
             int flag=0;
             int limit=sqrt(i);
             for(int j=0;primes[j]<=limit&&j<=k;j++)
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
    for(int i=0;i<10;i++)
    {
            printf("%d ",primes[i]);
    }    
    getch();
}
