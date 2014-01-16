#include<iostream>
using namespace std;

bool isOverlucky(int n)
{
	while(n)
	{
		if(n%10==7||n%10==4)
			return true;
		n/=10;
	}
	return false;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		int count=0;
		for(long long j=1;j*j<=n;j++)
		{
			if(n%j==0)
			{
				if(isOverlucky(j))
					count++;
				if(isOverlucky(n/j))
					count++;
			}
		}
		cout<<count<<endl;
	}
}
