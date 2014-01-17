#include<iostream>
#include<vector>
using namespace std;

bool infinite=false;
vector<vector<int> > solution;
vector<vector<bool> > exist;
vector<vector<bool> > computed;

int dfs(vector<vector<char> > &grid,int i,int j)
{
	if(i<0||i>grid.size()||j<0||j>grid[i].size())
		return 0;
	if(exist[i][j]&&computed[i][j])
		return solution[i][j];
	if(exist[i][j]&&!computed[i][j])
	{
		infinite=true;
		exist[i][j]=true;
		computed[i][j]=true;
		return 0;
	}
	else if(exist[i][j]==false)
	{
		exist[i][j]==true;
		if(grid[i][j]=='#')
			solution[i][j]=0;
		else if(grid[i][j]=='^')
			solution[i][j]=1+dfs(grid,i-1,j);
		else if(grid[i][j]=='>')
			solution[i][j]=1+dfs(grid,i,j+1);
		else if(grid[i][j]=='<')
			solution[i][j]=1+dfs(grid,i,j-1);
		else if(grid[i][j]=='v')
			solution[i][j]=1+dfs(grid,i+1,j);
		computed[i][j]=true;
		return solution[i][j];
	}
}
int main()
{
	int n,m;
	cin>>n>>m;
	vector<vector<char> > grid(n,vector<char>(m));
	solution.resize(n,vector<int>(m));
	exist.resize(n,vector<bool>(m));
	computed.resize(n,vector<bool>(m));
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>grid[i][j];
	
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			dfs(grid,i,j);
	
	if(infinite)
		cout<<-1;
	else
	{
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
				cout<<solution[i][j]<<" ";
			cout<<endl;
		}
	}
}
