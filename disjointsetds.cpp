/*
	Name: Connected Components in Graph(Using Disjoint Set Data Structure)
	Copyright: 
	Author: Shobhit Saxena
	Date: 05/03/13 21:36
	Description: Disjoint Set data Structure. With path compression algorithm and effective parent matching in union.
*/

#include<iostream>
using namespace std;

#define MAX 100001
#define MOD 1000000007

struct node
{
	int parent;
	int children;
};


void makeset(node *a,int n)
{
	for(int i=1;i<=n;i++)
	{
		a[i].parent=i;
		a[i].children=1;
	}
}

node &root(node *a,int i)
{
	if(a[i].parent==i)
		return a[i];
	else // path compression algo
	{
		int temp_parent=a[i].parent;
		a[i].parent=root(a,a[i].parent).parent;
		if(temp_parent!=a[i].parent)
			a[temp_parent].children-=a[i].children;
		return a[a[i].parent];
	}
}

bool Union(node *a,int i,int j)
{
	node &iroot=root(a,i);
	node &jroot=root(a,j);
	
	if(iroot.parent==jroot.parent)
		return false;
	else if(iroot.children<jroot.children)
	{
		iroot.parent=jroot.parent;
		jroot.children+=iroot.children;
	}
	else
	{
		jroot.parent=iroot.parent;
		iroot.children+=jroot.children;
	}
	return true;
}


int main()
{	
	node vertices[MAX];
	int t;
	cin>>t;
	while(t--)
	{
		long long ways=1;
		int n,m;
		cin>>n>>m;
		makeset(vertices,n);
		int disconnected=n;
		for(int i=0;i<m;i++)
		{
			int a,b;
			cin>>a>>b;	
			if(Union(vertices,a,b)) disconnected--;
		}
		for(int i=1;i<=n;i++)
		{
			if(vertices[i].parent==i)
				ways=(ways*vertices[i].children)%MOD;
		}
		cout<<disconnected<<" "<<ways<<endl;
	}
	return 0;
}
