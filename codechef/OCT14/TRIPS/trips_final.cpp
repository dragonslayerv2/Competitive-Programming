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

typedef vector<list<pair<int,int> > > tree;

#define sqrtN 300
#define MAXN 100005
#define LOGN 18
int bigParent[MAXN][LOGN];
int parent[MAXN], parentDistance[MAXN], level[MAXN], rootDistance[MAXN];
bool istraversed[MAXN];
int position[MAXN];
int pow2[MAXN];
int hopParent[MAXN][LOGN];

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

class LCA
{
	int adv(int x,int v){
	    for(int i=0;(1<<i)<=v;i++){
	        if((v>>i)&1)x=bigParent[x][i];
	    }
	    return x;
	}
	public:
		int query(int x,int y)
		{
			if(level[x]>level[y]) x=adv(x,level[x]-level[y]);
    		else y=adv(y,level[y]-level[x]);
    		if(x==y) return x;
    		for(int i=17;i>=0;i--){
    			if(bigParent[x][i]!=bigParent[y][i])
				{	
					x=bigParent[x][i];
					y=bigParent[y][i];
				}
    		}
        		
    		return bigParent[x][0];
		}	
};

//---------------------------------------------------------
struct query{
	int a,b,hops,no,ans;
	bool operator <(const query q2) const{
		return hops<q2.hops;
	}
};

#include<windows.h>
#include<cstdio>
//--------------------------------------------------------
int main(){
	generatePow2(MAXN);
	freopen("in.txt","r",stdin);
//	freopen("out.txt","w",stdout);
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	tree T(n);
	
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
		for(list<pair<int,int> >::iterator i=T[currentNode].begin();i!=T[currentNode].end();i++){
			if(parent[i->first]==-1){
				q.push(i->first);
				level[i->first]=1+level[currentNode];
				rootDistance[i->first]=i->second+rootDistance[currentNode];
				parent[i->first]=currentNode;
				parentDistance[i->first]=i->second;
			}
		}
	}
	for(int node=0;node<n;node++)
		bigParent[node][0]=parent[node];
	for(int pow2=1;pow2<LOGN;pow2++){
		for(int node=0;node<n;node++) {
			int parent = bigParent[node][pow2-1];
			bigParent[node][pow2]=bigParent[parent][pow2-1];
		}
	}
	
	LCA lca;
	int queries;
	cin>>queries;
	
	vector<query> Q(queries);
	for(int i=0;i<Q.size();i++){
		cin>>Q[i].a>>Q[i].b>>Q[i].hops;
		Q[i].no=i;
	}
	sort(Q.begin(),Q.end());
	
	vector<int> queryAnswer(Q.size());
	
	
	int *lastHopParent=new int[MAXN];
	int *currentHopParent=new int[MAXN];
	int *tempHopParent=new int[MAXN];
	
	
	for(int node=0;node<n;node++)
		lastHopParent[node]=node;
	
	// for 1
	for(int node=0;node<n;node++)
		if(parentDistance[node]==1)
			currentHopParent[node]=parent[node];
		else
			currentHopParent[node]=node;
	
	int lastHop=1;
	
	for(int q=0;q<Q.size();q++){
		
		int a=Q[q].a,b=Q[q].b,hops=Q[q].hops;
		a--;
		b--;
		int commonParent=lca.query(a,b);
		int ans=0;
		if(hops<sqrtN){
			bool changed=false;
			while(lastHop<hops){
				changed=true;
				for(int node=0;node<n;node++)
				{
					if(parentDistance[node]==2)
						tempHopParent[node]=lastHopParent[parent[node]];
					else
						tempHopParent[node]=currentHopParent[parent[node]];
				}
				swap(lastHopParent,currentHopParent);
				swap(tempHopParent,currentHopParent);
				lastHop++;
			}
			
			
			if(changed){
				for(int node=0;node<n;node++)
					hopParent[node][0]=currentHopParent[node];
				for(int pow2=1;pow2<LOGN;pow2++)
					for(int node=0;node<n;node++) {
						int parent = hopParent[node][pow2-1];
						hopParent[node][pow2]=hopParent[parent][pow2-1];
					}
			}
			int hopsA=0;
			int hopsB=0;
			int currentNodeA=a;
			int currentNodeB=b;
			int pow2=LOGN-1;
			while(pow2>=0){
				if(level[hopParent[currentNodeA][pow2]]>level[commonParent]){
					hopsA+=(1<<pow2);
					currentNodeA=hopParent[currentNodeA][pow2];
				}
				pow2--;
			}
			pow2=LOGN-1;
			while(pow2>=0){
				if(level[hopParent[currentNodeB][pow2]]>level[commonParent]){
					hopsB+=(1<<pow2);
					currentNodeB=hopParent[currentNodeB][pow2];
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
		}
		else
		{
			int hopsA=0;
			int hopsB=0;
			int currentNodeA=a;
			int currentNodeB=b;
			
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
		}
		queryAnswer[Q[q].no]=ans;
	}
	for(int i=0;i<queryAnswer.size();i++)
		cout<<queryAnswer[i]<<endl;
}
