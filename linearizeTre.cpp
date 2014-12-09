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


int main()
{
	ios_base::sync_with_stdio(false);
	int n,m;
	cin>>n>>m;
	
	vector<int> values(n);
	for(int i=0;i<n;i++)
		cin>>values[i];
	
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
	
	BIT<int> bit(n);
	for(int i=0;i<n;i++){
		bit.increase(LT.pos[i],values[i]);
	}
	
	while(m--)
	{
		char command;
		cin>>command;
		if(command=='Q')
		{
			int parent;
			cin>>parent;
			parent--;
			cout<<bit.query(LT.pos[parent],LT.pos[parent]+LT.child[parent])<<endl;
		}
		else
		{
			int node,value;
			cin>>node>>value;
			node--;
			bit.increase(LT.pos[node],value-bit.query(LT.pos[node],LT.pos[node]));
		}
	}
}

