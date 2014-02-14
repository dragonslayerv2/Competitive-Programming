#include<iostream>
#include<vector>
using namespace std;

typedef int value_type;

vector<value_type> tree;
vector<value_type> lazy;

bool inRange(size_t qx1,size_t qx2,size_t qy1,size_t qy2,size_t nx1,size_t nx2,size_t ny1,size_t ny2)
{
	if(nx2<nx1||ny2<ny1) // node is invalid.
		return false;
	if(qx2<nx1||qx1>nx2) // x is out of bounds
		return false;
	if(qy2<ny1||qy1>ny2) // y is out of bounds
		return false;
	return true;
}

inline size_t child(size_t node,size_t number)
{
	return node*4+number;
}


void update(size_t qx1,size_t qx2,size_t qy1,size_t qy2,size_t nx1,size_t nx2,size_t ny1,size_t ny2, size_t node, value_type &value)
{
	if(lazy[node])
	{
		tree[node]+=(lazy[node]*(nx2-nx1+1)*(ny2-ny1+1));
		if(nx1!=nx2&&ny1!=ny2)
		{
			lazy[child(node,1)]+=lazy[node];
			lazy[child(node,2)]+=lazy[node];
			lazy[child(node,3)]+=lazy[node];
			lazy[child(node,4)]+=lazy[node];
		}
		lazy[node]=0;
	}
	
	if(!inRange(qx1,qx2,qy1,qy2,nx1,nx2,ny1,ny2))
		return;
	else if(nx1>=qx1&&nx2<=qx2&&ny1>=qy1&&ny2<=qy2) // node is within query
	{
		tree[node]+=(value*(nx2-nx1+1)*(ny2-ny1+1));
		if(nx1!=nx2&&ny1!=ny2)
		{
			lazy[child(node,1)]+=value;
			lazy[child(node,2)]+=value;
			lazy[child(node,3)]+=value;
			lazy[child(node,4)]+=value;
		}
	}
	else
	{
		update(qx1,qx2,qy1,qy2,	nx1,(nx1+nx2)/2,ny1,(ny2+ny1)/2,        child(node,1), value);
		update(qx1,qx2,qy1,qy2,	nx1, (nx1+nx2)/2, (ny1+ny2)/2+1, ny2,   child(node,2), value);
		update(qx1,qx2,qy1,qy2,	(nx1+nx2)/2+1, nx2,	ny1, (ny2+ny1)/2,   child(node,3), value);
		update(qx1,qx2,qy1,qy2,	(nx1+nx2)/2+1, nx2, (ny1+ny2)/2+1, ny2, child(node,4), value);
		
		tree[node]=tree[child(node,1)]+tree[child(node,2)]+tree[child(node,3)]+tree[child(node,4)];
	}
}

value_type query (size_t qx1,size_t qx2,size_t qy1,size_t qy2,size_t nx1,size_t nx2,size_t ny1,size_t ny2,size_t node)
{
	if(lazy[node])
	{
		tree[node]+=(lazy[node]*(nx2-nx1+1)*(ny2-ny1+1));
		if(nx1!=nx2&&ny1!=ny2)
		{
			lazy[child(node,1)]+=lazy[node];
			lazy[child(node,2)]+=lazy[node];
			lazy[child(node,3)]+=lazy[node];
			lazy[child(node,4)]+=lazy[node];
		}
		lazy[node]=0;
	}
	
	if(!inRange(qx1,qx2,qy1,qy2,nx1,nx2,ny1,ny2))
		return 0;
	else if(nx1>=qx1&&nx2<=qx2&&ny1>=qy1&&ny2<=qy2)
		return tree[node];
	else
	{
		value_type LL=query(qx1,qx2,qy1,qy2, nx1,(nx1+nx2)/2, ny1,(ny2+ny1)/2,       child(node,1));
		value_type LR=query(qx1,qx2,qy1,qy2, nx1, (nx1+nx2)/2, (ny1+ny2)/2+1, ny2,   child(node,2));
		value_type RL=query(qx1,qx2,qy1,qy2, (nx1+nx2)/2+1, nx2, ny1, (ny2+ny1)/2,   child(node,3));
		value_type RR=query(qx1,qx2,qy1,qy2, (nx1+nx2)/2+1, nx2, (ny1+ny2)/2+1, ny2, child(node,4));
		return LL+LR+RL+RR;
	}
}

int main()
{
	freopen("test.txt","r",stdin);
	int n;
	cin>>n;
	tree.resize(16*n*n);
	
	int q;
	cin>>q;
	while(q--)
	{
		int type;
		cin>>type;
		int x1,x2,y1,y2;
		cin>>x1>>x2>>y1>>y2;
		if(type)
			cout<<query(x1,x2,y1,y2,0,n-1,0,n-1,0)<<endl;
		else
		{	
			value_type value;
			cin>>value;
			update(x1,x2,y1,y2,0,n-1,0,n-1,0,value);
		}
	}
}
