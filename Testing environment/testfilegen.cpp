#include<iostream>
#include<stdio.h>
#include<cstdlib>
using namespace std;


int main()
{
	freopen("test.txt","w",stdout);
	int t=100;
	cout<<t<<endl;
	while(t--)
	{
		int n=3;
		int m=4;
		cout<<n<<" "<<m<<endl;
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				cout<<rand()%2;
			}
			cout<<endl;
		}
		
	}
}
