#include<iostream>
#include<vector>
#include<list>
using namespace std;


typedef vector<list<int> > graph;

//------------------------------------------------------------------------------
int p=0;
vector<int> pos;
vector<int> child;
vector<bool> isvisited;
vector<long long> skills;
graph G;
//------------------------------------------------------------------------------
long long dfs(graph &G,int node)
{
	if(isvisited[node])
		return 0;
	else
	{
		p++;
		isvisited[node]=true;
		pos[node]=p;
		for(list<int>::iterator i=G[node].begin();i!=G[node].end();i++)
			child[node]+=dfs(G,*i);
		return 1+child[node];
	}
}
//------------------------------------------------------------------------------
class BIT
{
	vector<long long> tree;
	int n;
	
	public:
		BIT(size_t N)
		{
			n=N;
			tree.resize(n+1);
		}
		long long read(int idx)
		{
			int sum=0;
			while(idx>0)
			{
				sum+=tree.at(idx);
				idx-=(idx&(-idx));
			}
			return sum;
		}
		
		void increase(int idx, int val)
		{ 
			while (idx <= n)
			{ 
				tree.at(idx) += val; 
				idx += (idx & (- idx)); 
			}
		}
		long long query(int a,int b)
		{
			return read(b)-read(a-1);
		}
};
//------------------------------------------------------------------------------


int main()
{
	int n,m;
	cin>>n>>m;
	
	pos.resize(n+1);
	child.resize(n+1,0);
	isvisited.resize(n+1,false);
	skills.resize(n+1);
	G.resize(n+1);
	for(int i=1;i<=n;i++)
		cin>>skills[i];
	
	for(int i=1;i<=n-1;i++)
	{
		int a,b;
		cin>>a>>b;
		G[a].push_back(b);
		G[b].push_back(a);
	}	
	dfs(G,1);

	BIT bit(n);
	for(int i=1;i<=n;i++)
		bit.increase(pos[i],skills[i]);
	
	while(m--)
	{
		char command;
		cin>>command;
		if(command=='Q')
		{
			int parent;
			cin>>parent;
			cout<<bit.query(pos[parent],pos[parent]+child[parent])<<endl;
		}
		else
		{
			int node,value;
			cin>>node>>value;
			bit.increase(pos[node],value-bit.query(pos[node],pos[node]));
		}
	}

}

