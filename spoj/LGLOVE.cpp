#include<stdio.h>
#include<vector>
using namespace std;


#define isSet(n) isprime[n>>5]&(1<<(n&31))
#define unset(n) isprime[n>>5] &= ~(1<<(n&31));
#define MAX 3000000
int isprime[MAX/32+2];

void sieve()
{
    int i,j;
    isprime[0]=0xA28A28AC;
    for(int i=1;i<=MAX/32+1;i+=3)
    {
            isprime[i]  =0x28A28A28;
            isprime[i+1]=0x8A28A28A;
            isprime[i+2]=0xA28A28A2;
    }
    for(i=5;i*i<=MAX;i+=2)
   		if(isSet(i))
        	for(j=i*i;j<=MAX;j+=i)
        		unset(j);
}
long long LCM[MAX];

#define MOD 1000000007
void preprocess()
{
	sieve();
	for(int i=0;i<MAX;i++)
		LCM[i]=1;
	
	LCM[0]=0;
	LCM[1]=1;
	
	for(int i=2;i<MAX;i++)
		if(isSet(i))
			for(long long j=i;j<MAX;j*=i)
			{
				LCM[j]*=i;
				LCM[j]%=MOD;
			}
	
	long long current=1;
	for(int i=2;i<MAX;i++)
	{
		current*=LCM[i];
		current%=MOD;
		LCM[i]=current;
	}
}

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
	pair<int,int> operator()(pair<int,int> node,int newValue)
	{
		return make_pair(node.first+newValue,node.second+newValue);
	}	
};

struct mergeNode
{
	pair<int,int> operator()(pair<int,int> left,pair<int,int> right)
	{
		return make_pair(min(left.first,right.first),max(left.second,right.second));
	}
};

struct LazyUpdate
{
	typedef int value_type;
	static const int default_value;
	static const int invalid_value;
	pair<int,int> updateNode(pair<int,int> node,int lazy,size_t,size_t)
	{
		return make_pair(node.first+lazy,node.second+lazy);
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
	preprocess();
	int n,m;
	scanf("%d %d",&n,&m);
	
	segmentTree<pair<int,int> ,int, mergeNode,updateNode,LazyUpdate> T(n);
	for(int i=0;i<n;i++)
	{
		int a;
		scanf("%d",&a);
		T.update(i,i,a);
	}
	while(m--)
	{
		int type,i,j,value;
		scanf("%d %d %d",&type,&i,&j);
		switch(type)
		{
			case 0: scanf("%d",&value);
					T.update(i,j,value);
					break;
			case 1:	printf("%d\n",LCM[T.query(i,j).second]);
					break;
			case 2:	printf("%d\n",LCM[T.query(i,j).first]);
					break;
		}
	}
}
