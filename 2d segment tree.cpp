#include<iostream>
#include<vector>
using namespace std;

typedef int value_type;

vector<vector<value_type> > tree;

bool inRange(size_t qx1,size_t qx2,size_t qy1,size_t qy2,size_t nx1,size_t nx2,size_t ny1,size_t ny2)
{
	if(nx2<nx1||ny2<ny1) // node is invalid.
		return false;
	if(qx2<nx1||qx1>nx2)  // x is out of bounds
		return false;
	if(qy2<ny1||qy1>ny2)   // y is out of bounds
		return false;
	return true;
}

inline size_t leftChild(size_t node)
{
	return node*2+1;
}

inline size_t rightChild(size_t node)
{
	return node*2+2;
}

void update(size_t qx1,size_t qx2,size_t qy1,size_t qy2,size_t nx1,size_t nx2,size_t ny1,size_t ny2, size_t nodeX, size_t nodeY,value_type value)
{
	if(!inRange(qx1,qx2,qy1,qy2,nx1,nx2,ny1,ny2))
		return;
	else if(nx1>=qx1&&nx2<=qx2&&ny1>=qy1&&ny2<=qy2&&nx1==nx2&&ny1==ny2) // node is within query
		tree[nodeX][nodeY]+=value;
	else
	{
		update(qx1,qx2,qy1,qy2,	nx1,(nx1+nx2)/2,ny1,(ny2+ny1)/2, leftChild(nodeX), leftChild(nodeY), value);
		update(qx1,qx2,qy1,qy2,	nx1, (nx1+nx2)/2, (ny1+ny2)/2+1, ny2, leftChild(nodeX), rightChild(nodeY), value);
		update(qx1,qx2,qy1,qy2,	(nx1+nx2)/2+1, nx2,	ny1, (ny2+ny1)/2, rightChild(nodeX), leftChild(nodeY), value);
		update(qx1,qx2,qy1,qy2,	(nx1+nx2)/2+1, nx2, (ny1+ny2)/2+1, ny2, rightChild(nodeX), rightChild(nodeY), value);
		tree[nodeX][nodeY]=tree[leftChild(nodeX)][leftChild(nodeY)]+tree[leftChild(nodeX)][rightChild(nodeY)]+tree[rightChild(nodeX)][leftChild(nodeY)]+tree[rightChild(nodeX)][rightChild(nodeY)];
	}
}

value_type query (size_t qx1,size_t qx2,size_t qy1,size_t qy2,size_t nx1,size_t nx2,size_t ny1,size_t ny2,size_t nodeX,size_t nodeY)
{
	if(!inRange(qx1,qx2,qy1,qy2,nx1,nx2,ny1,ny2))
		return 0;
	else if(nx1>=qx1&&nx2<=qx2&&ny1>=qy1&&ny2<=qy2)
		return tree[nodeX][nodeY];
	else
	{
		value_type LL=query(qx1,qx2,qy1,qy2,	nx1,(nx1+nx2)/2,ny1,(ny2+ny1)/2, leftChild(nodeX), leftChild(nodeY));
		value_type LR=query(qx1,qx2,qy1,qy2,	nx1, (nx1+nx2)/2, (ny1+ny2)/2+1, ny2, leftChild(nodeX), rightChild(nodeY));
		value_type RL=query(qx1,qx2,qy1,qy2,	(nx1+nx2)/2+1, nx2,	ny1, (ny2+ny1)/2, rightChild(nodeX), leftChild(nodeY));
		value_type RR=query(qx1,qx2,qy1,qy2,	(nx1+nx2)/2+1, nx2, (ny1+ny2)/2+1, ny2, rightChild(nodeX), rightChild(nodeY));
		return LL+LR+RL+RR;
	}
}

int main()
{
	freopen("test.txt","r",stdin);
	int n;
	cin>>n;
	tree.resize(4*n,vector<value_type>(4*n));
	
	int q;
	cin>>q;
	while(q--)
	{
		int type;
		cin>>type;
		int x1,x2,y1,y2;
		cin>>x1>>x2>>y1>>y2;
		if(type)
			cout<<query(x1,x2,y1,y2,0,n-1,0,n-1,0,0)<<endl;
		else
		{	
			value_type value;
			cin>>value;
			update(x1,x2,y1,y2,0,n-1,0,n-1,0,0,value);
		}
	}
}
