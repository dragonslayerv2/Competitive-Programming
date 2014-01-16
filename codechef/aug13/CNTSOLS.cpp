#include<iostream>
using namespace std;

#define MOD 1000000007

long long p(long long n,long long m,long long M)
{
    if(m==0) return (1%M);
    
    long long x=p(n,m/2,M);
    if(m%2==0) 
               return (x*x)%M;
    else
               return (((x*x)%M)*n)%M;
}

long long solve(long long upper,long long d,long long m,long long n,int pos=0)
{
	//cout<<"Solving for "<<upper<<" "<<d<<" "<<m<<" "<<n<<" " <<pos<<endl;
	if(pos==2)
	{
		
			long long count=0;
			for(int i=0;i<n&&i<=upper;i++)
			{	
				if(p(i,d,n)==m)
				{	count+=1+(upper-i)/n;		
					count=count%MOD;
				}
			}
	//		cout<<"Returning "<<count<<endl;
			return count;
	}
	else
	{
		long long count=0;
		for(int i=0;i<n&&i<=upper;i++)
		{
			count+=solve(upper,d,(n+m-(n+p(i,d,n))%n)%n,n,pos+1)*(1+(upper-i)/n);
			count=count%MOD;
		}
	//	cout<<"Returning "<<count<<endl;
		return count;
	}
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long upper,d,m,n;
		cin>>upper>>d>>m>>n;
		cout<<solve(upper,d,m,n)<<endl;
	}
}
