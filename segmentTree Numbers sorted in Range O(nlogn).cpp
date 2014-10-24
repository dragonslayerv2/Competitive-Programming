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
		size_t leftChild(size_t node)
		{
			return (node<<1)+1;
		}
		size_t rightChild(size_t node)
		{
			return (node<<1)+2;
		}
		//----------------------------------------------------------------------
		bool inRange(size_t nodeLeft,size_t nodeRight,size_t queryLeft,size_t queryRight)
		{
			if(nodeLeft>nodeRight||nodeRight<queryLeft||nodeLeft>queryRight)
				return false;
			else
				return true;
		}
		//----------------------------------------------------------------------
		
		void buildTree(const vector<value_type> &A,size_t low,size_t high,size_t node)
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
		
		size_t query(size_t qLeft,size_t qRight,value_type value, size_t nLeft, size_t nRight, size_t node)
		{
			if(!inRange(nLeft,nRight,qLeft,qRight))
				return 0;
			else if(nLeft>=qLeft&&nRight<=qRight)
				return distance(lower_bound(tree[node].begin(),tree[node].end(),value),upper_bound(tree[node].begin(),tree[node].end(),value));
			else
				return query(qLeft,qRight,value,nLeft,(nLeft+nRight)/2,leftChild(node))+query(qLeft,qRight,value,(nLeft+nRight)/2+1,nRight,rightChild(node));

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
		
		size_t query(size_t left,size_t right,value_type value)
		{
			return query(left,right,value,0,(tree.size()/4)-1,0);
		}	
};


int main()
{
	freopen("test.txt","r",stdin);
	int n;
	cin>>n;
	vector<int> A(n);
	for(int i=0;i<n;i++)
		cin>>A[i];
	segmentTree T(A);
	
	int q;
	cin>>q;
	while(q--)
	{
		int a,b;
		cin>>a>>b;
		int value;
		cin>>value;
		cout<<T.query(a,b,value);
		cout<<endl;
	}
}
