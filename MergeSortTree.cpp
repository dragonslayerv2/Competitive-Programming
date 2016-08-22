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
		
		int rankQuery(int qLeft,int qRight,value_type value, int nLeft, int nRight, int node)
		{
			if(!inRange(nLeft,nRight,qLeft,qRight))
				return 0;
			else if(nLeft>=qLeft&&nRight<=qRight)
				return distance(tree[node].begin(),lower_bound(tree[node].begin(),tree[node].end(),value));
			else
				return rankQuery(qLeft,qRight,value,nLeft,(nLeft+nRight)/2,leftChild(node))+rankQuery(qLeft,qRight,value,(nLeft+nRight)/2+1,nRight,rightChild(node));

		}
		
		int kthQuery(int qLeft,int qRight, int rank, int nLeft,int nRight,int node){
			if(nLeft==nRight)
				return nLeft;
			else {
				int leftNode=leftChild(node);
				int inRangeLeftElements=distance(lower_bound(tree[leftNode].begin(),tree[leftNode].end(),qLeft),
												 upper_bound(tree[leftNode].begin(),tree[leftNode].end(),qRight));
				if(inRangeLeftElements>=rank)
					return kthQuery(qLeft,qRight,rank,nLeft,(nLeft+nRight)/2,leftChild(node));
				else{
					return kthQuery(qLeft,qRight,rank-inRangeLeftElements,(nLeft+nRight)/2+1,nRight,rightChild(node));
				}
			}
		}
		
	public:
		segmentTree()
		{}
		
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
		
		int rankQuery(int left,int right,value_type value)
		{
			return rankQuery(left,right,value,0,(tree.size()/4)-1,0);
		}
		
		int kthQuery(int left,int right,int rank){
			return kthQuery(left,right,rank,0,(tree.size()/4)-1,0);
		}
};


int main()
{
	ios::sync_with_stdio(false);
	int n;
	cin>>n;
	vector<int> A(n);
	vector<int> position(n);
	
	for(int i=0;i<n;i++)
	{
		cin>>A[i];
		position[A[i]]=i;	
	}
		
	segmentTree rankTree(A);
	segmentTree kTree(position);
	
	int q;
	cin>>q;
	while(q--)
	{
		int type;
		cin>>type;
		int a,b;
		cin>>a>>b;
		int x;
		cin>>x;
		if(type==0)
			cout<<kTree.kthQuery(a,b,x);
		else
			cout<<rankTree.rankQuery(a,b,x);
		cout<<endl;
		
	}
}
