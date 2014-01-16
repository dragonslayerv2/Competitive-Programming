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
		{
			cout<<1<<endl;
		}
		else if(k>n/2)
		{
			cout<<-1<<endl;
		}
		else
		{
			for(int i=1;i<=k;i++)
			{
				cout<<i*2<<" ";
			}
			cout<<endl;
		}
	
	}

}
