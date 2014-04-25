#include<iostream>
#include<vector>
#include<list>
#include<climits>
#include<map>
using namespace std;


#define INVALID (100000)
struct road
{
	int d;
	int l;
	int t;
	road(int D=0,int L=0,int T=0)
	{
		d=D;
		l=L;
		t=T;
	}
};

typedef vector<list<road> > graph;
graph G;

map<pair<int,int>,int > DP;
int solve(int s, int t)
{
	if(t<0)
		return INVALID;
	if(s==G.size()-1)
		return 0;
	else if(DP.find(make_pair(s,t))==DP.end())
	{
		DP[make_pair(s,t)]=INVALID;
		int MIN=INVALID;
		for(list<road>::iterator i=G[s].begin();i!=G[s].end();i++)
		{
			if(i->d==s)
				continue;
			MIN=min(MIN,i->l+solve(i->d,t-i->t));		
		}	
		DP[make_pair(s,t)]=min(INVALID,MIN);
	}
	return DP[make_pair(s,t)];
}
int main()
{
	//freopen("testL.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		DP.clear();
		
		int k;
		cin>>k;
		
		int n;
		cin>>n;
		
		G.assign(n,list<road>());
		
		int r;
		cin>>r;
		while(r--)
		{
			int a,b,l,t;
			cin>>a>>b>>l>>t;
			a--;
			b--;
			G[a].push_back(road(b,l,t));
		}
		
		int ans=solve(0,k);
		if(ans>=INVALID)
			cout<<-1<<endl;
		else
			cout<<ans<<endl;
	}
}

