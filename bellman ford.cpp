#include<iostream>
#include<vector>
#include<list>
#include<limits.h>
using namespace std;


struct edge
{
	int a,b;
	int w;
};



vector<long long> belmanford(int v,vector<edge> &edges,int source)
{
	vector<long long> distance(v,INT_MAX);
	distance[source]=0;
	for(int i=0;i<v-1;i++)
	{
		for(int j=0;j<edges.size();j++)
		{
			if(distance[edges[j].b]>distance[edges[j].a]+edges[j].w)
				distance[edges[j].b]=distance[edges[j].a]+edges[j].w;
		}
	}
	
	for(int j=0;j<edges.size();j++)
	{
		if(distance[edges[j].b]>distance[edges[j].a]+edges[j].w)
			return vector<long long>();
	}
	return distance;
	
}
int main()
{
	int v;
	cout<<"Enter the number of vertices = ";
	cin>>v;
	
	
	int e;
	cout<<"Enter the number of edges = ";
	cin>>e;
	
	vector<edge> edges(e);
	cout<<"Enter the edges.\n";
	for(int i=0;i<e;i++)
		cin>>edges[i].a>>edges[i].b>>edges[i].w;
	
	int source;
	cout<<"Enter source";
	cin>>source;
	
	vector<long long> distance=belmanford(v,edges,source);
	if(distance.empty())
		cout<<"Negative weight cycle";
	else
		for(int i=0;i<distance.size();i++)
		{
			cout<<distance[i]<<" ";
		}
		
}
