#include<iostream>
#include<vector>
#include<cstdio>
#include<list>
using namespace std;

#define INVALID_NUMBER -1
#define INVALID_EDGE -1

typedef vector<list<pair<int,int> > > graph; 

void calculateBridges(int currentNode,
	int &time,
	const graph &G, 
	vector<int> &dfsNumbers, 
	vector<int> &low,
	vector<int> &bridges,
	int parentEdge=INVALID_EDGE){
	
	if(dfsNumbers[currentNode]==INVALID_NUMBER)
	{
		dfsNumbers[currentNode]=low[currentNode]=(++time);	
		for(list<pair<int,int> >::const_iterator i=G[currentNode].begin();i!=G[currentNode].end();i++)
		{
			int currentEdge=i->second;
			if(currentEdge!=parentEdge){
				int destination = i->first;
				calculateBridges(destination, time, G, dfsNumbers, low, bridges,currentEdge);
				if(low[destination]>dfsNumbers[currentNode])
					bridges.push_back(currentEdge);
				low[currentNode]=min(low[currentNode],low[destination]);
			}
		}
	}
}

int main(){
	ios::sync_with_stdio(false);	
	freopen("bridges.in","r",stdin);
	freopen("bridges.out","w",stdout);
	int n,m;
	cin>>n>>m;
	
	graph G(n);
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		a--;
		b--;
		G[a].push_back(make_pair(b,i));
		G[b].push_back(make_pair(a,i));
	}
	
	vector<int> bridges;
	vector<int> low(n);
	vector<int> dfsNumber(n,INVALID_NUMBER);
	
	bridges.reserve(m);
	int initialTime = 0;
	for(int i=0;i<n;i++)
		calculateBridges(i, initialTime, G, dfsNumber, low, bridges);
	
	cout<<bridges.size()<<endl;
	for(int i=0;i<bridges.size();i++)
		cout<<bridges[i]+1<<" ";
}
