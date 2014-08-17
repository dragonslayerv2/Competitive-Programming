#include<iostream>
#include<vector>
using namespace std;

long long power(long long n,long long m,long long MOD)
{
    if(m==0) return 1%MOD;
    
    long long x=power(n,m/2,MOD);
    if(m%2==0) 
               return (x*x)%MOD;
    else
               return (((x*x)%MOD)*n)%MOD;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n,q,r,p1,p2;
		cin>>n>>q>>r>>p1>>p2;
		vector<long long> arrayp1(n+1);
		vector<long long> arrayp2(n+1);
		for(int i=1;i<=n;i++)
		{
			int a;
			cin>>a;
			arrayp1[i]=a%p1;
			arrayp2[i]=a%p2;
		}		
		while(q--)
		{
			int type;
			cin>>type;
			if(type==0)
			{
				long long a,d,x,y;
				cin>>a>>d>>x>>y;
				for(int i=x;i<=y;i++)
				{
					arrayp1[i]+=((a+(i-x)*d)*power(r,i-x,p1))%p1;
					arrayp2[i]+=((a+(i-x)*d)*power(r,i-x,p2))%p2;
					arrayp1[i]%=p1;
					arrayp2[i]%=p2;
				}
			}
		    else if(type==1)
			{
				int x,g;
				cin>>x>>g;
				arrayp1[x]=arrayp2[x]=power(arrayp2[x],g,p2);
				arrayp1[x]%=p1;
			}
			else
			{
				long long sum=0;
				int x,y;
				cin>>x>>y;
				for(int i=x;i<=y;i++)
				{
					sum+=arrayp1[i];
					sum%=p1;
				}
				cout<<sum<<endl;
			}
		}		
	}
}
