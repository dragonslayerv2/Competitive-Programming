/*
	Name: Cartesian Tree (Reducing RMQ to LCA)
	Copyright: 
	Author: Shobhit Saxena
	Date: 11/03/13 14:45
	Description: This algorithm reduces RMQ to LCA problem. Preprocessing of O(n) Psace O(n) and Query O(h) where h is the height of the tree.
*/

#include<iostream>
#include<vector>
#include<list>
using namespace std;

#define value(a) (a.first)
#define parent(a) (a.second)


void preprocess(vector<pair<int,int> > &tree,int n)  //create a cartesian tree
{
	parent(tree[0])=-1;
	int p=0;
	for(int i=1;i<n;i++)
	{
		parent(tree[i])=p;
		p=i;
		while(parent(tree[p])!=-1&&value(tree[i])<value(tree[parent(tree[p])]))
		{	
			p=parent(tree[p]);
		}
		if(p!=i)
		{	parent(tree[i])=parent(tree[p]);
			parent(tree[p])=i;
			p=i;
		}
	}	
}


int LCA(vector<pair<int,int> > &tree, int i, int j)
{
	list<int> parentI;
	list<int> parentJ;
	
	int p;
	p=i;
	
	while(p!=-1)
	{
		parentI.push_front(p);
		p=parent(tree[p]);
	}
	p=j;
	
	while(p!=-1)
	{
		parentJ.push_front(p);
		p=parent(tree[p]);
	}
	
	list<int>::const_iterator I,J;
	
	for(I=parentI.begin(),J=parentJ.begin();I!=parentI.end()&&J!=parentJ.end();I++,J++)
	{
		if(*I!=*J)
			break;
	}
	I--;
	return *I;
}

int main()
{
	int n;
	cin>>n;
	
	vector<pair<int,int> > tree(n);
	for(int i=0;i<n;i++)
	{
		cin>>value(tree[i]);
	}
	
	preprocess(tree,n);
	
	for(int i=0;i<n;i++)
	{
		cout<<value(tree[i])<<" => "<<value(tree[parent(tree[i])])<<endl;
	}
	while(1)
	{
		int a,b;
		cin>>a>>b;
		cout<<value(tree[LCA(tree,a,b)])<<endl;
	}
	return 0;
}
