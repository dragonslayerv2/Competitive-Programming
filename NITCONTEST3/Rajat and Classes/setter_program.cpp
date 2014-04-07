#include<iostream>
#include<map>
#include<algorithm>
#include<vector>
using namespace std;


class disjointSet
{
	private:
		struct node
		{
			int parent;
			int children;
			node(int P=-1,int C=0)
			{
				parent=P;
				children=C;
			}
		};
		
		vector<node> a;
		int _size;
		node &_root(int i)
		{		
			if(a[i].parent==i)
				return a[i];
			else // path compression algo
			{
				int temp_parent=a[i].parent;
				a[i].parent=_root(a[i].parent).parent;
				if(temp_parent!=a[i].parent)
				a[temp_parent].children-=a[i].children;
				return a[a[i].parent];
			}
		}
		
		public:
		disjointSet(){}
		
		disjointSet(int n)
		{
			assign(n);
		}
		
		void assign(int n)
		{
			_size=n;
			a.assign(n,node());
			for(int i=0;i<a.size();i++)
				a[i]=node(i,0);
		}
		
		int root(int i)
		{
			return _root(i).parent;
		}
		void Union(int i,int j)
		{
			node &iroot=_root(i);
			node &jroot=_root(j);
	
			if(iroot.parent==jroot.parent)
				return;
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
			_size--;
		}
		
		int size()
		{
			return _size;
		}
};

int main()
{
	int n,c;
	cin>>n>>c;
	disjointSet S(n);
	vector<int> friendshipCount	(n);
	while(c--)
	{
		int a,b;
		cin>>a>>b;
		a--;
		b--;
		S.Union(a,b);
		friendshipCount[a]++;
		friendshipCount[b]++;
	}
	cout<<S.size()<<endl;
	
	map<int,int> representatives;
	for(int i=0;i<n;i++)
	{
		int root=S.root(i);
		if(representatives.find(root)==representatives.end())
			representatives[root]=i;
		else if(friendshipCount[representatives[root]]<friendshipCount[i])
			representatives[root]=i;
		else if(friendshipCount[representatives[root]]==friendshipCount[i])
		{
			if(representatives[root]>i)
				representatives[root]=i;
		}
	}
	vector<int> output;
	for(map<int,int>::iterator i=representatives.begin();i!=representatives.end();i++)
		output.push_back(i->second+1);
	sort(output.begin(),output.end());
	for(int i=0;i<output.size();i++)
		cout<<output[i]<<" ";
}
