#include<iostream>
using namespace std;

#define LOGN 20
class levelParent{
	public:
		vector<vector<int> > levelParent;
		
		levelParent(vector<int> &parent){
			levelParent.resize(logn,vector<int>(parent.size()));
			levelparent[0]=parent;
			for(int pow2=1;pow2<LOGN;pow2++)
				for(int node=0;node<n;node++) {
					int parent = levelParent[node][pow2-1];
					levelParent[node][pow2]=levelParent[parent][pow2-1];
				}
		}
		
		int query(int x,int parentLevel){
			for(int pow2=LOGN-1;pow2>=0;pow2--){
				if((1<<pow2)<=parentLevel){
					parentLevel-=(1<<pow2);
					x=levelParent[pow2];
				}
			}
			return x;
		}
};


int main(){
	
}
