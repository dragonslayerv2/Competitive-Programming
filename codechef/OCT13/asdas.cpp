#include<iostream>
#include<limits>
#include<vector>
using namespace std;


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,m,c1,c2;
		cin>>n>>m>>c1>>c2;
		
		vector<vector<char> > GRID(n,vector<char>(m));
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin>>GRID[i][j];
		
		vector<int> blackcount(m);
		
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if (GRID[i][j]=='B') 
					blackcount[j]++;
			}
		}
		
		int minrow=numeric_limits<int>::max();
		for(int i=0;i<n;i++)
		{
			for(int j=0;j<m;j++)
			{
				if(GRID[i][j]=='B')
					minrow=min(minrow,i);
			}
		}
		
		
		for(int j=0;j<m;j++)
		{
			for(int i=0;i<n;i++)
			{
				if(blackcount[j]
			}
		}
	}
}	
