#include<iostream>
#include<vector>
using namespace std;

int solve(vector<int> &array)
{
	int cost=0;
	for(int i=array.size()-1;i>1;i--)
	{
		if(array[i-1]<=array[i])
			cost+=array[i]-array[i-1];
		else
		{
			cost=-1;
			break;
		}
	}
	return cost;
	
}
int main()
{
	int n,m,p;
	cin>>n>>m>>p;
	vector<vector<int> > grid(n+1,vector<int>(m+1));
	
	for(int i=1;i<=n;i++)
		for(int j=1;j<=m;j++)
				grid[i][j]=j;
	
	while(p--)
	{
		int i,j;
		cin>>i>>j;
		grid[i][j]++;
	}
	
	for(int i=1;i<=n;i++)
		cout<<solve(grid[i])<<endl;
	
}
