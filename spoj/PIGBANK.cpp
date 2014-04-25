#include<stdio.h>
#include<algorithm>
#include<vector>
#include<climits>
using namespace std;

inline bool cmp(pair<int,int>  coinA,pair<int,int> coinB)
{
	double a=coinA.first;
	a/=coinA.second;
	double b=coinB.first;
	b/=coinB.second;
	return a<b;
}


int DP[505][10005];
int main()
{
//	freopen("testD.txt","r",stdin);
	
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int w,e;
		scanf("%d %d",&e,&w);
		w-=e;
		
		int n;
		scanf("%d",&n);
		vector<pair<int,int> > coins(n);

		for(int i=0;i<n;i++)
			scanf("%d %d",&coins[i].first,&coins[i].second);
		
		for(int i=0;i<=n;i++)
			for(int W=0;W<=w;W++)
				DP[i][W]=INT_MAX;
		
		sort(coins.rbegin(),coins.rend(),cmp);
		
		int min=INT_MAX;
		for(int i=0;i<n;i++)
		DP[n][0]=0;
		
		for(int i=n;i>=1;i--)
			for(int W=w;W>=0;W--)
			{
				if(DP[i][W]<INT_MAX)
				{
					for(int count=0;W+count*coins[i-1].second<=w;count++)
					{
						if(DP[i-1][W+count*coins[i-1].second]<DP[i][W]+count*coins[i-1].first)
							break;
						
						DP[i-1][W+count*coins[i-1].second]=DP[i][W]+count*coins[i-1].first;
					}
				}
			}	
						
				
		if(DP[0][w]>=INT_MAX)
			printf("This is impossible.");
		else 
			printf("The minimum amount of money in the piggy-bank is %d.",DP[0][w]);
		printf("\n");
	}
}
