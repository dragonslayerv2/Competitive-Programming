#include<iostream>
#include<vector>
#include<list>
using namespace std;


typedef vector<list<int> > graph;

vector<bool> isvisited;

void dfs(graph & G,int source)
{
	if(!isvisited[source])
	{
		isvisited[source]=true;
		cout<<source;
		
		for(list<int>::iterator i=G[source].begin();i!=G[source].end();i++)
			dfs(G,*i);
	}
}
int main()
{
	graph G;
	int v;
	cin>>v;
	G.resize(v);
	
	int e;
	cin>>e;
	while(e--)
	{
		int a,b;
		cin>>a>>b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	
	int s;
	cin>>s;
	
	isvisited.resize(G.size());
	
	dfs(G,s);
}
