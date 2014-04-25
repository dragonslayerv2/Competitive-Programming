#include<iostream>
#include<vector>
#include<queue>
#include<limits>
#include<list>
using namespace std;


struct road
{
	int d;
	int l,t;
	
	road(int D=-1,int L=0,int T=0):d(D),l(L),t(T){}
};

struct state
{
	int node;
	int toll;
	int length;
	
	state(int N=-1,int T=-1,int L=-1):node(N),toll(T),length(L){}
	
	bool operator <(const state &s2) const
	{
		return length>s2.length;
	}
};

typedef vector<list<road> > graph;
int main()
{
	freopen("testL.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	int x;
	cin>>x;
	while(x--)
	{
		int toll,n,r;
		cin>>toll>>n>>r;
		
		graph G(n);
		while(r--)
		{
			int s,d,l,t;
			cin>>s>>d>>l>>t;
			s--;
			d--;
			G[s].push_back(road(d,l,t));
		}
		
		const int INVALID=numeric_limits<int>::max();
		priority_queue<state> Q;
		vector<vector<bool> > used(n,vector<bool>(toll+1));
		vector<vector<int> 	> distances(n,vector<int>(toll+1,INVALID));
		
		distances[0][toll]=0;
		Q.push(state(0,toll,0));
		
		while(!Q.empty())
		{
			state current=Q.top();
			Q.pop();
			//cerr<<"Current State = "<<current.node<<" "<<current.toll<<" "<<current.length<<endl;
			if(!used[current.node][current.toll]&&current.length!=INVALID)
			{
				used[current.node][current.toll]=true;
				
				for(list<road>::iterator i=G[current.node].begin();i!=G[current.node].end();i++)
				{					
						if(current.toll-i->t>=0&&!used[i->d][current.toll-i->t]&&distances[i->d][current.toll-i->t]>distances[current.node][current.toll]+i->l)
						{
						//	cerr<<"Relaxing "<<i->d<<" "<<current.toll-i->t;
						//	cerr<<"from "<<distances[i->d][current.toll-i->t]<<"to "<<distances[current.node][current.toll]+i->l<<endl;
							distances[i->d][current.toll-i->t]=distances[current.node][current.toll]+i->l;
							Q.push(state(i->d,current.toll-i->t,distances[i->d][current.toll-i->t]));	
						}
				}
			}
		}	
		
		int ans=INVALID;
		for(int i=0;i<=toll;i++)
		{
			//cerr<<distances[n-1][i]<<"\t";
			ans=min(ans,distances[n-1][i]);
		}
		//cerr<<endl;
		
		if(ans==INVALID)
			cout<<-1<<endl;
		else
			cout<<ans<<endl;
	}
}
