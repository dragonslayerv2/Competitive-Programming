#include<iostream>
#include<vector>
using namespace std;

int main()
{
//	freopen("testC.txt","r",stdin);
	int n,t;
	cin>>n>>t;
	
	vector<pair<int,int> > items[6];
	for(int i=0;i<n;i++)
	{
		int item;
		cin>>item;
		item--;
		
		int p,q;
		cin>>p>>q;
		if(item<0||item>5) continue;
		items[item].push_back(make_pair(p,q));
	}
	vector<vector<int> > DP(6,vector<int>(t+1,0));
	
	for(int i=0;i<=t;i++)
		for(int j=0;j<items[5].size();j++)
			if(items[5][j].first<=i)
				DP[5][i]=max(DP[5][i],items[5][j].second);
	
	for(int i=4;i>=0;i--)
		for(int j=0;j<=t;j++)
			for(int k=0;k<items[i].size();k++)
				if(j-items[i][k].first>=0)
					DP[i][j]=max(DP[i][j],min(items[i][k].second,DP[i+1][j-items[i][k].first]));
			
	cout<<DP[0][t];
}

