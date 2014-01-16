#include<iostream>
#include<vector>
#include<list>
#include<queue>
using namespace std;

typedef vector<list<int> > graph;


void bfs(graph &G,int source)
{
	vector<bool> isvisited(G.size(),false);
	
	queue<int> Q;
	Q.push(source);
	isvisited[source]=true;
	
	while(!Q.empty())
	{
		int current=Q.front();
		Q.pop();
		
		cout<<current<<" ";
		
		for(list<int>::iterator i=G[current].begin();i!=G[current].end();i++)
		{
			if(!isvisited[*i])
			{
				isvisited[*i]=true;
				Q.push(*i);
			}
		}
	}
}
int main()
{
	cout<<"Enter the number of vertices";
	int v;
	cin>>v;
	graph G(v);
	
	int e;
	cout<<"Enter the number of edges";
	cin>>e;
	
	cout<<"Enter edges\n";
	for(int i=0;i<e;i++)
	{
		int a,b;
		cin>>a>>b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	int source;
	cout<<"Enter source";	
	cin>>source;
	
	bfs(G,source);
	
}
