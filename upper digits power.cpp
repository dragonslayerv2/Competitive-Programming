#include<iostream>
#include<cmath>
using namespace std;

long long p_upper(long long n,long long m,int k)
{
	
	long double lg=m*log10l(n);
	lg=lg-(long long)(lg);
	double result=powl(10,lg);
	long long pow10=1;
	for(int i=1;i<k;i++)
		pow10*=10;
	return result*pow10;
}

long long p_lower(int n,int m,int MOD)
{
    if(m==0) return 1%MOD;
    
    long long x=p_lower(n,m/2,MOD);
    if(m%2==0) 
               return (x*x)%MOD;
    else
               return (((x*x)%MOD)*n)%MOD;
}

long long append_zero(long long a,int k)
{
	int x=a;
	int digit_count=0;
	do
	{
		digit_count++;
		x=x/10;
	}while(x);

	if(digit_count<k)
	{
		for(int i=digit_count;i<k;i++)
			cout<<0;		
	}
	return a;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		cout<<p_upper(n,n,k)<<" ";
		
		long long pow10=1;
		for(int i=0;i<k;i++)
			pow10*=10;
		
		cout<<append_zero(p_lower(n,n,pow10),k)<<endl;
	}
}
