#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
#include<list>
using namespace std;

class segmentTree
{
	public:
		typedef int value_type;
	
	private:
		vector<vector<value_type> > tree;

		//----------------------------------------------------------------------
		int leftChild(int node)
		{
			return (node<<1)+1;
		}
		int rightChild(int node)
		{
			return (node<<1)+2;
		}
		//----------------------------------------------------------------------
		bool inRange(int nodeLeft,int nodeRight,int queryLeft,int queryRight)
		{
			if(nodeLeft>nodeRight||nodeRight<queryLeft||nodeLeft>queryRight)
				return false;
			else
				return true;
		}
		//----------------------------------------------------------------------
		
		void buildTree(const vector<value_type> &A,int low,int high,int node)
		{
			if(low==high)
			{
				tree[node].resize(1);
				tree[node][0]=A[low];
			}
			else if(low>high)
				return;
			else
			{
				buildTree(A,low,(low+high)/2,leftChild(node));
				buildTree(A,(low+high)/2+1,high,rightChild(node));
				tree[node].resize(tree[leftChild(node)].size()+tree[rightChild(node)].size());
				merge(tree[leftChild(node)].begin(),tree[leftChild(node)].end(),tree[rightChild(node)].begin(),tree[rightChild(node)].end(),tree[node].begin());
			}
		}
		
		int queryEqual(int qLeft,int qRight,value_type value, int nLeft, int nRight, int node)
		{
			if(!inRange(nLeft,nRight,qLeft,qRight))
				return 0;
			else if(nLeft>=qLeft&&nRight<=qRight)
				return distance(lower_bound(tree[node].begin(),tree[node].end(),value),upper_bound(tree[node].begin(),tree[node].end(),value));
			else
				return queryEqual(qLeft,qRight,value,nLeft,(nLeft+nRight)/2,leftChild(node))+queryEqual(qLeft,qRight,value,(nLeft+nRight)/2+1,nRight,rightChild(node));

		}
		
		int queryLess(int qLeft,int qRight,value_type value, int nLeft, int nRight, int node)
		{
			if(!inRange(nLeft,nRight,qLeft,qRight))
				return 0;
			else if(nLeft>=qLeft&&nRight<=qRight)
				return distance(tree[node].begin(),lower_bound(tree[node].begin(),tree[node].end(),value));
			else
				return queryLess(qLeft,qRight,value,nLeft,(nLeft+nRight)/2,leftChild(node))+queryLess(qLeft,qRight,value,(nLeft+nRight)/2+1,nRight,rightChild(node));

		}
	public:
		segmentTree()
		{
		}
		segmentTree(const vector<value_type> &A)
		{
			assign(A);
		}
		
		void assign(const vector<value_type> &A)
		{
			tree.clear();
			tree.resize(4*A.size());
			buildTree(A,0,A.size()-1,0);
		}
		
		int queryLess(int left,int right,value_type value)
		{
			return queryLess(left,right,value,0,(tree.size()/4)-1,0);
		}	
		int queryEqual(int left,int right,value_type value)
		{
			return queryEqual(left,right,value,0,(tree.size()/4)-1,0);
		}
		int queryGreater(int left,int right,value_type value)
		{
			if(right<left)
				return 0;
			return (right-left+1) 
			- queryLess(left,right,value,0,(tree.size()/4)-1,0)
			- queryEqual(left,right,value,0,(tree.size()/4)-1,0);
		}
};

#ifdef ONLINE_JUDGE
	#define GETCHAR getchar_unlocked	
	#define PUTCHAR putchar_unlocked
#endif
#ifndef ONLINE_JUDGE
	#define GETCHAR getchar
	#define PUTCHAR putchar
#endif

inline int readlong() 
{
	int flag=1;
    int n = 0;
    char c;
    int sign=1;
    while (1)
    { 		
		c=GETCHAR();
    	if(c=='-')	sign=-1;
        else if(c>='0'&&c<='9') {n = n * 10 + c - '0';flag=0;}
        else if(flag!=1) break; 
    }
    return sign*n;
}

inline void writeInt(int x) 
{
     int i = 10;
     char buf[11];
     // buf[10] = 0;
     buf[10] = '\n';

     do 
     {
        buf[--i] = x % 10 + '0';
        x/= 10;
     }while(x);
     do 
     {
        PUTCHAR(buf[i]);
     } while (buf[i++] != '\n');
}
int main()
{
	#ifndef ONLINE_JUDGE
	freopen("in.txt","r",stdin);
	#endif
	int n=readlong(),m=readlong();
	vector<int> A(n);
	
	for(int i=0;i<n;i++)
		A[i]=readlong();

	long long inversions=0;

	segmentTree T(A);
	for(int i=0;i<n;i++)
		inversions+=T.queryLess(i+1,n-1,A[i]);
	
	while(m--)
	{
		int a,b;
		a=readlong();
		b=readlong();
		a--;
		b--;
		if(b<a)
			swap(a,b);
		/*
		cout<<"Querying for "<<a<<" "<<b<<endl;
		cout<<"Greater than "	<<A[a]<<" "<<T.queryGreater(a+1,b,A[a])	<<endl;
		cout<<"Less than "		<<A[a]<<" "<<T.queryLess(a+1,b,A[a])		<<endl;
		cout<<"Greater than "	<<A[b]<<" "<<T.queryGreater(a+1,b-1,A[b])		<<endl;
		cout<<"Less than "		<<A[b]<<" "<<T.queryLess(a+1,b-1,A[b])	<<endl;*/
		printf("%lld\n",inversions
			+ T.queryGreater(a+1,b,A[a])
			- T.queryLess(a+1,b,A[a])
			+ T.queryLess(a+1,b,A[b])
			- T.queryGreater(a+1,b,A[b]));
	}
}
