#include<iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n;
		cin>>n;
		long long fivep=5;
		int count=0;
		while(fivep<=n)
			{
				count+=n/fivep;
				fivep*=5;
			}
		cout<<count<<endl;
	}
	return 0;

}
