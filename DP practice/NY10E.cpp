#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<vector<long long> > count(65,vector<long long>(10));
	
	for(int j=0;j<=9;j++)
		count[1][j]=j+1;
	for(int i=2;i<=64;i++)
		for(int j=0;j<=9;j++)
			for(int k=0;k<=j;k++)
				count[i][j]+=count[i-1][k];
	
	int t;
	cin>>t;
	while(t--)
	{
		int number;
		cin>>number;
		cout<<number<<" ";
		
		
		int n;
		cin>>n;
		cout<<count[n][9]<<endl;	
	}
}
