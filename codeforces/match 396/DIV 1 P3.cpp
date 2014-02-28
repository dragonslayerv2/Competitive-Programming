#include<iostream>
#include<list>
#include<vector>
using namespace std;

#define MOD 1000000007LL

template<class T> class BIT
{
	public:
		typedef T value_type;
	private:
		vector<value_type> tree;
		
		void increase(long long idx, const value_type &val)
		{ 
			while (idx <= tree.size()-1)
			{ 
				tree[idx] += val; 
				tree[idx] %=MOD;
				idx += (idx & (- idx)); 
			}
		}
	public:
		BIT(){}
		
		BIT(size_t n)
		{
			assign(n);
		}
		
		void assign(int n)
		{
			tree.clear();
			tree.resize(n+1);
		}
	
	 	value_type query(long long idx) const
		{
			value_type sum=0;
			while(idx>0)
			{
				sum+=tree[idx];
				sum%=MOD;
				idx-=(idx&(-idx));
			}
			return sum;
		}
		
		value_type update(long long a,long long b,const value_type &value)
		{
			increase(a,value);
			increase(b+1,MOD-(value)%MOD);
			
		}
		void clear()
		{
			tree.clear();
		}
};


typedef vector<list<int> > graph;
int present;
int linearize(graph &G,vector<int> &position,vector<int> &children,vector<int> &level,vector<bool> &isVisited,int source,int l)
{
	if(!isVisited[source])
	{
		isVisited[source]=true;
		position[source]=present++;
		level[source]=l;
		children[source]=0;

		for(list<int>::iterator i=G[source].begin();i!=G[source].end();i++)
			children[source]+=linearize(G,position,children,level,isVisited,*i,l+1);
		return children[source]+1;
	}
	return 0;
}
int main()
{
	int n;
	cin>>n;
	
	graph G(n+1);
	
	for(int i=2;i<=n;i++)
	{
		int a;
		cin>>a;
		G[a].push_back(i);
		G[i].push_back(a);
	}		
	
	vector<int> position(n+1);
	vector<int> children(n+1);
	vector<int> level(n+1);
	vector<bool> isVisited(n+1);	
	
	present=1;
	linearize(G,position,children,level,isVisited,1,0);
	
	BIT<long long> T1(n+1),T2(n+1);
	int q;
	cin>>q;
	while(q--)
	{
		int type;
		cin>>type;
		if(type==1)
		{
			int v;
			long long x,k;
			cin>>v>>x>>k;
			T1.update(position[v],position[v]+children[v],(x+level[v]*k)%MOD);
			T2.update(position[v],position[v]+children[v],k);
		}
		else
		{
			int v;
			cin>>v;
			
			cout<<(MOD+T1.query(position[v])%MOD-(T2.query(position[v])*level[v])%MOD)%MOD;
			cout<<endl;
		}
	}
	
	

}
