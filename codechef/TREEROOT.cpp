#include<iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int root=0;
		while(n--)
		{
			int a,b;
			cin>>a>>b;
			root+=a-b;
		}
		cout<<root<<endl;
	}
}
