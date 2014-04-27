#include<stdio.h>
#include<cmath>
#include<vector>
using namespace std;

template<class T> class segmentTree
{
	public:
		typedef T value_type;
	private:
		vector<value_type> MAX;
		vector<value_type> sum;
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
			{
				MAX[node]=A[low];
				sum[node]=A[low];
			}		
			else if(low>high)
				return;
			else
			{
				buildTree(A,low,(low+high)/2,leftChild(node));
				buildTree(A,(low+high)/2+1,high,rightChild(node));
				MAX[node]=max(MAX[leftChild(node)],MAX[rightChild(node)]);
				sum[node]=sum[leftChild(node)]+sum[rightChild(node)];
			}
		}
		
		value_type query(size_t queryLeft,size_t queryRight,size_t nodeLeft,size_t nodeRight,size_t node)
		{
			if(nodeLeft>=queryLeft&&nodeRight<=queryRight)
				return sum[node];
			else
			{
				bool leftInRange=inRange(queryLeft,queryRight,nodeLeft,(nodeLeft+nodeRight)/2);
				bool rightInRange=inRange(queryLeft,queryRight,(nodeLeft+nodeRight)/2+1,nodeRight);
			
				if(leftInRange&&!rightInRange)
					return query(queryLeft,queryRight,nodeLeft,(nodeLeft+nodeRight)/2,leftChild(node));

				else if(!leftInRange&&rightInRange)
					return query(queryLeft,queryRight,(nodeLeft+nodeRight)/2+1,nodeRight,rightChild(node));
				
				else			
					return query(queryLeft,queryRight,nodeLeft,(nodeLeft+nodeRight)/2,leftChild(node))+query(queryLeft,queryRight,(nodeLeft+nodeRight)/2+1,nodeRight,rightChild(node));
			}
		}	
		
		void update(size_t queryLeft,size_t queryRight,size_t nodeLeft,size_t nodeRight,size_t node)
		{			
			if(!inRange(queryLeft,queryRight,nodeLeft,nodeRight))
				return;
			if(MAX[node]==1)
				return;
			if(nodeLeft==nodeRight)
			{
				sum[node]=sqrt(sum[node]);
				MAX[node]=sum[node];
			}	
			else
			{
				update(queryLeft,queryRight,nodeLeft,(nodeLeft+nodeRight)/2,leftChild(node));
				update(queryLeft,queryRight,(nodeLeft+nodeRight)/2+1,nodeRight,rightChild(node));
				MAX[node]=max(MAX[leftChild(node)],MAX[rightChild(node)]);
				sum[node]=sum[leftChild(node)]+sum[rightChild(node)];
			}
		}
	public:
		segmentTree(const vector<value_type> &A)
		{
			assign(A);
		}
		
		void assign(size_t size)
		{
			sz=size;
			sum.assign(4*size,0);
			MAX.assign(4*size,0);
		}
		
		void assign(const vector<value_type> &A) // assumes vector to be 0 indexed
		{
			assign(A.size());
			buildTree(A,0,A.size()-1,0);	
		}	
		
		value_type query(size_t low,size_t high)
		{
			return query(low,high,0,sz-1,0);
		}
		
		void update(size_t a,size_t b)
		{
			update(a,b,0,sz-1,0);
		}
};

int main()
{
//	freopen("testGSS4.txt","r",stdin);
	int t=0;
	int n;
	while(scanf("%d",&n)>=0)
	{
		t++;
		printf("Case #%d:\n",t);
		vector<long long> array(n);
		for(int i=0;i<n;i++)
			scanf("%lld",&array[i]);
		
		int q;
		scanf("%d",&q);
	
		segmentTree<long long> ST(array);
		while(q--)
		{
			int type,a,b;
			scanf("%d %d %d",&type,&a,&b);
			
			a--;
			b--;
			
			if(a>b)
				swap(a,b);
			if(type==0)
				ST.update(a,b);
			else
					printf("%lld\n",ST.query(a,b));
		}
		printf("\n");
	}
}
