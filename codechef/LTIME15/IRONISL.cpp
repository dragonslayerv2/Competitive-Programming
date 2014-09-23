#include<iostream>
#include<vector>
#include<queue>
#include<map>
using namespace std;

inline void set(vector<int> &a,int n){
	a[n>>5] |= (1<<(n&31));
}

inline void unset(vector<int> &a,int n){
	a[n>>5] &= ~(1<<(n&31));
}

inline int reducedSize(int n){
	return n/32+((n%32)!=0);
}

inline bool isSet(vector<int> &a,int n){
	return (a[n>>5]&(1<<(n&31)));
}

int main(){
	
	map<int,int> log2;
	for(int i=0;i<=31;i++)
		log2[1<<i]=i;
	

	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		vector<vector<int> > graph(n,vector<int>(reducedSize(n)));
		for(int i=0;i<n;i++)
			for(int j=0;j<n;j++){
				char c;
				cin>>c;
				if(c=='1')
					set(graph[i],j);
			}
				
		
		int q;
		cin>>q;
		while(q--){
			int v,m;
			cin>>v>>m;
			v--;
			vector<int> level(n,-1);
			while(m--){
				int a,b;
				cin>>a>>b;
				a--;
				b--;
				isSet(graph[a],b)?unset(graph[a],b):set(graph[a],b);
			}
			level[v]=0;
			queue<int> q;
			vector<int> visited(reducedSize(n));
			
			set(visited,v);
			q.push(v);
			level[v]=0;
			
			int count = 0;
			vector<int> notVisited(reducedSize(n));
			while(!q.empty()){
				int current = q.front();
				q.pop();
				
				for(int i=0;i<notVisited.size();i++)
					notVisited[i]=graph[current][i]&(~visited[i]);
				
				int offset=0;
				for(int i=0;i<notVisited.size();i++){
					while(notVisited[i]){
						int nextNode = offset+log2[notVisited[i]&(-notVisited[i])];
						notVisited[i]-=(notVisited[i]&(-notVisited[i]));
						
						level[nextNode]=level[current]+1;
						set(visited,nextNode);
						count+=level[nextNode];
						q.push(nextNode);
						
					}
					offset+=32;
				}
			}
			cout<<count<<endl;
		}
	}
}
