#include<iostream>
#include<vector>
#include<map>
#include<list>
using namespace std;

typedef vector<list<int> > tree;
vector<bool> isBlack;
vector<bool> isVisited;
tree T;
long long count = 1;
#define MOD 1000000007LL

bool dfs(int source,int currentNode,int distance){
	if(source!=currentNode&&isVisited[currentNode])
		return false;
	if(source!=currentNode && isBlack[currentNode]){
		count*=(distance);
		count%=MOD;
		isVisited[currentNode]=true;
		return true;
	}
	isVisited[currentNode]=true;
	bool hasCut = false;
	for(list<int>::iterator i = T[currentNode].begin();i!=T[currentNode].end();i++)
		hasCut=(hasCut||dfs(source,*i,distance+1));
	return hasCut;
}

int main(){
	int n;
	cin>>n;
	T.resize(n);
	isBlack.resize(n);
	for(int i=1;i<n;i++)
	{
		int dest;
		cin>>dest;
		T[dest].push_back(i);
		T[i].push_back(dest);
	}
	for(int i=0;i<n;i++){
		int color;
		cin>>color;
		if(color)
			isBlack[i]=true;
	}
	isVisited.resize(n,false);
	for(int i=0;i<n;i++)
		if(isBlack[i])
			dfs(i,i,0);
	
	cout<<count;
}
