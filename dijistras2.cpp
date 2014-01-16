#include<iostream>
#include<climits>
#include<list>
#include<vector>
using namespace std;

typedef vector<list<pair<int,int> > > graph;

int getmin(vector<long long>&distance,vector<bool> &isused)
{
	long long MIN=INT_MAX;
	int minpos=-1;
	for(int i=0;i<distance.size();i++)
		if(!isused[i]&&MIN>distance[i])
		{
			MIN=distance[i];
			minpos=i;
		}
	return minpos;
}
vector<long long> dijkstras(graph &G,int source)
{
	vector<long long>	 distance(G.size(),INT_MAX);
	vector<bool> isused(G.size(),false);
	
	distance[source]=0;
	
	for(int i=0;i<G.size();i++)
	{
		//--extract min operation-----
		int minnode=getmin(distance,isused);
		isused[minnode]=true;
		//--------------------------
		cout<<"MINNODE = "<<minnode<<"distance"<<distance[minnode]<<endl;
		for(list<pair<int,int> >::iterator i=G[minnode].begin();i!=G[minnode].end();i++)
		{
			if(distance[i->first]>distance[minnode]+i->second)
				distance[i->first]=distance[minnode]+i->second;
		}
	}
	return distance;
	
}

int main()
{
	int v;
	cin>>v;
	graph G(v);
	
	int e;
	cin>>e;
	
	while(e--)
	{
		int a,b,w;
		cin>>a>>b>>w;
		
		G[a].push_back(make_pair(b,w));	
	//	G[b].push_back(make_pair(a,w));	
	}
	
	int source;
	cin>>source;
	vector<long long> distances=dijkstras(G,source);
	
	for(int i=0;i<distances.size();i++)
		cout<<distances[i]<<"\t";
	cout<<endl;
}
