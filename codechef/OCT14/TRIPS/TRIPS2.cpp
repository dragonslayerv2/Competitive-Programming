#include<iostream>
#include<limits>
#include<vector>
#include<ctime>
#include<list>
#include<cmath>
#include<queue>
#include<assert.h>
#include<algorithm>
using namespace std;

typedef vector<vector<pair<int,int> > > tree;

#define sqrtN 100
#define MAXN 200001
#define LOGN 18
int hopParent[sqrtN][MAXN][LOGN];
int bigParent[MAXN][LOGN];
int parent[MAXN], parentDistance[MAXN], level[MAXN], rootDistance[MAXN];

int pow2[MAXN];

void generatePow2(int n){
	int pow=0;
	while((1<<pow)<MAXN){
		pow2[1<<pow]=pow;
		pow++;
	}
	for(int i=1;i<MAXN;i++){
		if(!pow2[i])
			pow2[i]=pow2[i-1];
	}
}

pair<int,int> RMQ[MAXN][30];
template<class T> class rmq
{
	public:
		rmq(){}
		rmq(vector<T> &arr)
		{
			int n=arr.size();
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
			int p=pow2[gap];
			int po=(1<<p);
			return min(RMQ[i][p],RMQ[j-po+1][p]);
		}
};


class LCA
{
	private:
		tree &T;
		vector<bool> istraversed;
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
					if(!istraversed[i->first])          // vertex point here
					{
						dfs(i->first);	
						rmqArray.push_back(make_pair(level[source],source));	
					}
				}
			}
		}
		
	public:
		LCA(tree &t,int start=0):T(t)
		{
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

//---------------------------------------------------------
//--------------------------------------------------------
int main(){
	generatePow2(MAXN);
//	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	tree T(n);
	assert(n<100000);
	for(int i=0;i<n-1;i++){
		int a, b, d;
		cin>>a>>b>>d;
		a--;
		b--;
		T[a].push_back(make_pair(b,d));
		T[b].push_back(make_pair(a,d));
	}
	for(int i=0;i<n;i++)
		parent[i]=-1;
	parent[0]=0;
	
	queue<int> q;
	q.push(0);
	
	while(!q.empty()){
		int currentNode=q.front();
		q.pop();
		for(vector<pair<int,int> >::iterator i=T[currentNode].begin();i!=T[currentNode].end();i++){
			if(parent[i->first]==-1){
				q.push(i->first);
				level[i->first]=1+level[currentNode];
				rootDistance[i->first]=i->second+rootDistance[currentNode];
				parent[i->first]=currentNode;
				parentDistance[i->first]=i->second;
			}
		}
	}
	// for 0
	for(int node=0;node<n;node++)
		hopParent[0][node][0]=node;
	
	// for 1
	for(int node=0;node<n;node++)
		if(parentDistance[node]==1)
			hopParent[1][node][0]=parent[node];
		else
			hopParent[1][node][0]=node;
	
	
	// for 2 and more
	for(int hops=2;hops<sqrtN;hops++)
		for(int node=0;node<n;node++)
			hopParent[hops][node][0]=hopParent[hops-parentDistance[node]][parent[node]][0];
	
	for(int pow2=1;pow2<LOGN;pow2++)
		for(int hops=0;hops<sqrtN;hops++)
			for(int node=0;node<n;node++) {
				int parent = hopParent[hops][node][pow2-1];
				hopParent[hops][node][pow2]=hopParent[hops][parent][pow2-1];
			}

	for(int node=0;node<n;node++)
		bigParent[node][0]=parent[node];
		
	for(int pow2=1;pow2<LOGN;pow2++){
		for(int node=0;node<n;node++) {
			int parent = bigParent[node][pow2-1];
			bigParent[node][pow2]=bigParent[parent][pow2-1];
		}
	}
	
	LCA lca(T);
	
	int queries;
	cin>>queries;

	while(queries--){
		int a,b,hops;
		cin>>a>>b>>hops;
		a--;
		b--;
		int commonParent=lca.query(a,b);
		int ans=0;
		
		if(hops<sqrtN){
			int hopsA=0;
			int hopsB=0;
			int currentNodeA=a;
			int currentNodeB=b;
			
			int pow2=LOGN-1;
			while(pow2>=0){
				if(level[hopParent[hops][currentNodeA][pow2]]>level[commonParent]){
					hopsA+=(1<<pow2);
					currentNodeA=hopParent[hops][currentNodeA][pow2];
				}
				pow2--;
			}
			pow2=LOGN-1;
			while(pow2>=0){
				if(level[hopParent[hops][currentNodeB][pow2]]>level[commonParent]){
					hopsB+=(1<<pow2);
					currentNodeB=hopParent[hops][currentNodeB][pow2];
				}
				pow2--;
			}
			
			ans=hopsA+hopsB;
			int leftDistance=rootDistance[currentNodeB]+rootDistance[currentNodeA]-2*rootDistance[commonParent];
			
			if(leftDistance){
				if(leftDistance<=hops)
					ans++;
				else
					ans+=2;
			}
			cout<<ans<<endl;
		}
		else
		{
			int hopsA=0;
			int hopsB=0;
			int currentNodeA=a;
			int currentNodeB=b;
			
			int ans;
			while(rootDistance[currentNodeA]-rootDistance[commonParent]>hops){
				hopsA++;
				int pow2=LOGN-1;
				int hopsLeft=hops;
				while(pow2>=0&&hopsLeft){
					int parent=bigParent[currentNodeA][pow2];
					if(rootDistance[currentNodeA]-rootDistance[parent]<=hopsLeft){
						hopsLeft-=rootDistance[currentNodeA]-rootDistance[parent];
						currentNodeA=parent;
					}
					pow2--;
				}	
			}
			while(rootDistance[currentNodeB]-rootDistance[commonParent]>hops){
				hopsB++;
				int pow2=LOGN-1;
				int hopsLeft=hops;
				while(pow2>=0&&hopsLeft){
					int parent=bigParent[currentNodeB][pow2];
					if(rootDistance[currentNodeB]-rootDistance[parent]<=hopsLeft){
						hopsLeft-=rootDistance[currentNodeB]-rootDistance[parent];
						currentNodeB=parent;
					}
					pow2--;
				}	
			}
			
			ans=hopsA+hopsB;
			
			int leftDistance=rootDistance[currentNodeB]+rootDistance[currentNodeA]-2*rootDistance[commonParent];
			if(leftDistance){
				if(leftDistance<=hops)
					ans++;
				else
					ans+=2;
			}	
			cout<<ans<<endl;
		}
	}
}
