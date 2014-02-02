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
vector<int> dijkstras(const graph &G,int source)
{
	const int INVALID = INT_MAX;
	priority_queue<pair<int,int>,vector<pair<int,int> >, cmp > Q;
	
	vector<bool> used(G.size(),false);  
	vector<int> distances(G.size(),INVALID);  
	
	distances[source]=0;
	Q.push(make_pair(source,0));
	
	while(!Q.empty())
	{
		pair<int,int> current=Q.top();
		Q.pop();
		if(!used[current.second])
		{
			used[current.second]=true;
			for(list<pair<int,int> >::const_iterator i=G[current.second].begin();i!=G[current.second].end();i++)
			{
				if(distances[i->first]>distances[current.second]+i->second)
				{
					distances[i->first]=distances[current.second]+i->second;
					Q.push(make_pair(distances[i->first],i->first));
				}
					
			}
		}
	}
	return distances;	
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
	vector<int> distances=dijkstras(G,s);
	for(int i=0;i<distances.size();i++)
		cout<<distances[i]<<" ";
}
