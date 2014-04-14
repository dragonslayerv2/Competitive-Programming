#include<stdio.h>
#include<vector>
using namespace std;

inline int count1(int i)
{
	int c=0;
	while(i)
	{
		c+=(i&1);
		i>>=1;
	}
	return c;
}

int main()
{
	int t;
	scanf("%d",&t);
	
	while(t--)
	{
		int n;
		scanf("%d",&n);
		vector<vector<int> > grid(n,vector<int>(n));
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				scanf("%d",&grid[i][j]);
		vector<long long> DP(1<<n);
		DP.back()=1;
		for(int i=(1<<n)-2;i>=0;i--)
		{
			int studentNumber=count1(i);
			for(int j=0;j<n;j++)
				if(grid[studentNumber][j]==1&&!(i&(1<<j)))
					DP[i]+=DP[i|(1<<j)];
		}	
		printf("%lld\n",DP[0]);
	}
}
