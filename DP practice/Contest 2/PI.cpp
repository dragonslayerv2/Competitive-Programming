#include<iostream>
#include<vector>
#include<map>
#include<climits>
using namespace std;

typedef pair<int,pair<int,bool> > state;
#define make_state(a,b,c) make_pair(a,make_pair(b,c))

vector<int> rock;
map<state,long long> DP;

long long solve(int i, int cost,bool taken)
{
	if(i==rock.size())
	{
		if(!taken)
			return 0;
		else if(taken)
		{
			if(cost<=0)
				return INT_MIN;
			else
				return 0;
		}
	}
	
	else if(DP.find(make_state(i,cost,taken))==DP.end())
	{
		if(taken)
		{
			if(cost<=0)
				DP[make_state(i,cost,taken)]=1+solve(i+1,cost+rock[i],true);
			else
				DP[make_state(i,cost,taken)]=max(1+solve(i+1,cost+rock[i],true),solve(i+1,0,false));
		}
		else
		{
			DP[make_state(i,cost,taken)]=max(1+solve(i+1,rock[i],true),solve(i+1,0,false));
		}
	}
	return DP[make_state(i,cost,taken)];
}
int main()
{
//	freopen("testJ.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		DP.clear();
		int n;
		cin>>n;
		
		rock.assign(n,0);
		string a;
		cin>>a;		
		for(int i=0;i<a.size();i++)
		{
			if(a[i]=='1') rock[i]=1;
			else		  rock[i]=-1;
		}
		cout<<solve(0,0,false)<<endl;
	}
}
