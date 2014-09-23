#include<iostream>
#include<queue>
#include<vector>
#include<list>
using namespace std;

typedef vector<list<int> > tree;
int main(){
//	freopen("testTREE_GAME.txt","r",stdin);
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		tree T(n+1);
		for(int i=0;i<n-1;i++)
		{
			int a,b;
			cin>>a>>b;
			T[a].push_back(b);
			T[b].push_back(a);
		}
		
		vector<int> level(n+1,-1);
		
		queue<int> Q;
		Q.push(1);
		level[1]=0;
		while(!Q.empty())
		{
			int currentNode=Q.front();
			Q.pop();
			for(list<int>::iterator i = T[currentNode].begin();i!=T[currentNode].end();i++)
			{
				if(level[*i]==-1){
					level[*i]=level[currentNode]+1;
					Q.push(*i);
				}
			}	
		}
		vector<int> nodesAtLevel;
		for(int i=1;i<=n;i++){
			if(nodesAtLevel.size()<=level[i])
				nodesAtLevel.resize(level[i]+1);
			nodesAtLevel[level[i]]++;
		}
			
		const int ALICE_TURN = 0;
		const int BOB_TURN = 1;
		int turn = ALICE_TURN;
		int turnCount = 0;
		
		int leavesAt = nodesAtLevel.size()-1;
		int rootAt = 0;
		while(leavesAt>=rootAt){
			
			if(turn==ALICE_TURN)
				rootAt++;
			else if(turn==BOB_TURN)
			{
				nodesAtLevel[leavesAt]--;
				if(nodesAtLevel[leavesAt]==0)
					leavesAt--;
			}
			turn^=1;
			turnCount++;
		}
		cout<<turnCount<<endl;
	}
}
