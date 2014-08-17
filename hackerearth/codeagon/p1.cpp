#include<iostream>
#include<vector>
#include<climits>
using namespace std;

vector<vector<bool> > isInitialised;
vector<vector<int> > dp; 
int solve(int first, int moversLeft, vector<int> &package){
	if(moversLeft == 0)
	{
		if(first!=package.size())
			return INT_MAX;
		else
			return 0;
	} 
	if(!isInitialised[first][moversLeft]){
		int currentWeight=0;
		int ans = INT_MAX;
		for(int i=first;i<=package.size();i++){
			ans = min(ans,max(currentWeight,solve(i,moversLeft-1,package)));
			if(i!=package.size())
				currentWeight+=package[i];
		}
		isInitialised[first][moversLeft]=true;
		dp[first][moversLeft]=ans; 
	}
	return dp[first][moversLeft];
}
int main(){
	int m,p;
	cin>>m>>p;
	vector<int> package(p);
	for(int i=0;i<p;i++)
		cin>>package[i];
	isInitialised.assign(p+1,vector<bool>(m+1));
	dp.assign(p+1,vector<int>(m+1));
	cout<<solve(0,m,package);		
}

