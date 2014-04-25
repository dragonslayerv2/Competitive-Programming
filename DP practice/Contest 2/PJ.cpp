#include<iostream>
#include<vector>
using namespace std;

int main()
{
	freopen("test.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		n=2*n;
		vector<bool> isBracket(n);
		for(int i=0;i<k;i++)
		{
			int a;
			cin>>a;
			isBracket[a-1]=true;
		}
		
		vector<vector<int> > DP(n+1,vector<int>(n/2+1));
		
		DP[n][0]=1;
		
		for(int i=n-1;i>=0;i--)
			for(int openCount=0;openCount<=n/2;openCount++)
			{
				if(isBracket[i])
				{
					if(openCount+1<=n/2)
						DP[i][openCount]=DP[i+1][openCount+1];
				}
				else
				{
					if(openCount-1>=0)
						DP[i][openCount]+=DP[i+1][openCount-1];
					if(openCount+1<=n/2)
						DP[i][openCount]+=DP[i+1][openCount+1];
				}
			}
		
		cout<<DP[0][0]<<endl;
	}
}
