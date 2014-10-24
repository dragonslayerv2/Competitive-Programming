#include<iostream>
#include<stack>
#include<queue>
#include<vector>
#include<climits>
#include<list>
using namespace std;

typedef vector<list<int> > tree;

vector<bool> isVisited, isPresent;
pair<int,int> diameter(tree &T,int node){
		isVisited[node]=true;
		int maxDia=0;
		int max1=0,max2=0;
		bool isLeaf=true;
		for(list<int>::iterator i=T[node].begin();i!=T[node].end();i++){
			if(!isVisited[*i]&&isPresent[*i]){
				isLeaf=false;
				pair<int,int> ans=diameter(T,*i);
				maxDia=max(maxDia,ans.first);
				if(ans.second+1>=max1){
					max2=max1;
					max1=ans.second+1;
				}
				else if(ans.second+1>=max2){
					max2=ans.second+1;
				}	
			}
		}
		if(isLeaf){
			return make_pair(0,0);
		}
		else{
			return make_pair(max(maxDia,max1+max2),max1);
		}
}
int main(){
	int n,k;
	cin>>n>>k;
	tree T(n);
	int minDia=INT_MAX;
	for(int i=0;i<n-1;i++){
		int a,b;
		cin>>a>>b;
		a--;
		b--;
		T[a].push_back(b);
		T[b].push_back(a);
	}
	
	for(int root=0;root<n;root++){
		
		
		queue<int> Q;
		vector<int> level(n,-1);
		Q.push(root);
		level[root]=0;
		stack<int> S;
		while(!Q.empty()){
			int currentNode=Q.front();
			Q.pop();
			S.push(currentNode);
			for(list<int>::iterator i=T[currentNode].begin();i!=T[currentNode].end();i++){
				if(level[*i]==-1)
				{
					level[*i]=level[currentNode]+1;
					Q.push(*i);
				}
			}
		}
		isPresent.assign(n,true);
		isVisited.assign(n,false);
		int kCopy=k;
		while(S.size()>=0&&kCopy--){
			isPresent[S.top()]=false;
			S.pop();
		}
		minDia=min(minDia,diameter(T,root).first);
	}
	cout<<minDia;
}
