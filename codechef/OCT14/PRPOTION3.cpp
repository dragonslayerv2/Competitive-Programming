#include<iostream>
#include<map>
using namespace std;

#define mp(R,G,B) make_pair(R,make_pair(G,B))
#define pairMax(a) max(a.first,max(a.second.first,a.second.second))
pair<int,pair<int,int> > solve(int R,int G,int B,int m){
	if(m==0){
		return mp(R,G,B);
	}	
	else
	{
		pair<int,pair<int,int> > ans1=mp(R,G,B);
		pair<int,pair<int,int> > ans2=solve(R/2,G+1,B+1,m-1);
		pair<int,pair<int,int> > ans3=solve(R+1,G/2,B+1,m-1);
		pair<int,pair<int,int> > ans4=solve(R+1,G+1,B/2,m-1);
		
		int min1=pairMax(ans1);
		int min2=pairMax(ans2);
		int min3=pairMax(ans3);
		int min4=pairMax(ans4);
		int minimum=min(min1,min(min2,min(min3,min4)));
		if(minimum==min1)
			return ans1;
		if(minimum==min2)
			return ans2;
		if(minimum==min3)
			return ans3;
		else
			return ans4;
	}
}
int main(){
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
		
		while(m>=3){
			m-=3;
			pair<int,pair<int,int> > newValues=solve(R,G,B,3);	
			R=newValues.first;
			G=newValues.second.first;
			B=newValues.second.second;
		}
		
		
		pair<int,pair<int,int> > newValues=solve(R,G,B,m);	
		R=newValues.first;
		G=newValues.second.first;
		B=newValues.second.second;
		int ans=max(R,max(G,B));
		cout<<ans<<endl;
	}
}
