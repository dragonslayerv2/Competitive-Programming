#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<list>
using namespace std;

typedef vector<list<pair<int,int> > > graph;


struct cmp
{
	bool operator()(pair<int,int> a,pair<int,int> b)
	{
		return a>b;
	}
};

int prims(const graph &G,int source)
{
	const int INVALID = INT_MAX;
	priority_queue<pair<int,int>,vector<pair<int,int> >, cmp > Q;
	
	vector<bool> used(G.size(),false);  
	vector<int> distances(G.size(),INVALID);  
	
	distances[source]=0;
	Q.push(make_pair(0,source));
	
	int weight=0;
	while(!Q.empty())
	{
		pair<int,int> current=Q.top();
		Q.pop();
		if(!used[current.second])
		{
			used[current.second]=true;
			weight+=current.first;
			for(list<pair<int,int> >::const_iterator i=G[current.second].begin();i!=G[current.second].end();i++)
			{
				if(!used[i->first]&&distances[i->first]>i->second)
				{
					distances[i->first]=i->second;
					Q.push(make_pair(distances[i->first],i->first));
				}	
			}
		}
	}
	return weight;	
}
int main()
{
	freopen("test.txt","r",stdin);
	int v,e;
	cin>>v>>e;
	graph G(v);
	while(e--)
	{
		int a,b,w;
		cin>>a>>b>>w;
		G[a].push_back(make_pair(b,w));
	}
	int s;
	cin>>s;
	cout<<prims(G,s);
}
