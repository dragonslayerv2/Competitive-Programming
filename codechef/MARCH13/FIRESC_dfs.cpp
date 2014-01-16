/*
	Name: Connected Components
	Copyright: 
	Author: Shobhit Saxena 
	Date: 06/03/13 00:33
	Description: This code uses dfs to find the disconnected components of a graph. DFS here returns the no of nodes in a connected component.
*/


#include<iostream>
#include<list>
#include<vector>
using namespace std;

#define MOD 1000000007

int dfs(vector<list<int> > &graph,vector<int> &isVisited, int i,int setno)
{
	isVisited[i]=setno;
	int count=1;
	
	list<int>::const_iterator j;
	for(j=graph[i].begin();j!=graph[i].end();j++)
	{
		if(!isVisited[*j]) count+=dfs(graph,isVisited,*j,setno);
	}
	return count;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		vector<list<int> > graph(n+1);
		while(m--)
		{
			int a,b;
			cin>>a>>b;
			graph[a].push_back(b);
			graph[b].push_back(a);
		}
	
	
		vector<int> isVisited(n+1);
		int components=1;
		long long ways=1;
		for(int i=1;i<=n;i++)
		{
			if(!isVisited[i])
				ways=(ways*dfs(graph,isVisited,i,components++))%MOD;
		}
		cout<<components-1<<" "<<ways<<endl;
	}
	return 0;
}
