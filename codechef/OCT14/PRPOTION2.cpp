#include<iostream>
#include<map>
using namespace std;
#include<cstdio>

inline pair<int,pair<int,pair<int,int> > > hash(int R,int G,int B, int m){
	int maximum=max(R,max(G,B));
	int minimum=min(R,min(G,B));
	int mid;
	if(maximum==R&&minimum==G) mid=B;
	if(maximum==R&&minimum==B) mid=G;
	if(maximum==G&&minimum==R) mid=B;
	if(maximum==G&&minimum==B) mid=R;
	if(maximum==B&&minimum==R) mid=G;
	if(maximum==B&&minimum==G) mid=R;
	
	return make_pair(maximum,make_pair(mid,make_pair(minimum,m)));
} 

map<pair<int,pair<int,pair<int,int> > >,int> solution;
int  getSolution(int R,int G,int B,int m){
	
	if(m==0)
		return max(R,max(G,B));
	else{
		 pair<int,pair<int,pair<int,int> > > hashValue=::hash(R,G,B,m);
		map<pair<int,pair<int,pair<int,int> > >,int>::iterator it=solution.find(hashValue);
		if(it==solution.end()){
			int ans=max(R,max(G,B));
			ans=min(ans,min(
						getSolution(R/2,G+1,B+1,m-1),
						min(
							getSolution(R+1,G/2,B+1,m-1),
							getSolution(R+1,G+1,B/2,m-1))));
			solution[hashValue]=ans;
			return ans;
		}
		return it->second;
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
		cout<<getSolution(R,G,B,m)<<endl;
	}
}
