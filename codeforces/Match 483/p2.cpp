#include<iostream>
#include<cstdio>
#include<vector>
using namespace std;

struct query{
	int l,r,num;
};

int main(){
//	freopen("test.txt","r",stdin);
	int n,q;
	cin>>n>>q;
	vector<vector<int> > bits(n+1,vector<int>(32));
	vector<vector<int> > prefixSum(n+1,vector<int>(32));
	
	vector<query> Q(q);
	
	for(int i=0;i<q;i++){
		cin>>Q[i].l>>Q[i].r>>Q[i].num;	
		Q[i].l--;
		Q[i].r--;	
	}
	
	for(int i=0;i<q;i++){
		int tempNum=Q[i].num;
		int position=0;
		while(tempNum){
			if(tempNum&1){
				bits[Q[i].l][position]++;
				bits[Q[i].r+1][position]--;
			}
			position++;
			tempNum>>=1;	
		}
	}	
	
	for(int j=0;j<32;j++){
		int current=0;
		for(int i=0;i<n;i++){
			current+=bits[i][j];
			bits[i][j]=(current>0);
			if(i!=0)
				prefixSum[i][j]=prefixSum[i-1][j];
			prefixSum[i][j]+=bits[i][j];
		}
	}
	bool validated=true;
	
	
	for(int i=0;i<q;i++){
		int tempNum=Q[i].num;
		int position=0;
		while(tempNum){
			if(!(tempNum&1)){
				
				int leftSum=0;
				if(Q[i].l-1>=0)
					leftSum=prefixSum[Q[i].l-1][position];
				
				int rightSum=prefixSum[Q[i].r][position];
				if(rightSum-leftSum==Q[i].r-Q[i].l+1){
					validated=false;
					break;	
				}
			}
			position++;
			tempNum>>=1;	
		}	
	}
	
	if(validated){
		cout<<"YES"<<endl;
		for(int i=0;i<n;i++){
			int number=0;
			for(int j=0;j<bits[i].size();j++)
				number+=bits[i][j]*(1<<j);
			cout<<number<<" ";
		}
	}
	else
		cout<<"NO";
}
