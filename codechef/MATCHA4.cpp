#include<iostream>
using namespace std;

long long pow10=1;
long long upper_digits(long long n,long long k)
{
	if(n/pow10)
	{
		long long nsize=1;
		long long ncopy=n;
		while(ncopy)
		{
			ncopy/=10;
			nsize*=10;
		}
		return n/(nsize/pow10);
	}		
	return n;
}
long long p_upper(int n,int m,int k)
{
	
	if(m==0)
		return upper_digits(1,k);
	
	long long x=p_upper(n,m/2,k);
	if(m%2==0)
		return upper_digits(x*x,k);
	else
		return upper_digits(upper_digits(x*x,k)*n,k);
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
		pow10=1;
		for(int i=0;i<k;i++)
			pow10*=10;
		cout<<p_upper(n,n,k)<<" ";
		cout<<append_zero(p_lower(n,n,pow10),k)<<endl;
	}
}
