#include<stdio.h>

#define MAX 100001
#define MOD 1000000007

int graph[MAX];

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		
		int count[MAX]={0};
		
		int n,m;
		scanf("%d %d",&n,&m);
		
		for(int i=0;i<n;i++)
		{
			graph[i]=0;
		}
		int x=1;
		while(m--)
		{
			int a,b;
			scanf("%d %d",&a,&b);
			if(graph[a]==0&&graph[b]==0)
			{
				graph[a]=graph[b]=x;	
				x++;
			}
			else if(graph[a]==0)
				graph[a]=graph[b];
			else if(graph[b]==0)
				graph[b]=graph[a];
			else
			{
				int temp=graph[b];
				for(int i=1;i<=n;i++)
					if(graph[i]==temp)
						graph[i]=graph[a];
			}
		}
		int distinct=0;
		for(int i=1;i<=n;i++)
		{
			count[graph[i]]++;
			if(count[graph[i]]==1||graph[i]==0)
				distinct++;
		}
		int captians=1;
		for(int i=1;i<=x;i++)
		{
			if(count[i]>0)
				captians=(captians*count[i])%MOD;	
		}
		printf("%d %d\n",distinct,captians);
	}
	return 0;
}
