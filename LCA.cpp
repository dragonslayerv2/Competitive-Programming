#include<stdio.h>
#include<cmath>
#include<queue>
#include<list>
#include<vector>
#include<map>
using namespace std;

vector<bool> istraversed;
void dfs(vector<list<pair<int,long long> > > &graph,vector<int> &level,vector<int> &position,vector<pair<int,long long> > &rmqarray,int source=0)
{
	
	if(!istraversed[source])
	{
		istraversed[source]=true;
		position[source]=rmqarray.size();
		rmqarray.push_back(make_pair(level[source],source));
		for(list<pair<int,long long> >::iterator i=graph[source].begin();i!=graph[source].end();i++)
		{
			if(!istraversed[i->first])
			{
				dfs(graph,level,position,rmqarray,i->first);	
				rmqarray.push_back(make_pair(level[source],source));	
			}
		}
	}
}
template<class T> class rmq
{
	private:
		vector<vector<T> > RMQ;
	public:
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

int main()
{
	
	while(1)
	{
		int n;
		scanf("%d",&n);
		//cin>>n;
		
		if(n==0)
			break;
		
		vector<list<pair<int,long long> > > graph(n);
		
		for(int i=1;i<n;i++)
		{
			int b,w;
			scanf("%d %d",&b,&w);
			//cin>>b>>w;
			graph[i].push_back(make_pair(b,w));
			graph[b].push_back(make_pair(i,w));
		}
	
		vector<int> level(n,-1);
		vector<long long > distances(n,0);	
		
		//--bfs-------
		queue<int> Q;
		level[0]=0;
		distances[0]=0;
		Q.push(0);
		
		
		while(!Q.empty())
		{
			int current=Q.front();
			Q.pop();
			for(list<pair<int,long long> >::iterator i=graph[current].begin();i!=graph[current].end();i++)
			{
				if(level[i->first]==-1)
				{
					level[i->first]=level[current]+1;
					distances[i->first]=distances[current]+i->second;
					Q.push(i->first);
				}
			}
		}
		
		//----------------------------------------------------------------------
		vector<int> position(n);
		vector<pair<int,long long> > rmqarray;
		istraversed.clear();
		istraversed.resize(n);
	
		dfs(graph,level,position,rmqarray);
		
				
		rmq<pair<int,long long> >  RMQ(rmqarray);
		
		
		int q;
		scanf("%d",&q);
		//cin>>q;
		while(q--)
		{
			int a,b;
			scanf("%d %d",&a,&b);
			//cin>>a>>b;
			pair<int,int> LCA=RMQ.query(min(position[a],position[b]),max(position[a],position[b]));
			printf("%lld ",distances[a]+distances[b]-2*distances[LCA.second]);
		}
		printf("\n");	
	}
}
