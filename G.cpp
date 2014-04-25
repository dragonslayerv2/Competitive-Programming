#include<iostream>
#include<vector>
using namespace std;

int main()
{
	freopen("testG.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	int n,m;
	while(cin>>n)
	{
		cin>>m;
		vector<vector<int> > grid(n,vector<int>(m));
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin>>grid[i][j];
		
		for(int j=m-2;j>=0;j--)
			for(int i=0;i<n;i++)
				grid[i][j]+=min(grid[(n+i-1)%n][j+1],min(grid[i][j+1],grid[(i+1)%n][j+1]));	

		int MIN=INT_MAX;
		for(int i=0;i<n;i++)
			MIN=min(MIN,grid[i][0]);
		cout<<MIN<<endl;
	}
}
