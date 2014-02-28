#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long n,l,r;
		cin>>n>>l>>r;
		long long k=floor(double(n)/l);
		if(k>=ceil(double(n)/r))
			cout<<"Yes";
		else
			cout<<"No";
		cout<<endl;
	}
}
