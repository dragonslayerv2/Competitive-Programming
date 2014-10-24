#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;

int main(){
	int n,k;
	cin>>n>>k;
	vector<int> dest(2001);
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		dest[x]++;
	}
	
	int lastAt=1;
	int lastCount=n;
	
	int time=0;
	
	for(int i=0;i<dest.size();i++){
		int current=0;
		if(dest[i]){
			while(dest[lastAt]<lastCount){
				time+=2*(i-lastAt);
				int moved=min(k,lastCount-dest[lastAt]);
				current+=moved;
				lastCount-=moved;
			}
			time-=(i-lastAt);
			lastAt=i;
			lastCount=current;
		}
	}
	cout<<time+lastAt-1;
}
