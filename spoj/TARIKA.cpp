#include<stdio.h>
#include<vector>
using namespace std;

int main()
{
	int n,m;
	scanf("%d %d",&n,&m);
	vector<vector<int> > grid(n,vector<int>(m));
	
	int x,y;
	scanf("%d %d",&x,&y);
	x--;
	y--;
	
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			scanf("%d",&grid[i][j]);
	
	int power=grid[x][y];
	
	grid[x][y]=0;
	for(int i=n-1;i>=x;i--)
		for(int j=m-1;j>=y;j--)
		{
			if(i==n-1&&j==m-1)
				continue;
			else if(i==n-1)
				grid[i][j]+=grid[i][j+1];
			else if(j==m-1)
				grid[i][j]+=grid[i+1][j];
			else
				grid[i][j]+=min(grid[i+1][j],grid[i][j+1]);	
		}
	if(power-grid[x][y]>=0)
		printf("Y %d",power-grid[x][y]);
	else
		printf("N");
	
}
