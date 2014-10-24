#include<iostream>
#include<vector>
#include<algorithm>
#include<list>
#include<queue>
using namespace std;

int n;
vector<vector<long long> > distMatrix;
vector<vector<pair<long long,int> > > distances;
#define ROOT -1
#define INVALID -2
vector<int> parent;

typedef vector<list<pair<int,long long> > > tree;


void generateTree(int node){
	if(parent[node]==ROOT){
		for(int i=0;i<distances[node].size();i++)
			if(parent[distances[node][i].second]==INVALID)
			{
				parent[distances[node][i].second]=node;
				generateTree(distances[node][i].second);
			}			
	}	
	else{
		for(int i=0;i<distances[node].size();i++){
			int target=distances[node][i].second;
			if(target!=parent[node]){
				if(parent[target]==INVALID){
					int myParent=parent[node];
					if(distMatrix[myParent][target]+distMatrix[node][myParent]!=distMatrix[node][target])
					{
						parent[target]=node;
						generateTree(target);
					}
				}
			}
		}	
	}
}
int main(){
	ios::sync_with_stdio(false);
	//freopen("test.txt","r",stdin);
	cin>>n;
	distMatrix.resize(n,vector<long long>(n));
	distances.resize(n);
	parent.resize(n,INVALID);
	
	bool isPossible=true;
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			cin>>distMatrix[i][j];
			if(i!=j)
				distances[i].push_back(make_pair(distMatrix[i][j],j));
		}
	
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++){
			if(distMatrix[i][j]!=distMatrix[j][i])
				isPossible=false;
			
			if(i==j){
			
				if(distMatrix[i][j]!=0)
				isPossible=false;}
			else if(distMatrix[i][j]==0)
				isPossible=false;
		}
			
	
	if(!isPossible){
		cout<<"NO";
		return 0;
	}
	
	for(int i=0;i<distances.size();i++)
		sort(distances[i].begin(),distances[i].end());	

	parent[0]=ROOT;
	generateTree(0);
	for(int i=0;i<n;i++)
		if(parent[i]==INVALID)
			isPossible=false;
		
	if(!isPossible){
		cout<<"NO";
		return 0;
	}
	
	tree T(n);
	for(int i=0;i<n;i++){
		if(parent[i]!=ROOT){
			T[i].push_back(make_pair(parent[i],distMatrix[i][parent[i]]));
			T[parent[i]].push_back(make_pair(i,distMatrix[i][parent[i]]));
		}
	}
	
	vector<long long> newDist;
	for(int start=0;start<n;start++){
		queue<int> Q;
		newDist.clear();
		newDist.resize(n,-1);	
		Q.push(start);
		newDist[start]=0;
		while(!Q.empty())
		{
			int current=Q.front();
			Q.pop();
			for(tree::value_type::iterator i=T[current].begin();i!=T[current].end();i++)
			{
				if(newDist[i->first]==-1)
				{
					newDist[i->first]=newDist[current]+i->second;
					Q.push(i->first);
				}
			}
		}
		for(int i=0;i<n;i++)
			if(distMatrix[start][i]!=newDist[i])
			{
				isPossible=false;
				break;
			}
	}
	if(!isPossible){
		cout<<"NO";
		return 0;
	}
	else
		cout<<"YES";
}
