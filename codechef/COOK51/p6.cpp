#include<iostream>
#include<cstdio>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;


bool isPossible[100000002];
int prefixSum[100000002];

int leftCompare(int l,int r, int targetPosition,int n){
	int count=r-l+1;
	while(count>0){
		int currentPosition=l;
		int step=count>>1;
		currentPosition+=step;
		if(prefixSum[currentPosition]-prefixSum[targetPosition]<n){
			l=++currentPosition;
			count-=step+1;
		}
		else
			count=step;
	}
	return l;
}

int main(){
	ios::sync_with_stdio(false);
	vector<int> fibo;
	map<int,int> rank;
	fibo.push_back(1);
	fibo.push_back(1);
	rank[1]=1;
	while(fibo.back()<=100000000){
		isPossible[fibo.back()]=true;
		fibo.push_back(fibo[fibo.size()-1]+fibo[fibo.size()-2]);
		rank[fibo.back()]=fibo.size();
	}
	
	for(int i=1;i<=100000000;i++)
		if(isPossible[i])
			for(int j=0;fibo[j]<=100000000/i&&j<fibo.size();j++)
				isPossible[i*fibo[j]]=true;
	
	prefixSum[1]=1;
	for(int i=2;i<=100000000;i++)
		prefixSum[i]=prefixSum[i-1]+isPossible[i];
	
	int t;
	cin>>t;
	while(t--){
		int l,r,n;
		cin>>l>>r>>n;
		int number=leftCompare(l,r+1,l,n-1);
		if(number>r)
			cout<<-1<<endl;
		else{
			cout<<number<<' ';
			for(int i=fibo.size()-1;i>=2;i--){
				while(number%fibo[i]==0){
					int currentRank=rank[fibo[i]];
					for(int j=0;j<currentRank;j++)
						cout<<'.';
					number/=fibo[i];
					if(number!=1)
						cout<<'#';
				}
			}
			cout<<endl;
		}		
	}
}
