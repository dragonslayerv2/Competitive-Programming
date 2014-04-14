#include<stdio.h>
//#include<iostream>
#include<vector>
#include<queue>
#include<list>
#include<stack>
using namespace std;


typedef vector<list<int> > tree;
int main()
{
	freopen("test.txt","r",stdin);
	int n;
	scanf("%d",&n);
	
	tree T(n+1);
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		
		T[a].push_back(b);
		T[b].push_back(a);
	}
	
	vector<int> level(n+1);
	
	queue<int> Q;
	Q.push(1);
	level[1]=1;
	
	stack<int> S;
	
	while(!Q.empty())
	{
		int current=Q.front();
		S.push(current);
		Q.pop();
		for(list<int>::iterator i=T[current].begin();i!=T[current].end();i++)
			if(level[*i]==0)
			{
				level[*i]=level[current]+1;
				Q.push(*i);
			}
	}
	
	vector<vector<int> > DP(3,vector<int>(n+1));
	while(!S.empty())
	{
		int current=S.top();
		S.pop();
		
		//cout<<S.size()<<" Solving "<<current<<endl;
		DP[1][current]=1;
		for(list<int>::iterator i=T[current].begin();i!=T[current].end();i++)
			if(level[*i]==level[current]+1)
			{
					DP[1][current]+=DP[0][*i];
					DP[2][current]+=DP[1][*i];		
			}

		DP[0][current]=min(DP[1][current],DP[2][current]);// maybe
	}
	printf("%d",DP[0][1]);
}
