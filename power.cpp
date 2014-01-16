// Calculate power %MOD in lO(log n).
#define MOD (10000000+7)


long long p(int n,int m)
{
    if(m==0) return 1;
    
    long long x=p(n,m/2);
    if(m%2==0) 
               return (x*x)%MOD;
    else
               return (((x*x)%MOD)*n)%MOD;
}
