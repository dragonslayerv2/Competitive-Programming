#include<iostream>
#include<vector>
using namespace std;

vector<vector<int> > solution;
vector<vector<int> > grid;

int solve(int i,int j)
{
	if(i==grid.size())
		return 0;
	if(j<0||j>=grid[i].size())
		return -1;
	else if(solution[i][j]==-1)
	{
		int ans=grid[i][j];
		ans+=max(max(solve(i+1,j-1),solve(i+1,j)),solve(i+1,j+1));
		solution[i][j]=ans;
	}
	return solution[i][j];
	
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int h,w;
		cin>>h>>w;
		
		grid.clear();		
		grid.resize(h,vector<int>(w));
		solution.clear();
		solution.resize(h,vector<int>(w,-1));
	
		for(int i=0;i<h;i++)
			for(int j=0;j<w;j++)
				cin>>grid[i][j];
		
		int ans=0;
		for(int i=0;i<w;i++)
		{
			
			ans=max(ans,solve(0,i));
		}
			
		
		cout<<ans<<endl;
	}
}
