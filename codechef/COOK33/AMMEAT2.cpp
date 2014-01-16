#include<iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		
		if(k==1)
			cout<<n;
		else if(n/2<k)
			cout<<-1;
		
		else
		{
			for(int i=1;i<=k;i++)
			cout<<i*2<<" ";
		}
		cout<<endl;
	}
	return 0;
}
