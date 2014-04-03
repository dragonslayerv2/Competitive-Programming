// Calculate power %MOD in lO(log n).
#define MOD (10000000+7)


template<class T> T p(T n,T m)
{
    if(m==0) return 1%MOD;
    
    T x=p(n,m/2);
    if(m%2==0) 
               return (x*x)%MOD;
    else
               return (((x*x)%MOD)*n)%MOD;
}



