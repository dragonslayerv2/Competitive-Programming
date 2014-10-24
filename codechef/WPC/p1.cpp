#include<iostream>
#include<climits>
#include<vector>
#include<queue>
using namespace std;

int v,e,k;
vector<vector<int> > distances;
typedef vector<vector<pair<int,int> > > graph;

struct cmp
{
	bool operator()(pair<int,int> a,pair<int,int> b)
	{
		return a>b;
	}
};
vector<int> dijkstras(const graph &G,int source)
{
	const int INVALID = INT_MAX;
	priority_queue<pair<int,int>,vector<pair<int,int> >, cmp > Q;
	
	vector<bool> used(G.size(),false);  
	vector<int> distances(G.size(),INVALID);  
	
	distances[source]=0;
	Q.push(make_pair(0,source));
	
	while(!Q.empty())
	{
		pair<int,int> current=Q.top();
		Q.pop();
		if(!used[current.second])
		{
			used[current.second]=true;
			for(vector<pair<int,int> >::const_iterator i=G[current.second].begin();i!=G[current.second].end();i++)
			{
				if(distances[i->first]>distances[current.second]+i->second)
				{
					distances[i->first]=distances[current.second]+i->second;
					Q.push(make_pair(distances[i->first],i->first));
				}
			}
		}
	}
	return distances;	
}
#include<cstdio>
#define A_TURN 0
#define B_TURN 1

bool isCalculated[2][600000];
int solution[2][600000];
#define INVALIDA INT_MIN
#define INVALIDB INT_MAX

inline bool allAssigned(int setA){
	int assigned=0;
	while(setA){
		assigned+=((setA%3)?1:0);
		setA/=3;
	}
	return assigned==k;
}

inline bool notAssigned(int set,int point){
	while(point--)
		set/=3;
	return !(set%3);
}

inline int assign(int set,int point,int group){
	int newNumber=0;
	int last3Power=1;
	while(point--){
		newNumber+=(set%3)*last3Power;
		set/=3;
		last3Power*=3;
	}
	newNumber+=group*last3Power;
	last3Power*=3;
	set/=3;
	while(set){
		newNumber+=(set%3)*last3Power;
		set/=3;
		last3Power*=3;
	}
	return newNumber;
}

int solve(int turn,int setA){
	if(allAssigned(setA)){
		int dist=0;
		for(int i=0,last3=1;i<k;i++,last3*=3){
			int currentGroup=(setA/last3)%3;
			if(currentGroup==1){
				for(int j=0,pow3=1;j<k;j++,pow3*=3)
					if((setA/pow3)%3==2)
						dist+=distances[i][j];	
			}		
		}
		return dist;
	}
	else{
		if(!isCalculated[turn][setA]){
			int ans;
			isCalculated[turn][setA]=true;
			if(turn==A_TURN){
				ans=INVALIDA;
				for(int i=0;i<k;i++)
					if(notAssigned(setA,i)){
						int current=solve(turn^1,assign(setA,i,1));
						if(current!=INVALIDA&&current!=INVALIDB)
							ans=max(ans,current);	
					}
			}
			else{
				ans=INVALIDB;
				for(int i=0;i<k;i++)
					if(notAssigned(setA,i)){
						int current=solve(turn^1,assign(setA,i,2));
						if(current!=INVALIDA&&current!=INVALIDB)
							ans=min(ans,current);	
					}			
			}
			solution[turn][setA]=ans;
		}	
		return solution[turn][setA];
	}
}
int main(){
	cin>>v>>e>>k;
	
	graph G(v);
	while(e--){
		int a,b,d;
		cin>>a>>b>>d;
		a--;
		b--;
		G[a].push_back(make_pair(b,d));
		G[b].push_back(make_pair(a,d));
	}
	
	vector<int> goodNodes(k);
	for(int i=0;i<k;i++){
			cin>>goodNodes[i];
			goodNodes[i]--;
	}
	
	distances.resize(goodNodes.size(),vector<int>(goodNodes.size()));
	for(int i=0;i<goodNodes.size();i++){
		vector<int> dist=dijkstras(G,goodNodes[i]);
		for(int j=0;j<goodNodes.size();j++)
			distances[i][j]=dist[goodNodes[j]];
	}
	
	cout<<solve(A_TURN,0);
}
