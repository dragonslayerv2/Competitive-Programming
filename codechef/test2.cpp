#include<iostream>
using namespace std;


int main()
{
	int t=3125;
	cout<<t<<endl;
	for(int i=1;i<=5;i++)
	{
		for(int j=1;j<=5;j++)
		{
			for(int k=1;k<=5;k++)
			{
				for(int l=1;l<=5;l++)
				{
					for(int m=1;m<=5;m++)
					{
						cout<<5<<"\n"<<i<<" "<<j<<" "<<k<<" "<<l<<" "<<m<<endl;
					}
				}
			}
		}
	}
}
