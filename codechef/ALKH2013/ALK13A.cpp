#include<iostream>
#include<vector>
#include<map>
#include<list>
#include<algorithm>
using namespace std;
typedef vector<pair<long long, list<pair<int,int> > > > graph;

#include<stdio.h>
#ifdef ONLINE_JUDGE
	#define GETCHAR getchar_unlocked	
	#define PUTCHAR putchar_unlocked
#endif
#ifndef ONLINE_JUDGE
	#define GETCHAR getchar
	#define PUTCHAR putchar
#endif
	
inline int readlong() 
{
	int flag=1;
    long long n = 0;
    char c;
    int sign=1;
    while (1)
    { 
    			
              c=GETCHAR();
              if(c=='-')
              	sign=-1;
              else if(c>='0'&&c<='9') {n = n * 10 + c - '0';flag=0;}
              else if(flag!=1) break; 
                              
    }
    return sign*n;
}

int solution=-1;
bool accepted=false;
long long dfs(graph &G,vector<bool> &isvisited,int initial,int final,long long pathlength,long long danger=-1)
{
	if(accepted&&G[initial].first>solution)
		return -1;
	if(pathlength<0)
		return -1;	
	if(initial==final)
	{
		solution=max(danger,G[initial].first);
		accepted=true;
		return max(danger,G[initial].first);
	}
		
	
		
	danger=max(G[initial].first,danger);
	isvisited[initial]=true;
	int result=-1;
	for(list<pair<int,int > >::iterator i=G[initial].second.begin();i!=G[initial].second.end();i++)
	{
		if(!isvisited[i->first])
		{
			int newresult=dfs(G,isvisited,i->first,final,pathlength-i->second,danger);
			if(result==-1)
				result=newresult;
			else if(newresult!=-1&&result!=-1)
				result=min(newresult,result);
		}
	}
	isvisited[initial]=false;
	return result;
}
int main()
{
	int t;
	t=readlong();
	
	while(t--)
	{
		int n,k;
		n=readlong();
		k=readlong();
		//cin>>n>>k;
		graph G(n);
		for(int i=0;i<n;i++)
			G[i].first=readlong();
			//cin>>G[i].first;
	//	cout<<"OK";
		int m;
		int initial,final;
		m=readlong();
		initial=readlong();
		final=readlong();
		//cin>>m>>initial>>final;
		initial--;
		final--;
		for(int i=0;i<m;i++)
		{
			int a,b,c;
			a=readlong();
			b=readlong();
			c=readlong();
		//	cin>>a>>b>>c;
			a--;
			b--;
			G[a].second.push_back(make_pair(b,c));
			G[b].second.push_back(make_pair(a,c));
		}

		solution=-1;
		accepted=false;
		vector<bool> isvisited(n);
		cout<<dfs(G,isvisited,initial,final,k)<<endl;
	}	
}

