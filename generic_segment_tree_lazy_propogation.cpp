/*
	Name: Generic Segment Tree
	Copyright: 
	Author: Shobhit Saxena
	Date: 09/02/14 12:27
	Description: This is the generic implementation of Segment trees.
	Update the UpdateFunction and MergeFunction to change the behaviour of the tree.
*/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

//------------------------------------------------------------------------------
template<class T,class U, class MF,class UN,class L> class segmentTree
{
	public:
		typedef T value_type;
		typedef U update_type;
	private:
		vector<value_type> tree;
		vector<typename L::value_type> lazy;
		MF mergeFunction;
		UN updateNode;
		L propogate;
		
		size_t sz;
		bool inRange(size_t queryLeft,size_t queryRight,size_t nodeLeft,size_t nodeRight) const
		{
			if(nodeLeft > nodeRight || nodeLeft > queryRight || nodeRight < queryLeft)
				return false;
			return true;
		}
		
		size_t leftChild(size_t node)
		{
			return (node<<1)+1;
		}
		size_t rightChild(size_t node)
		{
			return (node<<1)+2;
		}
		
		value_type query(size_t queryLeft,size_t queryRight,size_t nodeLeft,size_t nodeRight,size_t node)
		{
			if(lazy[node]!=L::invalid_value)
			{
				tree[node]=propogate.updateNode(tree[node],lazy[node],nodeLeft,nodeRight);
				if(nodeLeft!=nodeRight)
				{
					lazy[leftChild(node)]=propogate.updateLazy(lazy[leftChild(node)],lazy[node]);
					lazy[rightChild(node)]=propogate.updateLazy(lazy[rightChild(node)],lazy[node]);
				}	
				lazy[node]=L::invalid_value;
			}
			
			if(nodeLeft>=queryLeft&&nodeRight<=queryRight)
				return tree[node];
			else
			{
				bool leftInRange=inRange(queryLeft,queryRight,nodeLeft,(nodeLeft+nodeRight)/2);
				bool rightInRange=inRange(queryLeft,queryRight,(nodeLeft+nodeRight)/2+1,nodeRight);
			
				if(leftInRange&&!rightInRange)
					return query(queryLeft,queryRight,nodeLeft,(nodeLeft+nodeRight)/2,leftChild(node));

				else if(!leftInRange&&rightInRange)
					return query(queryLeft,queryRight,(nodeLeft+nodeRight)/2+1,nodeRight,rightChild(node));
				
				else			
					return mergeFunction(query(queryLeft,queryRight,nodeLeft,(nodeLeft+nodeRight)/2,leftChild(node)),query(queryLeft,queryRight,(nodeLeft+nodeRight)/2+1,nodeRight,rightChild(node)));
			}
		}
		
		void update(size_t queryLeft,size_t queryRight,size_t nodeLeft,size_t nodeRight,size_t node,update_type value)
		{			
			if(lazy[node]!=L::invalid_value)
			{
				tree[node]=propogate.updateNode(tree[node],lazy[node],nodeLeft,nodeRight);
				if(nodeLeft!=nodeRight)
				{
					lazy[leftChild(node)]=propogate.updateLazy(lazy[leftChild(node)],lazy[node]);
					lazy[rightChild(node)]=propogate.updateLazy(lazy[rightChild(node)],lazy[node]);
				}	
				lazy[node]=L::invalid_value;
			}
			
			if(!inRange(queryLeft,queryRight,nodeLeft,nodeRight))
				return;
			
			else if(nodeLeft>=queryLeft&&nodeRight<=queryRight)
			{	
				tree[node]=propogate.updateNode(tree[node],value,nodeLeft,nodeRight);
				if(nodeLeft!=nodeRight)
				{
					lazy[leftChild(node)]=propogate.updateLazy(lazy[leftChild(node)],value);
					lazy[rightChild(node)]=propogate.updateLazy(lazy[rightChild(node)],value);
				}
			}
			else if(nodeLeft==nodeRight)
				tree[node]=updateNode(tree[node],value);
			else
			{
				update(queryLeft,queryRight,nodeLeft,(nodeLeft+nodeRight)/2,leftChild(node),value);
				update(queryLeft,queryRight,(nodeLeft+nodeRight)/2+1,nodeRight,rightChild(node),value);
				tree[node]=mergeFunction(tree[leftChild(node)],tree[rightChild(node)]);	
			}
		}
		
	public:
		segmentTree()
		{
			sz=0;
		}
		
		segmentTree(size_t size,value_type initial=value_type())
		{
			assign(size,initial);
		}
		
		segmentTree(const vector<value_type> &A)
		{
			clear();
			assign(A);
		}
		
		void assign(size_t size,value_type initial=value_type())
		{
			clear();
			sz=size;
			lazy.resize(4*size,L::default_value);
			tree.resize(4*size,initial);
		}
		
		void clear()
		{
			sz=0;
			tree.clear();
			lazy.clear();
		}
		
		void update(size_t left,size_t right,const update_type &value)
		{
			update(left,right,0,sz-1,0,value);
		}
		
		value_type query(size_t low,size_t high)
		{
			return query(low,high,0,sz-1,0);
		}
		~segmentTree()
		{
			clear();
		}	
};

//------------------------------------------------------------------------------

struct updateNode
{
	int operator()(int node,int newValue)
	{
		return node+newValue;
	}	
};

struct mergeNode
{
	int operator()(int left,int right)
	{
		return left+right;
	}
};

struct LazyUpdate
{
	typedef int value_type;
	static const int default_value;
	static const int invalid_value;
	int updateNode(int node,int lazy,size_t,size_t)
	{
		return node+lazy;
	}
	int updateLazy(int belowLazy,int lazy)
	{
		belowLazy+=lazy;
		return belowLazy;
	}
};
const int LazyUpdate::default_value=0;
const int LazyUpdate::invalid_value=0;
//------------------------------------------------------------------------------
int main()
{
	int n;
	cin>>n;
	segmentTree<int,int,mergeNode,updateNode,LazyUpdate> T(n,0);
	while(1)
	{
		int type, a,b,value;
		cin>>type>>a>>b;
		if(type)
		{
			cin>>value;
			T.update(a,b,value);
		}
		else
			cout<<T.query(a,b)<<endl;
	}
}
