#include<iostream>
#include<limits>
#include<vector>
using namespace std;

int main()
{
	int T=1;
	while(1)
	{	
		int n;
		cin>>n;
		if(n==0)
			break;
		vector<vector<long long> > matrix(n,vector<long long>(3));
	
		for(int i=0;i<n;i++)
			for(int j=0;j<3;j++)
				cin>>matrix[i][j];
		
		vector<vector<long long> > DP(n,vector<long long>(3));
		
		DP[n-1][2]=1000000000000LL;
		DP[n-1][1]=matrix[n-1][1];
		DP[n-1][0]=matrix[n-1][0]+matrix[n-1][1];
	
		for(int i=n-2;i>=0;i--)
		{
			for(int j=2;j>=0;j--)
			{
				if(j==0)
					DP[i][j]=matrix[i][j]+min(DP[i+1][j],min(DP[i+1][j+1],DP[i][j+1]));
				else if(j==1)
				{
					DP[i][j]=matrix[i][j]+min(DP[i+1][j-1],min(DP[i+1][j],min(DP[i+1][j+1],DP[i][j+1])));
				}
				else
				{
					DP[i][j]=matrix[i][j]+min(DP[i+1][j],DP[i+1][j-1]);
				}
			}
		}
		
		cout<<T<<". ";
		if(n==1)
			cout<<matrix[0][1];
		else
			cout<<DP[0][1];
		cout<<endl;
		T++;
	}
}
