/*
	Name: Biconnected Componenets
	Copyright: 
	Author: Shobhit Saxena
	Date: 02/02/14 11:55
	Description: A graph is biconnected if there exist 2 vertex disjoint paths b/w every pair of vertices.
				 
*/

#include<iostream>
#include<vector>
#include<list>
using namespace std;


typedef vector<list<int> > graph;

int biconnectedComponenetsDFS(graph &G,vector<bool> &isVisited,int v,int DFN,vector<int> &dfn,vector<int> &low)
{
	int child=0;
	bool cutvertex=false;
	isVisited[v]=true;
	low[v]=dfn[v]=DFN;
	int count=0;
	for(list<int>::iterator i=G[v].begin();i!=G[v].end();i++)
	{
		if(!isVisited[*i])
		{
			child++;
			count+=biconnectedComponenetsDFS(G,isVisited,*i,++DFN,dfn,low);
			low[v]=min(low[v],low[*i]);			
			
			if(low[*i]>=dfn[v]) cutvertex=true;
		}
		else
			low[v]=min(low[v],dfn[*i]);
	}
	
	if(!dfn[v])
	{
		if(child>1)
			return count+1;
		else
			return count;
	}
	else if(cutvertex)
	{
		return count+1;
	}
	else return count;
}


bool isBiconnected(graph &G)
{
	vector<bool> isVisited(G.size());
	vector<int>  dfn(G.size()), low(G.size());
	int count=biconnectedComponenetsDFS(G,isVisited,0,0,dfn,low);
	if(!count)
	{
		for(int i=0;i<G.size();i++)
			if(!isVisited[i])	return false;
		return true;
	}
	else
		return false;
}
int main()
{
	int v,e;
	cin>>v>>e;
	graph G(v);
	while(e--)
	{
		int a,b;
		cin>>a>>b;
		G[a].push_back(b);
		G[b].push_back(a);
	}
	cout<<isBiconnected(G);
}
