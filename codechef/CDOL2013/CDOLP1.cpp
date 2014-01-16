#include<iostream>
using namespace std;

bool graph[1001][1001];
bool isVisited[1001];
int dfs(int S,int n)
{
	isVisited[S]=true;
	int count=0;
	for(int i=1;i<=n;i++)
	{
		if(graph[S][i]&&!isVisited[i])
		{
			count+=dfs(i,n);
		}
	}
	return 1+count;
}



int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,s,f;
		cin>>n>>s>>f;
		
		for(int i=1;i<=n;i++)
		{
			for(int j=1;j<=n;j++)
				graph[i][j]=false;
			isVisited[i]=false;
		}
		
		for(int i=0;i<f;i++)
		{
			int a,b;
			cin>>a>>b;
			graph[a][b]=true;
		}
		
		cout<<n-dfs(s,n)<<endl;
	}
	return 0;
}
