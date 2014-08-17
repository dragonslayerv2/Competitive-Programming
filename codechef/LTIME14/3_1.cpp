#include<stdio.h>
#include<iostream>
#include<cmath>
#include<queue>
#include<list>
#include<vector>
#include<map>
using namespace std;

template<class T> class rmq
{
	private:
		vector<vector<T> > RMQ;
	public:
		rmq()
		{
		}
		rmq(vector<T> &arr)
		{
	//------------------------------------------------
			int n=arr.size();
			RMQ.resize(n);
			int len=5+ceil(log(arr.size()));
			for(int i=0;i<n;i++)
			{
				RMQ[i].resize(len);
			}
			
			
	//----------------------------------------------
			for(int i=0;i<n;i++)
			RMQ[i][0]=arr[i];
	
			for(int j=1,p=2;p<=n;j++,p*=2)
			{
				for(int i=0;i+p<=n;i++)
				RMQ[i][j]=min(RMQ[i][j-1],RMQ[i+p/2][j-1]);
			}
		}
		
		T query(int i,int j)
		{
			
			int gap=j-i+1;
			int p=-1;
			int po=1;
	
			while(gap) // calculates 2^(floor(logk)) and floor(logk)
			{
				gap=gap/2;
				p++;
				po<<=1;
			}
			po/=2;
			
			return min(RMQ[i][p],RMQ[j-po+1][p]);
		}
};


class LCA
{
	public:
		typedef vector<list<int> > tree; // change this according to your problem.
	private:
		tree &T;
		
		vector<bool> istraversed;
		vector<int> level;
		vector<int> position;
		vector<pair<int,int> > rmqArray;
		rmq<pair<int,int> >  RMQ;
		
		void dfs(int source)
		{
			if(!istraversed[source])
			{
				istraversed[source]=true;
				position[source]=rmqArray.size();
				rmqArray.push_back(make_pair(level[source],source));
				for(tree::value_type::iterator i=T[source].begin();i!=T[source].end();i++)
				{
					if(!istraversed[*i])          // vertex point here
					{
						dfs(*i);	
						rmqArray.push_back(make_pair(level[source],source));	
					}
				}
			}
		}
		
		void bfs(int start)
		{
			queue<int> Q;
			level[start]=0;
			Q.push(start);
		
			while(!Q.empty())
			{
				int current=Q.front();
				Q.pop();
				for(tree::value_type::iterator i=T[current].begin();i!=T[current].end();i++)
				{
					if(level[*i]==-1)
					{
						level[*i]=level[current]+1;
						Q.push(*i);
					}
				}
			}
		}
		
		
	public:
		LCA(tree &t,int start=0):T(t)
		{
			level.resize(t.size(),-1);
			bfs(start);
		
			position.resize(t.size());
			istraversed.resize(t.size());
			dfs(start);
		
			RMQ=rmq<pair<int,int> >(rmqArray);
		}
		
		int query(int nodeA,int nodeB)
		{
			return RMQ.query(min(position[nodeA],position[nodeB]),max(position[nodeA],position[nodeB])).second;
		}	
};

typedef vector<list<int> > tree;

int main()
{
	int t;
	t=1;
	while(t--)
	{
		int n;
		cin>>n;
		tree T(n);
		for(int i=1;i<n;i++)
		{
			int a,b;
			cin>>a>>b;
			a--;
			b--;
			T[a].push_back(b);
			T[b].push_back(a);
		}
		LCA lca=LCA(T);	
		int q; 			// number of queries
		cin>>q; 
		while(q--)
		{
			int r;
			cin>>r;
			
			int a,b;
			cin>>a>>b;
			a--;
			b--;
			r--;
			
			int lca_ab = lca.query(a,b);
			int lca_ra = lca.query(r,a);
			int lca_rb = lca.query(r,b);
			int lca_rlca = lca.query(r,lca_ab);
			
			int ans;
			if((lca_ra==r||lca_rb==r)&&lca_rlca==lca_ab)
				ans=r;
			else if(lca_ra==a&&lca_ab!=a)
				ans=a;
			else if(lca_rb==b&&lca_ab!=b)
				ans=b;
			else if(lca_ra==a&&lca_rb==r)
				ans=r;
			else if(lca_ra==r&&lca_rb==b)
				ans=b;
			else if(lca_ra==a&&lca_ab==a)
				ans=lca_rb;
			else if(lca_rb==b&&lca_ab==b)
				ans=lca_ra;
			else
				ans=lca_ab;
			cout<<ans+1<<endl;
		}
	}
}
