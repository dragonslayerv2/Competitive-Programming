#include<iostream>
#include<vector>
#include<queue>
#include<climits>
#include<list>
using namespace std;

typedef vector<list<pair<long long,long long> > > graph;

struct cmp
{
	bool operator()(pair<long long,long long> a,pair<long long,long long> b)
	{
		return a>b;
	}
};
vector<long long> dijkstras(const graph &G,long long source)
{
	const long long INVALID = long long_MAX;
	priority_queue<pair<long long,long long>,vector<pair<long long,long long> >, cmp > Q;
	
	vector<bool> used(G.size(),false);  
	vector<long long> distances(G.size(),INVALID);  
	
	distances[source]=0;
	Q.push(make_pair(0,source));
	
	while(!Q.empty())
	{
		pair<long long,long long> current=Q.top();
		Q.pop();
		if(!used[current.second])
		{
			cout<<"AT "<<current.second;
			used[current.second]=true;
			for(list<pair<long long,long long> >::const_iterator i=G[current.second].begin();i!=G[current.second].end();i++)
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
long long main()
{
	freopen("test.txt","r",stdin);
	long long v,e;
	cin>>v>>e;
	graph G(v);
	while(e--)
	{
		long long a,b,w;
		cin>>a>>b>>w;
		G[a].push_back(make_pair(b,w));
	}
	long long s;
	cin>>s;
	vector<long long> distances=dijkstras(G,s);
	for(long long i=0;i<distances.size();i++)
		cout<<distances[i]<<" ";
}
