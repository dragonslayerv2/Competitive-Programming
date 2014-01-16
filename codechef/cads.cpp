#include<iostream>
using namespace std;

#define MOD 1000000007
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		long long count=1;
		for(int i=1;i<=n;i++)
		{
			count=count*(i*2-1);
			count%=MOD;
		}
		cout<<count<<endl;
	}
}
