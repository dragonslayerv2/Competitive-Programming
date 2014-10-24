/*
	Name: Linearise the tree
	Copyright: 
	Author: Shobhit Saxena
	Date: 27/04/14 15:59
	Description: Linearise the tree so that all queries on decendents of a node can be converted to range queries.
*/

#include<iostream>
#include<vector>
#include<list>
using namespace std;

class linearTree
{
	public:
		typedef vector<list<int> > tree;
	private:
		int p=0;
		tree &T;
		
		int dfs(int node)
		{
			if(isvisited[node])
				return 0;
			else
			{
				p++;
				isvisited[node]=true;
				pos[node]=p;
				for(list<int>::iterator i=T[node].begin();i!=T[node].end();i++)
					child[node]+=dfs(*i);
				return 1+child[node];
			}		
		}
	public:
		vector<int> pos;
		vector<int> child;
		vector<bool> isvisited;
	linearTree(tree &t):T(t)
	{
		pos.resize(t.size());
		child.resize(t.size(),0);
		isvisited.resize(t.size(),false);
		dfs(0);
	}		
};

template<class T> class BIT
{
	public:
		typedef T value_type;
	private:
		vector<value_type> tree;
	public:
		BIT(){}
		
		BIT(int n)
		{
			assign(n);
		}
		
		void assign(int n)
		{
			tree.clear();
			tree.resize(n+1);
		}
	
	 	value_type read(size_t idx) const
		{
			value_type sum=0;
			while(idx>0)
			{
				sum+=tree[idx];
				idx-=(idx&(-idx));
			}
			return sum;
		}
		
		void increase(size_t idx, const value_type &val)
		{ 
			while (idx <= tree.size()-1)
			{ 
				tree[idx] += val; 
				idx += (idx & (- idx)); 
			}
		}
		value_type query(size_t a,size_t b) const
		{
			return read(b)-read(a-1);
		}
		void clear()
		{
			tree.clear();
		}
};

#include<cstdio>
int main()
{
//	freopen("test.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	
	linearTree::tree T(n);
		
	for(int i=1;i<=n-1;i++)
	{
		int a,b;
		cin>>a>>b;
		a--;
		b--;
		T[a].push_back(b);
		T[b].push_back(a);
	}	
	
	linearTree LT(T);
	vector<long long> values(n+1);
	BIT<int> isZero(n+1);

	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		values[LT.pos[i]]=x;
		if(!x){
			isZero.increase(LT.pos[i],1);
		}
	}
	
	while(m--)
	{
		char command;
		cin>>command;
		if(command=='U')
		{
			int node;
			cin>>node;
			node--;
			int value;
			cin>>value;
			values[LT.pos[node]]+=value;
			if(values[LT.pos[node]]==0){
				if(!isZero.query(LT.pos[node],LT.pos[node]))
					isZero.increase(LT.pos[node],1);
			}
			else 
			{
				if(isZero.query(LT.pos[node],LT.pos[node])){
					isZero.increase(LT.pos[node],-1);}
			}
		}
		else
		{
			int parent;
			cin>>parent;
			parent--;
			cout<<isZero.query(LT.pos[parent],LT.pos[parent]+LT.child[parent])<<endl;
		}
	}

}

