#include<iostream>
#include<vector>
using namespace std;

int main()
{
//	freopen("sample.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	
	while(t--)
	{
			vector<int> a;
			int n;
			cin>>n;
			a.resize(n);
			for(int i=0;i<n;i++)
				cin>>a[i];
		
			for(int i=0;i<n;i++)
			{
				int b;
				cin>>b;
				a[i]=(4+b-a[i])%4;
			}
			
			#define MAXDP 100
			vector<vector<int> > DP(n+1,vector<int>(MAXDP));
			for(int i=n-1;i>=0;i--)
			{
				for(int j=0;j<MAXDP;j++)
				{
					DP[i][j]=INT_MAX;
					for(int k=0;k<MAXDP;k++)
						DP[i][j]=min(DP[i][j],a[i]+4*k+DP[i+1][k]-min(a[i]+4*k,a[i-1]+4*j));
				}
			}
			int ans=INT_MAX;
			for(int i=0;i<MAXDP;i++)
				ans=min(ans,DP[1][i]+a[0]+4*i);
			cout<<ans<<endl;
	}
}
