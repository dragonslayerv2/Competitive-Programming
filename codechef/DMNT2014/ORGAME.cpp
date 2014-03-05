#include<stdio.h>
using namespace std;


int n;
void dfs(char graph[200][200],bool isVisited[200],int source)
{
	if(!isVisited[source])
	{
		isVisited[source]=true;
		for(int i=0;i<n;i++)
			if(graph[source][i])
				dfs(graph,isVisited,i);
	}
}
int main()
{
	scanf("%d",&n);
	
	int profit[n];
	for(int i=0;i<n;i++)
		scanf("%d",&profit[i]);
	
	char graph[200][200];
	for(int i=0;i<n;i++)
	{
	
			scanf("%s",graph[i]);
		}
	
	bool isVisited[200]={false};
	
	dfs(graph,isVisited,0);
	int ans=0;
	for(int i=0;i<n;i++)
		if(isVisited[i])
			ans|=profit[i];
	printf("%d",ans);
}
