#include<iostream>
#include<queue>
#include<list> 
#include<vector>
using namespace std;

typedef vector<list<int> > graph;

bool isBipartite(const graph &G)
{
	vector<int> colour(G.size());
	queue<int> Q;
	for(int i=0;i<G.size();i++)
	{
		if(!colour[i])
		{
			colour[i]=1;
			Q.push(i);
			while(!Q.empty())
			{
				int current=Q.front();
				Q.pop();
				for(list<int>::const_iterator i=G[current].begin();i!=G[current].end();i++)
				{
					if(colour[*i]==colour[current])
						return false;
					else if(!colour[*i])
					{
						colour[*i]=1^2^colour[current];							
						Q.push(*i);
					}
				}
			}
		}
	}
	return true;
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
	cout<<isBipartite(G);
}
