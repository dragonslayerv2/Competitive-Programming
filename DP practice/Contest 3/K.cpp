#include<iostream>
#include<vector>
using namespace std;

#define MOD 1000000
int main()
{
//	freopen("testK.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	while(1)
	{
		int n,k;
		cin>>n>>k;
		if(!n&&!k)
			break;
		
		vector<vector<int> > DP(n+1,vector<int>(k+1,1));
		
		for(int i=0;i<=n;i++)
			DP[i][0]=0;
		
		for(int i=1;i<=n;i++)
			for(int j=2;j<=k;j++)
			{
				DP[i][j]=DP[i-1][j]+DP[i][j-1];
				DP[i][j]%=MOD;
			}
				
		
/*		for(int i=0;i<=n;i++)
		{
			for(int j=0;j<=k;j++)
				cout<<DP[i][j]<<" ";
			cout<<endl;
		}*/
		cout<<DP[n][k]<<endl;
	}
}
