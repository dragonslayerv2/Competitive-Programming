#include<iostream>
#include<vector>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	
	int t;
	cin>>t;
	while(t--)
	{
		int w,e;
		cin>>e>>w;
		
		int n;
		cin>>n;
		vector<pair<int,int> > coins(n);
		for(int i=0;i<n;i++)
			cin>>coins[i].first>>coins[i].second;
		
		vector<int> DP(w-e+1,INT_MAX);
	
		DP[0]=0;
		for(int i=1;i<DP.size();i++)
			for(int j=0;j<n;j++)
				if(i-coins[j].second>=0&&DP[i-coins[j].second]<INT_MAX)
					DP[i]=min(DP[i],DP[i-coins[j].second]+coins[j].first);
		
		if(DP.back()>=INT_MAX)
			cout<<"This is impossible.";
		else 
			cout<<"The minimum amount of money in the piggy-bank is "<<DP.back()<<".";
		cout<<endl;
		
	}
}
