#include<iostream>
#include<vector>
#include<list>
#include<queue>
#include<climits>
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
	Q.push(make_pair(0,source));
	
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

struct edge{
	int a,b,l;
	edge(int a,int b,int l){
		this->a=a;
		this->b=b;
		this->l=l;
	}
};

int main(){
	int n,e;
	cin>>n>>e;
	graph G(n);
	
	vector<edge> E;
	while(e--){
		int a,b,l;
		cin>>a>>b>>l;
		G[a].push_back(make_pair(b,l));
		G[b].push_back(make_pair(a,l));
		E.push_back(edge(a,b,l));
	}
	
	vector<int> distance0=dijkstras(G,0);
	vector<int> distanceP=dijkstras(G,n-1);
	
	long long ans=0;
	for(int i=0;i<E.size();i++)
		if(distance0[E[i].a]+E[i].l+distanceP[E[i].b]==distance0[n-1]||distance0[E[i].a]+E[i].l+distanceP[E[i].b]==distance0[n-1])
			ans+=E[i].l;
	cout<<ans*2;
	
}
