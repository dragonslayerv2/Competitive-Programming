#include<iostream>
#include<queue>
using namespace std;

struct cmp
{
	bool operator ()(int a,int b)
	{
		return a>b;
	}
};

int main()
{
	int n,m;
	cin>>n>>m;
	
	priority_queue<int,vector<int>,cmp> Q1,Q2;
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		Q1.push(a);
	}
	
	for(int i=0;i<m;i++)
	{
		int a;
		cin>>a;
		Q2.push(a);
	}
	
	while(!Q1.empty()&&!Q2.empty())
	{
		while(!Q2.empty()&&Q2.top()<Q1.top())
			Q2.pop();
		if(!Q2.empty())
		{
			Q1.pop();
			Q2.pop();
		}
	}
	cout<<Q1.size();
}
