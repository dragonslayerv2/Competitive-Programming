//http://acm.timus.ru/problem.aspx?space=1&num=1018
#include<iostream>
#include<list>
#include<queue>
#include<climits>
#include<vector>
using namespace std;

typedef vector<list<pair<int,int> > > graph;

graph G;
vector<int> level;
vector<int> nodeWeight;
vector<int> childrenWeight;
vector<bool> removed;

void dfs(int pos)
{
	childrenWeight[pos]=nodeWeight[pos];
	for(list<pair<int,int> >::iterator i=G[pos].begin();i!=G[pos].end();i++)
	{
		if(level[i->first]>level[pos]&&!removed[i->first])
		{
			dfs(i->first);
			childrenWeight[pos]+=childrenWeight[i->first];
		}			
	}

}

int main()
{
//	freopen("test.txt","r",stdin);
	int n,q;
	cin>>n>>q;
	
	G.resize(n+1);
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		cin>>a>>b;
		int w;
		cin>>w;	
		G[a].push_back(make_pair(b,w));
		G[b].push_back(make_pair(a,w));
	}
	
	level.resize(n+1,-1);
	
	level[1]=1;
	
	queue<int> Q;
	Q.push(1);
	while(!Q.empty())
	{
		int current=Q.front();
		Q.pop();
		
		for(list<pair<int,int> >::iterator i=G[current].begin();i!=G[current].end();i++)
		{
			if(level[i->first]==-1)
			{
				level[i->first]=level[current]+1;
				Q.push(i->first);
			}
		}
	}
	
	nodeWeight.resize(n+1);
	for(int i=1;i<=n;i++)
		for(list<pair<int,int> >::iterator j=G[i].begin();j!=G[i].end();j++)
		{	
			if(level[i]>level[j->first])
				nodeWeight[i]=j->second;
			else
				nodeWeight[j->first]=j->second;
		}
	childrenWeight.resize(n+1,0);	
	removed.resize(n+1,false);
	while(n-1>q)
	{	
		dfs(1);
		
		int minChild=INT_MAX;
		int minNode=-1;
		for(int i=1;i<=n;i++)
			if(!removed[i]&&childrenWeight[i]<minChild)
			{
				minChild=childrenWeight[i];
				minNode=i;
			}
		if(minNode==-1)
			break;
		removed[minNode]=true;
		n--;
	}
	dfs(1);
	cout<<childrenWeight[1];
}
