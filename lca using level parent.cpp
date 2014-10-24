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

class LCA
{
	int adv(int x,int v){
	    for(int i=0;(1<<i)<=v;i++){
	        if((v>>i)&1)x=bigParent[x][i];
	    }
	    return x;
	}
	public:
		int query(int x,int y)
		{
			if(level[x]>level[y]) x=adv(x,level[x]-level[y]);
    		else y=adv(y,level[y]-level[x]);
    		if(x==y) return x;
    		for(int i=17;i>=0;i--){
    			if(bigParent[x][i]!=bigParent[y][i])
				{	
					x=bigParent[x][i];
					y=bigParent[y][i];
				}
    		}
        		
    		return bigParent[x][0];
		}	
};


int main(){
	
}
