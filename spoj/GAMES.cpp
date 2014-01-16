#include<iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;
		
	while(t--)
	{
		double x;
		cin>>x;
		for(int i=1;1;i++)
		{		
			if((x*i)==(long long)(x*i))
			{
				cout<<i<<endl;
				break;
			}
		}
	}
}
