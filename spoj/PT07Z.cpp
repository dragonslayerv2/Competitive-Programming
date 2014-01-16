#include<iostream>
#include<vector>
#include<list>
#include<map>
using namespace std;

typedef vector<list<int> > tree;
vector<bool> isvisited;
pair<int,int> solve(tree &T,int source)
{
	if(isvisited[source])
		return make_pair(0,0);
	else
	{
		if(T[source].size()==1)
			return make_pair(0,0);
		else if(T[source].size()
	}
		
}
int main()
{
	tree T;
	int n;
	cin>>n;
	T.resize(n+1);
	isvisited.resize(n+1);
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		cin>>a>>b;
		T[a].push_back(b);
		T[b].push_back(a);
	}
	
	cout<<solve(T,1).second;
}
