#include<iostream>
using namespace std;

long long gcd(long long a,long long b)
{
	if(b==0)
		return a;
	else
		gcd(b,a%b);
}

int main()
{
	//freopen("test.txt","r",stdin);
	int t;
	cin>>t;
	while(t--)
	{
		string x;
		cin>>x;
		
		bool flag=false;
		long long num=0;
		long long den=1;
		
		for(int i=0;i<x.size();i++)
		{
			if(x[i]=='.')
				flag=true;
			else
			{
				num*=10;
				num+=x[i]-'0';
				if(flag)
				den*=10;
			}
		}
		//cout<<num<<" "<<den<<endl;
		cout<<den/gcd(num,den)<<endl;
	}
}
