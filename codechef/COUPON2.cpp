#include<iostream>
#include<vector>
#include<limits>
using namespace std;


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		
		vector<vector<long long> > price  	(n,vector<long long>(m));
		vector<vector<long long> > discount	(n,vector<long long>(m));
		
		vector<vector<long long> > cost		(n,vector<long long>(m));
		
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin>>price[i][j];
		
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin>>discount[i][j];
				
		long long mincost=numeric_limits<long long>::max();
		for(int shop=0;shop<m;shop++)
		{
			cost[n-1][shop]=price[n-1][shop];
			mincost=min(cost[n-1][shop],mincost);
		}
		
		for(int item=n-2;item>=0;item--)
		{
			long long newmincost=numeric_limits<long long>::max();
				
			for(int shop=0;shop<m;shop++)
			{
				long long buysame	   = cost[item+1][shop];
				buysame-=(discount[item][shop]<price[item+1][shop]?discount[item][shop]:price[item+1][shop]);
				 
				long long buydifferent = mincost;
				cost[item][shop]=price[item][shop]+min(buysame,buydifferent);
				newmincost=min(newmincost,cost[item][shop]);
			}
			mincost=newmincost;
		}
		cout<<mincost<<endl;
	}
}
