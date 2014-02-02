#include<iostream>
#include<climits>
#include<vector>
#include<list>
using namespace std;

typedef vector<list<pair<int,int> > > graph;

void topologicalSortDFS(graph &G,int source,vector<bool> &isvisited,list<int> &topologicallySortedList)
{
	if(!isvisited[source])
	{
		isvisited[source]=true;
		for(list<pair<int,int> >::iterator i=G[source].begin();i!=G[source].end();i++)
			topologicalSortDFS(G,i->first,isvisited,topologicallySortedList);
		topologicallySortedList.push_front(source);
	}
}
void topologicalSort(graph &G,list<int> &topologicallySortedList)
{
	vector<bool> isvisited(G.size());
	for(int i=0;i<G.size();i++)
		topologicalSortDFS(G,i,isvisited,topologicallySortedList);
}



vector<int> shortestDistance(graph &G,int s)
{
	const int INFINITY = INT_MAX; // change here for negative values.
	vector<int> distances(G.size(),INFINITY);
	distances[s]=0;
	list<int> Tsortedlist;
	topologicalSort(G,Tsortedlist);
	for(list<int>::iterator i=Tsortedlist.begin();i!=Tsortedlist.end();i++)
		if(distances[*i]!=INFINITY)
			for(list<pair<int,int> >::iterator j=G[*i].begin();j!=G[*i].end();j++)
				distances[j->first]=min(distances[j->first],distances[*i]+j->second);
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
	vector<int> distances=shortestDistance(G,s);
	for(int i=0;i<distances.size();i++)
		cout<<distances[i]<<" ";
	
}
