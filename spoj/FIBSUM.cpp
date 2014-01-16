#include<iostream>
using namespace std;

void tn(long long a[2][2],long long n,long long MOD)
{      
    if(n==1) return;
    else
    {
        tn(a,n/2,MOD);
        long long u,v,w,x;
        u=((a[0][0]*a[0][0])%MOD+(a[0][1]*a[1][0])%MOD)%MOD;
        v=((a[0][0]*a[0][1])%MOD+(a[0][1]*a[1][1])%MOD)%MOD;
        w=((a[1][0]*a[0][0])%MOD+(a[1][1]*a[1][0])%MOD)%MOD;
        x=((a[1][0]*a[0][1])%MOD+(a[1][1]*a[1][1])%MOD)%MOD;
        a[0][0]=u;
        a[0][1]=v;
        a[1][0]=w;
        a[1][1]=x;
        if(n%2!=0)
        {
                  u=a[0][1];
                  v=(a[0][0]+a[0][1])%MOD;
                  w=a[1][1];
                  x=(a[1][0]+a[1][1])%MOD;
                  a[0][0]=u;
                  a[0][1]=v;
                  a[1][0]=w;
                  a[1][1]=x;
        }
    }
}

long long fibonicci(int n,long long MOD)
{
	long long T[2][2]={{0,1},{1,1}};
	tn(T,n,MOD);
	return T[1][0]%MOD;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n,m;
		cin>>n>>m;
		const long long MOD=1000000007;
		cout<<(MOD+fibonicci(m+2,MOD)-fibonicci(n+1,MOD))%MOD<<endl;
	}
}

