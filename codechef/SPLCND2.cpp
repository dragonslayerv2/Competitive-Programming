#include<iostream>
#include<limits>
using namespace std;


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		long long x=0;
		long long sum=0;
		long long MIN=numeric_limits<long long>::max();
		while(n--)
		{
			long long a;
			cin>>a;
			sum+=a;
			x^=a;
			MIN=min(MIN,a);
		}
		if(x==0)
			cout<<sum-MIN<<endl;
		else 
			cout<<"NO"<<endl;
	}
}
