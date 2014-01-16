#include<iostream>
using namespace std;


int main()
{
	int t=1048576;
	cout<<t;
	for(int i=0;i<t;i++)
	{
		cout<<"4 5"<<endl;
		int n=i;
		for(int j=0;j<4;j++)
		{
			
			for(int k=0;k<5;k++)
			{
				cout<<(n&1);
				n=n>>1;
			}
			cout<<endl;
		}
	
	}
	
	
}
