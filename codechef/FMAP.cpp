#include<iostream>
#include<list>
#include<vector>
using namespace std;

typedef vector<list<int> > graph;

vector<int> parent;
vector<bool> isvisited;
		
		
void dfs(graph &G,int node,int parent)
{
	if(isvisited[node])
		return;
		
	isvisited[node]=true;
	::parent[node]=parent;
	for(auto i=G[node].begin();i!=G[node].end();i++)
	{
		dfs(G,*i,node);		
	}
}
int main()
{
	int t;
	cin>>t;
	
	
	while(t--)
	{
		int n,hq1,hq2;
		cin>>n>>hq1>>hq2;
		
		graph G(n+1);
		parent.assign(n+1,0);
		isvisited.assign(n,false);
		for(int i=1;i<=n;i++)
		{
			if(i!=hq1)
			{
				int a;
				cin>>a;
				G[i].push_back(a);	
				G[a].push_back(i);
			}
		}
		
		dfs(G,hq2,hq2);
		
		for(int i=1;i<=n;i++)
		{
			if(i!=hq2)
			{
				cout<<parentaq[i]<<" ";
			}
		}
		
	}
}
