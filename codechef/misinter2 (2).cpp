#include<stdio.h>
#include<string.h>

#define MAX 100000

int flags[MAX/32+2];

#define isSet(n) flags[n>>5]&(1<<(n&31))
#define unset(n) flags[n>>5] &= ~(1<<(n&31))
#define set(n) flags[n>>5]|=(1<<(n&31))

#define MOD (1000000007)


long long p(int m)
{
    if(m==0) return 1;
    
    long long x=p(m/2);
    if(m%2==0) 
               return (x*x)%MOD;
    else
               return (((x*x)%MOD)*26)%MOD;
}




inline int disjoint(int n)
{
       for(int i=0;i<=n/32+1;i++)
               flags[i]=-1;
       
       int count=0;
       
       for(int i=1;i<=n;i++)
       {
               if(isSet(i))
               {
                           int x=i;
                            while(isSet(x))
                            {
                                      unset(x);
                                      x=x>n/2?2*x-n-1:2*x;       
                            }
                            count++;            
               }        
       }
       return count;
}      
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
           int n;
           scanf("%d",&n);
           printf("%lld\n",p(disjoint(n)));
    }        
    return 0;
}
