#include<iostream>
#include<vector>
using namespace std;

bool isCalculated[200][200][200];
int dp[200][200][200];
int Pi[200];
string a,b,c;

void computePiFunction()
{
		int m=c.size();

		Pi[0]=-1;
		int k=-1;
		
		for(int i=1;i<m;i++)
		{
		
			while(k>=0&&c[k+1]!=c[i])
				{k=Pi[k];}
			if(c[k+1]==c[i])
				k++;
			Pi[i]=k;	
		}
}


#define MIN -1000
int solve(int i,int j,int k){
	if(k==c.size())
		return MIN;
	if(i==a.size()||j==b.size())
		return 0;
	else if(!isCalculated[i][j][k]){
		int ans = MIN; 
		if(a[i]==b[j]){
				while(k>=0&&c[k+1]!=a[i])
					k=Pi[k];
				if(c[k+1]==a[i])	
					k++;
				if(k==c.size()-1)
					ans=MIN;
				else
					ans=max(ans,1+solve(i+1,j+1,k));
						
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
	computePiFunction();
	int ans = solve(0,0,-1);
	if(ans<=0)
		cout<<0;
	else
		cout<<ans;
}
