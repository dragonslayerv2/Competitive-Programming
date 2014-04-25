#include<iostream>
#include<vector>
using namespace std;

int DP[2][101][101];
int main()
{
	freopen("testB.txt","r",stdin);
	int T;
	cin>>T;
	while(T--)
	{
		int t;
		cin>>t;
		cout<<t<<" ";
		
		int n,k;
		cin>>n>>k;
		
		for(int K=0;K<=k;K++)
			DP[0][n][K]=DP[1][n][K]=0;
		
		DP[0][n][0]=1;	
		DP[1][n][0]=1;
		
		for(int N=n-1;N>0;N--)
			for(int K=0;K<=k;K++)
			{
				DP[0][N][K]=DP[0][N+1][K]+DP[1][N+1][K];
				DP[1][N][K]=DP[0][N+1][K];
				if(K-1>=0)
					DP[1][N][K]+=DP[1][N+1][K-1];
			}
			
		cout<<DP[1][1][k]+DP[0][1][k]<<endl;
	}
}
