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
void computeSCCDFS(graph &G,int source,int SCCNumber,vector<int> &SCC)
{
	if(SCC[source]==-1)
	{
		SCC[source]=SCCNumber;
		for(list<int>::iterator i=G[source].begin();i!=G[source].end();i++)
			computeSCCDFS(G,*i,SCCNumber,SCC);
	}
}
int computeSCC(graph &G,vector<int> &SCC)
{
	//--------- reverse Graph----------------
	graph GR(G.size());
	for(int i=0;i<G.size();i++)
		for(list<int>::iterator j=G[i].begin();j!=G[i].end();j++)
			GR[*j].push_back(i);
	//--------------------------------------
	list<int> topologicallySortedList;
	topologicalSort(GR,topologicallySortedList);
	//--------------------------------------
	SCC.resize(G.size(),-1);
	int SCCNumber=0;
	while(topologicallySortedList.size())
	{
	
		if(SCC[topologicallySortedList.front()]==-1)
			computeSCCDFS(G,topologicallySortedList.front(),SCCNumber++,SCC);
		topologicallySortedList.pop_front();
	}
	return SCCNumber;
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
	
	vector<int> SCC;
	cout<<computeSCC(G,SCC)<<endl;
	for(int i=0;i<SCC.size();i++)
		cout<<SCC[i]<<" ";
}
