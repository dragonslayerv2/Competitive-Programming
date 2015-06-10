#include<iostream>
#include<vector>
#include<list>
#include<cstdio>
#include<queue>
#include<queue>
#include<stack>
using namespace std;

struct edge{
	int a,b,w;
};
int main(){
//		freopen("test4.txt","r",stdin);
	int n;
	cin>>n;

	vector<edge> edges(n-1);
	vector<list<int> > tree(n);
	
	for(int i=0;i<n-1;i++)
	{
		cin>>edges[i].a>>edges[i].b>>edges[i].w;
		edges[i].a--;
		edges[i].b--;
		tree[edges[i].a].push_back(edges[i].b);
		tree[edges[i].b].push_back(edges[i].a);
	}
	
	
	vector<int> level(n,-1);
	queue<int> Q;
	level[0]=0;
	Q.push(0);
	
	stack<int> S;
	
	while(!Q.empty())
	{
		int current=Q.front();
		S.push(current);
		Q.pop();
		for(list<int>::iterator i=tree[current].begin();i!=tree[current].end();i++)	
		{
				if(level[*i]==-1)
				{
					level[*i]=level[current]+1;
					Q.push(*i);
				}
		}
	}

	vector<int> childs(n,1);	
	while(!S.empty()){
		int current=S.top();
		S.pop();
		for(list<int>::iterator i=tree[current].begin();i!=tree[current].end();i++){
			if(level[*i]>level[current]){
				childs[current]+=childs[*i];
			}
		}
	}
	
	double initialValue=0;
	long long denominator = n;
	denominator*=n-1;
	denominator*=n-2;
	denominator/=6;
	
	for(int i=0;i<edges.size();i++){
		long long childCount;
		if(level[edges[i].a]>level[edges[i].b])
			childCount=childs[edges[i].a];
		else
			childCount=childs[edges[i].b];
		
		long long alpha=childCount;
		long long beta=n-childCount;
		
		long long multiplier = ((alpha*(alpha-1))/2)*beta;
		multiplier+=((beta*(beta-1))/2)*alpha;
		
		initialValue+=((double)(2*edges[i].w*multiplier))/denominator;
	}

	int q;
	cin>>q;
	while(q--){
		int i,w;
		cin>>i>>w;
		i--;
		int delta=edges[i].w-w;
		edges[i].w=w;
		
		long long childCount;
		if(level[edges[i].a]>level[edges[i].b])
			childCount=childs[edges[i].a];
		else
			childCount=childs[edges[i].b];
		
		long long alpha=childCount;
		long long beta=n-childCount;
		
		long long multiplier = ((alpha*(alpha-1))/2)*beta;
		multiplier+=((beta*(beta-1))/2)*alpha;
		
		initialValue-=((double)(2*delta*multiplier))/denominator;
		cout.setf(ios::fixed);
		cout.precision(6);
		cout<<initialValue<<endl;
	}
}
