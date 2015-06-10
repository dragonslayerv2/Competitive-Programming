#include<iostream>
#include<vector>
#include<map>
#include<climits>
using namespace std;

int dp[3000][30];
bool isCalculated[3000][30]={false};

int roundOff(int number){
	int rem=number%10;
	if(rem<5)
		number-=rem;
	else
		number+=10-rem;
	return number;
}

int solve(int pos,int d, vector<int> &cost){
	if(!isCalculated[pos][d]){
		int currentCost=0;
		int ans=INT_MAX;
		for(int i=pos;i<cost.size();i++){
			currentCost+=cost[i];
			if(d>0&&i+1<cost.size())
				ans=min(ans,roundOff(currentCost)+solve(i+1,d-1,cost));
		}
		isCalculated[pos][d]=true;
		dp[pos][d]=min(ans,roundOff(currentCost));
	}
	return dp[pos][d];
}
int main(){
	int n,d;
	cin>>n>>d;
	vector<int> cost;
	for(int i=0;i<n;i++)
	{
		int x;
		cin>>x;
		cost.push_back(x);
	}
	cout<<solve(0,d,cost);
}

