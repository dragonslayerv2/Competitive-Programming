#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main(){
	int n,m,k;
	cin>>n>>m>>k;
	vector<int> values(n);
	for(int i=0;i<n;i++)
		cin>>values[i];
	
	sort(values.rbegin(),values.rend());
	
	int count=0;
	while(k<m&&count<n){
		k+=values[count++]-1;
	}
	if(k<m)
		cout<<-1;
	else
		cout<<count;
}
