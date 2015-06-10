#include<iostream>
using namespace std;

bool isCalculated[200][200][200];
int dp[200][200][200];

string a,b,c;

#define MIN -1000
int solve(int i,int j,int k){
	if(k==c.size())
		return MIN;
	if(i==a.size()||j==b.size())
		return 0;
	else if(!isCalculated[i][j][k]){
		int ans = MIN; 
		if(a[i]==b[j]){
			if(a[i]==c[k]){
				if(k+1!=c.size())
					ans = max(ans,1+solve(i+1,j+1,k+1));
			}
			else
				ans = max(ans,1+solve(i+1,j+1,0));
		}
		ans = max(ans,solve(i+1,j,k));
		ans = max(ans,solve(i,j+1,k));
		dp[i][j][k]=ans;
		isCalculated[i][j][k]=true;
			
	}
	return dp[i][j][k];
}


int main(){
	cin>>a>>b>>c;
	int ans = solve(0,0,0);
	if(ans<=0)
		cout<<0;
	else
		cout<<ans;
}
