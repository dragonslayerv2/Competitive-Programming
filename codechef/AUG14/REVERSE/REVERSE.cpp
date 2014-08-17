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
int dijkstras(const graph &G,int source,int destination)
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
	if(distances[destination]==INT_MAX)
		return -1;
	
	return distances[destination];	
}
int main()
{
	int n,m;
	cin>>n>>m;
	vector<list<pair<int,int> > > graph(n);
	while(m--)
	{
		int x,y;
		cin>>x>>y;
		x--;
		y--;
		graph[x].push_back(make_pair(y,0));
		graph[y].push_back(make_pair(x,1));
	}
	
	cout<<dijkstras(graph, 0, n-1);
}
