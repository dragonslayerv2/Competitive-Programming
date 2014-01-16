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
bool isVisited[MAX];

int dfs(int graph[MAX][MAX],int n,bool isVisited[MAX],int v)
{
//	cout<<"at "<<v;
	isVisited[v]=true;
	int count=1;
	
	for(int i=1;i<=graph[v][0];i++)
	{
		if(!isVisited[graph[v][i]])
			{
				count+=dfs(graph,n,isVisited,graph[v][i]);
			}
	}
	return count;

}


int cutvertex(int graph[MAX][MAX],int n)
{
	int cutcount=0;
	
	for(int i=0;i<n;i++)
	{
//		cout<<"removing"<<i<<endl;
		if(graph[i][0]>1)
		{
		//----------------------------
		
			for(int j=0;j<n;j++)
				isVisited[j]=false;
			
			isVisited[i]=true;
		//--------------------------------
		
			int v=0;
			if(i==0) v=1;
//			cout<<"conduction dfs on"<<v<<endl;
			int c=dfs(graph,n,isVisited,v);
//			cout<<"got count"<<c<<endl;
			if(c!=n-1)
			{
				cutcount++;
			}
		}
	}
	return cutcount;	
}

int main()
{
	
	int t;
	t=readInt();
//	cin>>t;
	while(t--)
	{
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
		writeInt(cutvertex(graph,n)*k);
	}
	return 0;
}
