#include<stdio.h>
#define tprimes 10
int primes[]={2,3,5,7,11,13,17,19,23,29};

inline int findprime(int n)
{
       for(int i=tprimes-1;i>=0;i--)
       {
               if(!(n%primes[i]))
                      return primes[i];       
       }
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
              int n;
              scanf("%d",&n);
              
              int x;
              int c;
              int flag=1;
              for(int i=0;i<n;i++)
              {
                      scanf("%d",&x);
                      if(i>=1)
                      {
                       if(c!=x)
                               flag=0;
                      }
                      c=x;
              }
              if(flag==1)
                         {printf("0\n"); continue;}
              //------------------------- Step phase------------------------
              int steps=0;
              int nn=n;
              while(nn>1)
              {
                       int prime=findprime(nn);
                       while(1)
                       {
                        if((nn%prime)) break;
                        steps+=n/prime;
                        nn=nn/prime;
                       }
              }
              printf("%d\n",steps);
              //------------------------------- step cal [hase-------------------------
              int d=1;
               nn=n;
              while(nn>1)
              {
              int prime=findprime(nn);
              int in =1;
              int j;
              for(int i=0;i<n/prime;i++)
              {
                         printf("%d ",prime);
                         for( j=in;j<=in+(prime-1)*d;j+=d)
                         {
                                 printf("%d ",j); 
                         }
                         printf("\n");
                         in=j+d;
              }
              d=d*prime;
           
              nn=nn/prime;
            in=;
              }
              
    }
    return 0;
}
