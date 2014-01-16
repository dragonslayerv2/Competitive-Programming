/*
	Name: Kth binary number with S 1s...
	Copyright: 
	Author: Shobhit Saxena
	Date: 11/08/13 03:58
	Description: "http://discuss.codechef.com/questions/19033/coinchng-editorial"
*/
//------------------------------------------------------------------------------
#include<iostream>
using namespace std;


#define MOD 1000000007
#define MAX 64
long long fact[MAX];
long long ifact[MAX];
long long pow(long long n,int m)
{
    if(m==0) return 1;
    
    long long x=pow(n,m/2);
    if(m%2==0) 
               return (x*x)%MOD;
    else
               return (((x*x)%MOD)*n)%MOD;
}

void initfact(int n=MAX-1)
{
     int i;
     fact[0]=1;
     for(i=1;i<=n;i++)
                     fact[i] = i*fact[i-1]%MOD;
     ifact[n] = pow(fact[n],MOD-2);
     for(i=n;i>0;i--)
     ifact[i-1] = ifact[i]*i%MOD;
}


inline long long C(int a,int b)
{
	if(b<=a)
		return ((((fact[a]*ifact[b])%MOD)*ifact[a-b])%MOD);
	else
		return 0;
} 



long long solve(int s,int k)
{
	int n=s;
	while(C(n,s)<k)
		n++;
		
	long long ans=0;
	
	for(int i=n;i>=1;i--)
	{
		if(C(i-1,s)>=k)
		{
			continue;
		}
			
		else
		{
			
			ans+=((long long)1)<<(i-1);
			k-=C(i-1,s);
			s--;
		}	
	}
	
	return ans;
}
//------------------------------------------------------------------------------
int  main()
{
	
	initfact();
	
	int t;
	cin>>t;
	while(t--)
	{
		int s,k;
		cin>>s>>k;
		cout<<solve(s,k)<<endl;
	}
	return 0;
}

