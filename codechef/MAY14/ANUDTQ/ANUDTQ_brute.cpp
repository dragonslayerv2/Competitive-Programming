#include<iostream>
#include<vector>
#include<list>
using namespace std;

vector<bool> alreadyDeleted;
vector<list<int> > tree;
vector<long long> nodeValues;


void addAll(int key,long long value)
{
	if(alreadyDeleted[key])
		return;
	else
	{
		nodeValues[key]+=value;
		for(list<int>::iterator i=tree[key].begin();i!=tree[key].end();i++)
			addAll(*i,value);
	}
}

void removeAll(int key)
{
	if(alreadyDeleted[key]) return;
	else
	{
		alreadyDeleted[key]=true;
		for(list<int>::iterator i=tree[key].begin();i!=tree[key].end();i++)
			removeAll(*i);
	}
}
long long query(int key)
{
	if(alreadyDeleted[key]) return 0;
	long long sum=nodeValues[key];
	for(list<int>::iterator i=tree[key].begin();i!=tree[key].end();i++)
		sum+=query(*i);
	return sum;
}

int main()
{	
	int n;
	cin>>n;
	tree.resize(n);
	alreadyDeleted.resize(n);
	nodeValues.resize(n);
	
	for(int i=0;i<n;i++)
		cin>>nodeValues[i];
	
	for(int i=0;i<n-1;i++)
	{
		int a,b;
		cin>>a>>b;
		tree[a].push_back(b);
	}
	
	int m;
	cin>>m;
	while(m--)
	{
		int type;
		cin>>type;
		int key;
		cin>>key;
		if(type==1)	
		{
			long long value;
			cin>>value;
			alreadyDeleted.push_back(false);
			tree[key].push_back(tree.size());
			tree.push_back(list<int>());
			nodeValues.push_back(value);
		}
		if(type==2)
		{
			long long value;
			cin>>value;
			addAll(key,value);
		}
		if(type==3)
			removeAll(key);
		if(type==4)
			cout<<query(key)<<endl;
	}
	
}
