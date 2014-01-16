#include<iostream>
#include<vector>
using namespace std;

vector<vector<long long> > HASH;
vector<vector<bool> > exist;

long long dfs(vector<vector<int> > &grid,int i,int j)
{
	if(j<0||i>=grid.size()||j>=grid[i].size())
		return 0;
	if(!exist[i][j])
	{
		exist[i][j]=true;
		HASH[i][j]=grid[i][j]+max(dfs(grid,i+1,j),max(dfs(grid,i+1,j-1),dfs(grid,i+1,j+1)));
	}
	return HASH[i][j];
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int r,c;
		cin>>r>>c;
		vector<vector<int> > grid(r,vector<int>(c));
		
		exist.clear();
		HASH.clear();
		exist.resize(r,vector<bool>(c));
		HASH.resize(r,vector<long long>(c));
		for(int i=0;i<r;i++)
			for(int j=0;j<c;j++)
				cin>>grid[i][j];
		
		
		long long solution=0;
		for(int i=0;i<c;i++)
			solution=max(solution,dfs(grid,0,i));
		cout<<solution<<endl;
	}
}
