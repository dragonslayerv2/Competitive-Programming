#include<stdio.h>


#define MOD 1009

inline long long func(int a[],int n,int x)
{
             int i;
             long long fx=0;
             for(i=n;i>=0;i--)
                     fx=(fx*x+a[i])%MOD;
             return fx;
}


int main()
{
    int n,m;
    int i,x;
    int a[201];
    scanf("%d%d",&n,&m);
    m%=MOD;
    for(i=n;i>=0;i--)
            scanf("%d",&a[i]);
    
    long long ans=0;
    for( x=1;x<=m;x++)
            ans=(ans+func(a,n,x))%MOD;
    ans+=a[0];
    ans%=MOD;
    printf("%d\n",(int)ans);
   // fflush(stdin);
    //getchar();
    return 0;
}
