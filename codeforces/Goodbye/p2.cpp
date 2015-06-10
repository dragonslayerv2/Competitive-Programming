#include<iostream>
#include<queue>
#include<algorithm>
#include<vector>
using namespace std;


int main(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
		a[i]--;
	}	
	vector<string> matrix(n);
	for(int i=0;i<n;i++)
		cin>>matrix[i];
	
	vector<int> componentId(n,-1);
	vector<vector<int> > componentMembers;
	componentMembers.reserve(n);
	
	for(int i=0;i<n;i++){
		if(componentId[i]==-1){
			int componentNumber=componentMembers.size();
			componentMembers.push_back(vector<int>());
			queue<int> Q;
			Q.push(i);
			while(!Q.empty()){
				int top=Q.front();
				Q.pop();
				if(componentId[top]!=-1)
					continue;
				componentId[top]=componentNumber;
				componentMembers.back().push_back(a[top]);
				for(int j=0;j<n;j++){
					if(matrix[top][j]=='1'&&componentId[j]==-1){
						Q.push(j);
					}
				}
				
			}
		}
	}
	for(int i=0;i<componentMembers.size();i++){
		sort(componentMembers[i].begin(),componentMembers[i].end());
	}
	for(int i=n-1;i>=0;i--){
		int top=componentMembers[componentId[i]].back();
		componentMembers[componnentId[i]].pop_back();
		a[i]=top;
	}
	
	for(int i=0;i<n;i++)
		cout<<a[i]+1<<" ";
	
}
