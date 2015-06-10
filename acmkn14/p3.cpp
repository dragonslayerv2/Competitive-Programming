/*
	Name: Generic Segment Tree
	Copyright: 
	Author: Shobhit Saxena
	Date: 09/02/14 12:27
	Description: This is the generic implementation of Segment trees .
	Update the UpdateFunction and MergeFunction to change the behaviour of the tree .
*/

#include<iostream>
#include<vector>
#include<climits>
using namespace std;

template<class T> class segmentTree
{
	public:
		typedef T value_type;
	
	private:
		vector<value_type> tree;
		int sz;
		
		bool inRange(int queryLeft,int queryRight,int nodeLeft,int nodeRight) const
		{
			if(nodeLeft > nodeRight || nodeLeft > queryRight || nodeRight < queryLeft)
				return false;
			return true;
		}
		
		int leftChild(int node)
		{
			return (node<<1)+1;
		}
		int rightChild(int node)
		{
			return (node<<1)+2;
		}
		
		void buildTree(const vector<value_type> &A,int low,int high, int node)
		{
			
			if(low==high)
				tree[node]=A[low];
			else if(low>high)
				return;
			else
			{
				buildTree(A,low,(low+high)/2,leftChild(node));
				buildTree(A,(low+high)/2+1,high,rightChild(node));
				tree[node]=min(tree[leftChild(node)],tree[rightChild(node)]);
			}
		}
		
		value_type query(int queryLeft,int queryRight,int nodeLeft,int nodeRight,int node)
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
					return min(query(queryLeft,queryRight,nodeLeft,(nodeLeft+nodeRight)/2,leftChild(node)),query(queryLeft,queryRight,(nodeLeft+nodeRight)/2+1,nodeRight,rightChild(node)));
			}
		}
		
		void update(int queryLeft,int queryRight,int nodeLeft,int nodeRight,int node,value_type value)
		{			
			if(!inRange(queryLeft,queryRight,nodeLeft,nodeRight))
				return;
			
			if(nodeLeft==nodeRight)
				tree[node]=value;
			else
			{
				update(queryLeft,queryRight,nodeLeft,(nodeLeft+nodeRight)/2,leftChild(node),value);
				update(queryLeft,queryRight,(nodeLeft+nodeRight)/2+1,nodeRight,rightChild(node),value);
				
				tree[node]=min(tree[leftChild(node)],tree[rightChild(node)]);	
			}
		}
		
	public:
		segmentTree()
		{
			sz=0;
		}
		
		segmentTree(int size,value_type initial=value_type())
		{
			assign(size,initial);
		}
		
		segmentTree(const vector<value_type> &A)
		{
			clear();
			assign(A);
		}
		
		void assign(int size,value_type initial=value_type())
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
		
		void update(int pos,const value_type &value)
		{
			update(pos,pos,0,sz-1,0,value);
		}
		
		value_type query(int low,int high)
		{
			return query(low,high,0,sz-1,0);
		}
		~segmentTree()
		{
			clear();
		}	
};
template<class T> class BIT
{
	public:
		typedef T value_type;
	private:
		vector<value_type> tree;
	public:
		BIT(){}
		
		BIT(int n)
		{
			assign(n);
		}
		
		void assign(int n)
		{
			tree.clear();
			tree.resize(n+1);
		}
	
	 	value_type read(size_t idx) const
		{
			value_type sum=0;
			while(idx>0)
			{
				sum+=tree[idx];
				idx-=(idx&(-idx));
			}
			return sum;
		}
		
		class operationOn0Exception{};
		void increase(size_t idx, const value_type &val)
		{ 
			if(idx==0)
				throw operationOn0Exception();
			while (idx <= tree.size()-1)
			{ 
				tree[idx] += val; 
				idx += (idx & (- idx)); 
			}
		}
		value_type query(size_t a,size_t b) const
		{
			if(a>b)
				return 0;
			return read(b)-read(a-1);
		}
		void clear()
		{
			tree.clear();
		}
};
#include<cstdio>

int main()
{
	freopen("test2.txt","r",stdin);
	int n,m;
	cin>>n>>m;
	
	vector<long long> a(n);
	BIT<long long> bit(n+1);
	vector<long long> negativeArray(n);
	
	long long sum=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		negativeArray[i]=-a[i];
		bit.increase(i+1,a[i]);
	}
		
	
		
	vector<long long> previousDifference(n);
	vector<long long> nextDifference(n);
	for(int i=1;i<n;i++)
		previousDifference[i]=a[i]-a[i-1];
		
	for(int i=n-2;i>=0;i--)
		nextDifference[i]=a[i]-a[i+1];
		
	segmentTree<long long> minTree(negativeArray);
	segmentTree<long long> previousTree(previousDifference);
	segmentTree<long long> nextTree(nextDifference);

	while(m--){
		char type;
		cin>>type;
		
		switch(type){
			case 'U': int x,d;
					  cin>>x>>d;
					  bit.increase(x,d-bit.query(x,x));
					  x--;
					  a[x]=d;
					  
					  minTree.update(x,-d);
					  if(x+1<n)
					  	previousTree.update(x+1,a[x+1]-a[x]);
					  if(x-1>=0)
					  	previousTree.update(x,a[x]-a[x-1]);
					  
					  
					  if(x+1<n)
					  	nextTree.update(x,a[x]-a[x+1]);
					  if(x-1>=0)
					  	nextTree.update(x-1,a[x-1]-a[x]);
					  
					break;
			case 'M':
					int l,r;
					cin>>l>>r;
					l--;r--;
					cout<<-1*minTree.query(l,r)<<endl;
					break;
			case 'S':
					int a,b;
					cin>>a>>b;
					cout<<bit.query(a,b)<<endl;
					break;
			case 'I':
					int p,q;
					cin>>p>>q;
					p--;
					q--;
					if(p==q)
						cout<<1<<endl;
					else{
						if(previousTree.query(p+1,q)>=0)
							cout<<1<<endl;
						else
							cout<<0<<endl;
					}
					break;
			
			case 'D':{
	
					int p,q;
					cin>>p>>q;
					p--;
					q--;
					if(p==q)
						cout<<1<<endl;
					else{
						if(nextTree.query(p,q-1)>=0)
							cout<<1<<endl;
						else
							cout<<0<<endl;
					}
							}
					break;
		}
	}	
}
