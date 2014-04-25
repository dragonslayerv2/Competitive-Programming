#include<stdio.h>
#include<iostream>
#include<climits>
#include<vector>
using namespace std;

int main()
{	
	while(1)
	{
		int n,T;
		scanf("%d%d",&n,&T);
		if(n==0&&T==0)
			break;
		vector<vector<int> > time(n,vector<int>(n));
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				scanf("%d",&time[i][j]);
				
		vector<vector<int> > risk(n,vector<int>(n));
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++)
				scanf("%d",&risk[i][j]);
		
		vector<vector<long long> > DP(T+1,vector<long long>(n,INT_MAX));
		
		for(int i=0;i<=T;i++)
			DP[i][n-1]=0;
		
		for(int i=0;i<=T;i++)
			for(int j=0;j<n;j++)
				for(int k=0;k<n;k++)
				{
					
					if(i-time[j][k]>=0)
						DP[i][j]=min(risk[j][k]+DP[i-time[j][k]][k],DP[i][j]);
				}
		/*
		for(int i=0;i<T;i++)
		{
			for(int j=0;j<DP[i].size();j++)
				cout<<DP[i][j]<<"\t";
			cout<<endl;
		}*/
		
		if(DP[T][0]>=INT_MAX)
			printf("%d\n",-1);		
		else
		{
			int t=T;
			while(t>=0&&DP[T][0]==DP[t][0])
				t--;
			printf("%lld %d\n",DP[T][0],t+1);
		}
	}
}
