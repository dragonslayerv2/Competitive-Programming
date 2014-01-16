#include<stdio.h>
#define MYNULL -1

#define MOD (1000000007)


long long pow(int n,int m)
{
    if(m==0) return 1;
    
    long long x=pow(n,m/2);
    if(m%2==0) 
               return (x*x)%MOD;
    else
               return (x*x*n)%MOD;
}


inline int finddisjoint(int a[],int n)
{
    int count=0;
    for(int i=1;i<=n;i++)
    {
            if(a[i]!=MYNULL)
            {
                            int x=i;
                            while(a[x]!=MYNULL)
                            {
                                      int temp=x;
                                      x=a[x];  
                                      a[temp]=MYNULL;         
                            }
                            count++;
            }
    }
    return count;
}

inline void initialise(int a[],int n)
{
       int i=2;
       for(int j=1;j<=n;j++)
       {
               if(i>n) i=1;
               a[j]=i;
               i+=2;
       }
}


int main()
{
    int a[100010];
    
    int t;
    scanf("%d",&t);
    while(t--)
    {
            int n;
            scanf("%d",&n);
            initialise(a,n);
            printf("%lld\n",pow(26,finddisjoint(a,n)));
    }        
    return 0;
}
