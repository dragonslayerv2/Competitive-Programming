#include<iostream>
#include<vector>
#include<limits>
#include<map>
using namespace std;

#define UNDEFINED -1
#define LEFT 0
#define DOWN 1
#define RIGHT 2
#define UP 3


void printgrid(vector<vector<char> > &grid)
{
	for(int i=0;i<grid.size();i++)
	{
		for(int j=0;j<grid[i].size();j++)
			cout<<grid[i][j];
		cout<<endl;
	}
	cout<<endl;
	cin.get();
}
long long dfs(vector<vector<char> > &grid,int i,int j,int lastmove,bool upleft=false)
{
	if(grid[i][j]=='#')
		return 0;
	else
	{
		grid[i][j]='#';
		
		bool allowed[4]={true,true,true,true};
		
		if(i==0)
			allowed[UP]=false;
		if(i==grid.size()-1)
			allowed[DOWN]=false;
		if(j==0)
			allowed[LEFT]=false;
		if(j==grid[i].size()-1)
			allowed[RIGHT]=false;
			
		if(upleft&&lastmove!=LEFT)
			allowed[LEFT]=false;
		
		if(upleft&&lastmove!=UP)
			allowed[UP]=false;
		#ifdef DEBUG
	//	printgrid(grid);
		#endif
		long long solution=0;
		
		if(allowed[UP])
			solution=max(solution,dfs(grid,i-1,j,UP,true));
		if(allowed[LEFT])
			solution=max(solution,dfs(grid,i,j-1,LEFT,true));
		if(allowed[DOWN])
			solution=max(solution,dfs(grid,i+1,j,DOWN,upleft));
		if(allowed[RIGHT])
			solution=max(solution,dfs(grid,i,j+1,RIGHT,upleft));
		grid[i][j]='.';
		return 1+solution;
	}
}


int main()
{
	freopen("output3.txt","w",stdout);
	int t;
	cin>>t;
	for(int T=1;T<=t;T++)
	{
		int n,m;
		cin>>n>>m;
		vector<vector<char> > grid(n,vector<char>(m));
		
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin>>grid[i][j];
		
		cout<<"Case #"<<T<<": "<<dfs(grid,0,0,UNDEFINED)<<endl;
	}
}
