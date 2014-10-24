#include<iostream>
#include<vector>
using namespace std;
#include<cstdio>
int main(){
//	freopen("test.txt","r",stdin);
	int t;
	cin>>t;
	while(t--){
		int r,b,g,m;
		cin>>r>>g>>b>>m;
		int R=0,G=0,B=0;
		for(int i=0;i<r;i++){
			int x;
			cin>>x;
			R=max(x,R);
		}
		for(int i=0;i<g;i++){
			int x;
			cin>>x;
			G=max(x,G);
		}
		for(int i=0;i<b;i++){
			int x;
			cin>>x;
			B=max(x,B);
		}	
		
		int ans=max(R,max(G,B));
		while(m--){
			int maximum=max(R,max(G,B));
			if(maximum==R)
				R=R/2;
			else if(maximum==G)
				G=G/2;
			else
				B=B/2;
			ans=min(ans,max(R,max(G,B)));
		}
		cout<<ans<<endl;
		
	}
}
