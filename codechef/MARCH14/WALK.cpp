#include<iostream>
#include<climits>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int x=INT_MIN;
		
		for(int i=0;i<n;i++)
		{
			int a;
			cin>>a;
			x=max(x,a+i);
		}
		cout<<x<<endl;
	}
}
