#include<iostream>
#include<limits>
#include<vector>
using namespace std;


vector<vector<long long> > myhash;
vector<vector<bool> >exist;

long long buy(int item,int shop,vector <vector<long long> > &prices,vector<vector<long long> > &discount)
{
	if(item==prices.size()-1)
		return prices[item][shop];
	else
	{
		if(exist[item][shop])
			return myhash[item][shop];
		else
		{
			long long cost=prices[item][shop];
	
			long long buysame=buy(item+1,shop,prices,discount);
			buysame-=(discount[item][shop]<prices[item+1][shop]?discount[item][shop]:prices[item+1][shop]);
		
			long long buydifferent=numeric_limits<long long>::max();
				
			for	(int i=0;i<prices[item].size();i++)
				if(i!=shop)
					buydifferent=min(cost,buy(item+1,i,prices,discount));
		
			long long result=cost+min(buydifferent,buysame);
			
			exist[item][shop]=true;
			myhash[item][shop]=result;
			
			return result;
		}
	}
}



int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		
		vector<vector<long long> > prices  (n,vector<long long>(m));
		vector<vector<long long> > discount(n,vector<long long>(m));
		myhash.clear();
		exist.clear();
		myhash.resize(n,vector<long long>(m));
		exist.resize(n,vector<bool>(m,false));
		
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin>>prices[i][j];
		
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin>>discount[i][j];

		long long cost=numeric_limits<long long>::max();
		
		for(int j=0;j<m;j++)
				cost=min(cost,buy(0,j,prices,discount));
		
		cout<<cost<<endl;
	}
}
