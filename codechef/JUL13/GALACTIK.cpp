#include<iostream>
#include<limits>
using namespace std;

#define MAX 100005
#define MOD 1000000007
#define INVALID numeric_limits<int>::max()
struct node
{
	int parent;
	int children;
	int min;
};


void makeset(node *a,int n)
{
	for(int i=1;i<=n;i++)
	{
		a[i].parent=i;
		a[i].children=1;	
		a[i].min=INVALID;
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
		jroot.min=min(jroot.min,iroot.min);
		
	}
	else
	{
		jroot.parent=iroot.parent;
		iroot.children+=jroot.children;
		iroot.min=min(jroot.min,iroot.min);
	}
	return true;
}

node vertices[MAX];
int main()
{	
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

	int global_min=INVALID;
	int global_min_pos=-1;
	for(int i=1;i<=n;i++)
	{
		int m;
		cin>>m;
		if(m>=0)
		{	
			node &r=root(vertices,i);
			r.min=min(r.min,m);
			if(r.min<global_min)
			{
				global_min=r.min;
				global_min_pos=r.parent;
			}
		}
	}
	
	long long cost=0;
	for(int i=1;i<=n&&(disconnected>1);i++)
	{
		
		int MIN=root(vertices,i).min;
		if(MIN==INVALID ) break;
		if(Union(vertices,i,global_min_pos))
		{
			cost+=global_min+MIN;
			disconnected--;
			
		}
	}
	
	if(disconnected==1)
		cout<<cost;	
	
	else
		cout<<-1;
}
