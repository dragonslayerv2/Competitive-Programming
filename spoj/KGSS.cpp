#include<stdio.h>
#include<vector>
using namespace std;

template<class T,class MF,class UN> class segmentTree
{
	public:
		typedef T value_type;
	
	private:
		vector<value_type> tree;
		MF mergeFunction;
		UN updateNode;
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
		
		void buildTree(const vector<value_type> &A,size_t low,size_t high, size_t node)
		{
			
			if(low==high)
				tree[node]=A[low];
			else if(low>high)
				return;
			else
			{
				buildTree(A,low,(low+high)/2,leftChild(node));
				buildTree(A,(low+high)/2+1,high,rightChild(node));
				tree[node]=mergeFunction(tree[leftChild(node)],tree[rightChild(node)]);
			}
		}
		
		value_type query(size_t queryLeft,size_t queryRight,size_t nodeLeft,size_t nodeRight,size_t node)
		{
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
		
		void update(size_t queryLeft,size_t queryRight,size_t nodeLeft,size_t nodeRight,size_t node,value_type value)
		{			
			if(!inRange(queryLeft,queryRight,nodeLeft,nodeRight))
				return;
			
			if(nodeLeft==nodeRight)
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
			tree.resize(4*size,initial);
		}
		
		void assign(const vector<value_type> &A) // assumes vector to be 0 indexed
		{
			assign(A.size());
			buildTree(A,0,A.size()-1,0);	
		}
		
		void clear()
		{
			sz=0;
			tree.clear();
		}
		
		void update(size_t pos,const value_type &value)
		{
			update(pos,pos,0,sz-1,0,value);
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


struct node
{
	int sum;
	int max;
	node()
	{
		sum=max=0;
	}
	node(int S,int M)
	{
		sum=S;
		max=M;
	}
};

struct updateNode
{
	node operator()(node N,node newValue)
	{
		return newValue;
	}	
};

struct mergeNode
{
	node operator()(node left,node right)
	{
		return node(max(left.max+right.max,max(left.sum,right.sum)),max(left.max,right.max));
	}
};

int main()
{
	int n;
	scanf("%d",&n);
	segmentTree<node,mergeNode,updateNode> T(n);
	for(int i=0;i<n;i++)
	{
		int n;
		scanf("%d",&n);
		T.update(i,node(-1000000000,n));
	}
	int q;
	scanf("%d",&q);
	while(q--)
	{
		char type;
		int a,b;
		scanf(" %c %d %d",&type,&a,&b);
		if(type=='Q')
		{	
			a--;
			b--;
			printf("%d\n",T.query(a,b).sum);
		}
		else
		{
			a--;
			T.update(a,node(-1000000000,b));
		}
	}	
}
