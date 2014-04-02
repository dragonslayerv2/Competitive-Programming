#include<iostream>
using namespace std;

int main()
{
	long long n;
	cin>>n;
	long long sum=0;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		sum+=x;
	}
	
	if(sum*2==n*(n+1))
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
}
