#include<iostream>
#include<vector>
#include<list>
#include<climits>
using namespace std;

typedef vector<list<pair<int,int> > > graph;


int getmin(vector<long long> &cost,vector<bool>& isused)
{
	int minpos=-1;
	int MIN=INT_MAX;
	
	for(int i=0;i<cost.size();i++)
	{
		if(!isused[i]&&cost[i]<MIN)
		{
			MIN=cost[i];
			minpos=i;
		}
	}
	return minpos;
}
int prims(graph &G,int source)
{
	vector<long long> cost(G.size(),INT_MAX);
	vector<bool> isused(G.size(),false);	
	
	cost[source]=0;
	
	long long totalcost=0;

	for(int i=0;i<G.size();i++)
	{
		int minpos=getmin(cost,isused);
		isused[minpos]=true;
		totalcost+=cost[minpos];
		
		for(list<pair<int, int> >::iterator i=G[minpos].begin();i!=G[minpos].end();i++)
			if(cost[i->first]>i->second)
				cost[i->first]=i->second;
	}
	return totalcost;
}
int main()
{
	int v;
	cin>>v;
	graph G(v);
	
	int e;
	cin>>e;
	while(e--)
	{
		int a,b,w;
		cin>>a>>b>>w;
		G[a].push_back(make_pair(b,w));
		G[b].push_back(make_pair(a,w));
	}
	
	int source;
	cin>>source;
	cout<<"Weight of minimum spanning tree = "<<prims(G,source);
}
