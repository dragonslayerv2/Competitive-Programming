#include<iostream>
#include<cstdio>
#include<vector>
#include<list>
using namespace std;

#define MAX 3000

#define GETCHAR getchar//_unlocked
#define PUTCHAR putchar//_unlocked

inline int readInt() 
{
	int flag=1;
    int n = 0;
    char c;
    while (1)
    { 
              c=GETCHAR();
              if(c>='0'&&c<='9') {n = n * 10 + c - '0';flag=0;}
              else if(flag!=1) break; 
                              
    }
    return n;
}
 
 

inline void writeInt(int x) 
{
     int i = 10;
     char buf[11];
     // buf[10] = 0;
     buf[10] = '\n';

     do 
     {
        buf[--i] = x % 10 + '0';
        x/= 10;
     }while(x);
     do 
     {
        PUTCHAR(buf[i]);
     } while (buf[i++] != '\n');
}

int graph[MAX][MAX];

int dfs(int graph[MAX][MAX],int n,bool isVisited[MAX],int v,int DFN,int dfn[MAX],int low[MAX])
{
	int child=0;
	bool cutvertex=false;
	isVisited[v]=true;
	low[v]=dfn[v]=DFN;
	int count=0;
	for(int i=1;i<=graph[v][0];i++)
	{
		if(!isVisited[graph[v][i]])
		{
			child++;
			count+=dfs(graph,n,isVisited,graph[v][i],++DFN,dfn,low);
			low[v]=min(low[v],low[graph[v][i]]);			
			
			if(low[graph[v][i]]>=dfn[v]) cutvertex=true;
		}
		else
			low[v]=min(low[v],dfn[graph[v][i]]);
	}
	
	if(!dfn[v])
	{
		if(child>1)
			return count+1;
		else
			return count;
	}
	else if(cutvertex)
	{
		return count+1;
	}
	else return count;
	
}



int main()
{
	
	int t;
	t=readInt();
//	cin>>t;
	while(t--)
	{
		bool isVisited[MAX]={false};
		int dfn[MAX]={0};
		int low[MAX]={0};
		int n,m,k;
		//cin>>n>>m>>k;
		n=readInt();
		m=readInt();
		k=readInt();
		//----------------------- 	
		for(int i=0;i<n;i++)
			graph[i][0]=0;
		//----------------------
		
		for(int i=0;i<m;i++)
		{
			int a,b;
			//cin>>a>>b;
			a=readInt();
			b=readInt();
			graph[a][0]++;
			graph[b][0]++;
			graph[a][graph[a][0]]=b;
			graph[b][graph[b][0]]=a;
			
		}
		writeInt(dfs(graph,n,isVisited,0,0,dfn,low)*k);
	}
	return 0;
}
