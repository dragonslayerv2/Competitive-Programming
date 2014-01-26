#include<iostream>
#include<vector>
#include<list>
using namespace std;

typedef vector<list<int> > graph;

void topologicalSortDFS(graph &G,int source,vector<bool> &isvisited,list<int> &topologicallySortedList)
{
	if(!isvisited[source])
	{
		isvisited[source]=true;
		for(list<int>::iterator i=G[source].begin();i!=G[source].end();i++)
			topologicalSortDFS(G,*i,isvisited,topologicallySortedList);
		topologicallySortedList.push_front(source);
	}
}
void topologicalSort(graph &G,list<int> &topologicallySortedList)
{
	vector<bool> isvisited(G.size());
	for(int i=0;i<G.size();i++)
		topologicalSortDFS(G,i,isvisited,topologicallySortedList);
}

int main()
{
//	freopen("test.txt","r",stdin);
	int v,e;
	cin>>v>>e;
	graph G(v);
	while(e--)
	{
		int a,b;
		cin>>a>>b;
		G[a].push_back(b);
	}	
	list<int> topologicallySortedList;
	topologicalSort(G,topologicallySortedList);
	
	for(list<int>::iterator i=topologicallySortedList.begin();i!=topologicallySortedList.end();i++)
		cout<<*i<<" ";
}
