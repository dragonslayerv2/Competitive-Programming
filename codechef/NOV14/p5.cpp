#include<iostream>
#include<vector>
using namespace std;

#define RED 1
#define BLACK 0

int main(){
	ios::sync_with_stdio(false);
	int t;
	cin>>t;
	int rootColor=BLACK;
	while(t--){
		char Q,type;
		cin>>Q>>type;
		if(type=='i'){
			rootColor^=1;
		}
		else{
			vector<int> xParents,yParents;
			int x,y;
			cin>>x>>y;
				xParents.clear();
				yParents.clear();
				xParents.reserve(32);
				yParents.reserve(32);
				while(x){
					xParents.push_back(x);
					x/=2;
				}
				while(y){
					yParents.push_back(y);
					y/=2;
				}
				int xLevel=xParents.size();
				int yLevel=yParents.size();	
				int lcaLevel=0;
				while(!xParents.empty()&&!yParents.empty()&&xParents.back()==yParents.back()){
					lcaLevel++;
					xParents.pop_back();
					yParents.pop_back();
				}
				int pathLength=xLevel-lcaLevel+1+yLevel-lcaLevel;


				int lcaColor;
				if(lcaLevel&1)
					lcaColor=rootColor;
				else
					lcaColor=(rootColor^1);
				int sameColorNodes=(xLevel-lcaLevel)/2+(yLevel-lcaLevel)/2+1;
				int askedColor=((type=='r')?RED:BLACK);
				if(askedColor==lcaColor)
					cout<<sameColorNodes;
				else
					cout<<pathLength-sameColorNodes;
				cout<<endl;
		}
	}
}
