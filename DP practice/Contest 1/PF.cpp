#include<iostream>
#include<vector>
using namespace std;

int main()
{
	while(1)
	{
		int b,n;
		scanf("%d %d",&b,&n);
		if(b==0&&n==0)
			return 0;
		
		vector<pair<int,int> > parties(n);
		for(int i=0;i<n;i++)
			scanf("%d %d",&parties[i].first,&parties[i].second);
		
		
		vector<vector<int> > DP(n+1,vector<int>(b+1));
		for(int i=n-1;i>=0;i--)
			for(int j=0;j<=b;j++)
			{
				DP[i][j]=DP[i+1][j];
				if(j-parties[i].first>=0)
					DP[i][j]=max(DP[i][j],DP[i+1][j-parties[i].first]+parties[i].second);
			}
	
		while(b>0&&DP[0][b-1]==DP[0][b])
			b--;
		printf("%d %d\n",b,DP[0][b]);
	}
	
}
