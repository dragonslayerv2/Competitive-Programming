#include<iostream>
#include<vector>
using namespace std;

class directAddressingTable
{
	private:
		vector<int> ID;
		vector<int> subTreeSize;
		vector<bool> isPresent;
		int sz;
		
		bool inRange(int queryLeft,int queryRight,int nodeLeft,int nodeRight) const
		{
			if(nodeLeft > nodeRight || nodeLeft > queryRight || nodeRight < queryLeft)
				return false;
			return true;
		}
		
		int leftChild(int node) const
		{
			return (node<<1)+1;
		}
		
		int rightChild(int node) const
		{
			return (node<<1)+2;
		}
		
		int parent(int node) const
		{
			return (node-1)/2;
		}
		void buildTree(int low,int high,int node)
		{
			if(low==high)
				ID[node]=low;
			else
			{
				buildTree(low,				(low+high)/2,	leftChild(node));
				buildTree((low+high)/2+1,	high,			rightChild(node));
			}
		}

		int query(int nodeLeft,int nodeRight,int node, int k) const
		{	
			if(k<=0||nodeLeft>nodeRight||subTreeSize[node]<k)
				return INVALID;
			
			if(nodeLeft==nodeRight)
				return ID[node];
			else
			{
				if(subTreeSize[leftChild(node)]>=k)
					return query(nodeLeft,(nodeLeft+nodeRight)/2,leftChild(node),k);
				else
					return query((nodeLeft+nodeRight)/2+1,nodeRight,rightChild(node),k-subTreeSize[leftChild(node)]);
			}
		}
		
		int rankQuery(int nodeLeft,int nodeRight,int node,int k) const
		{
			if(nodeLeft==nodeRight)
				return subTreeSize[node];
			if(inRange(k,k,nodeLeft,(nodeLeft+nodeRight)/2))
				return rankQuery(nodeLeft,(nodeLeft+nodeRight)/2,leftChild(node),k);
			else 
				return subTreeSize[leftChild(node)]+rankQuery((nodeLeft+nodeRight)/2+1,nodeRight,rightChild(node),k);
		}
		
		void update(int nodeLeft,int nodeRight,int node,int k,bool setValue)
		{
			if(!inRange(k,k,nodeLeft,nodeRight))
				return;
			
			else if(nodeLeft==nodeRight)
				subTreeSize[node]=setValue;
			else
			{
				update(nodeLeft,(nodeLeft+nodeRight)/2,leftChild(node),k,setValue);
				update((nodeLeft+nodeRight)/2+1,nodeRight,rightChild(node),k,setValue);
				subTreeSize[node]=subTreeSize[leftChild(node)]+subTreeSize[rightChild(node)];
			}
		}
		
	public:
		static const int INVALID =-1;
		directAddressingTable(){}
		directAddressingTable(int SZ)
		{
			assign(SZ);
		}
		void assign(int SZ)
		{
			sz=0;
			ID.assign(4*SZ,-1);
			subTreeSize.assign(4*SZ,0);
			isPresent.assign(SZ,false);
			buildTree(0,ID.size()/4-1,0);
		}
		void clear()
		{
			ID.clear();
			subTreeSize.clear();
			isPresent.clear();
		}
		int size() const
		{
			return sz;
		}
		
		int maxRange() const
		{
			return ID.size()/4-1;
		}
		int front() const
		{
			return kthElement(1);
		}
		
		int back() const
		{
			return kthElement(sz);
		}
		void insert(int pos)
		{
			if(!isPresent[pos])
			{
				sz++;
				update(0,ID.size()/4-1,0,pos,true);
				isPresent[pos]=true;
			}
		}
		void remove(int pos)
		{
			if(isPresent[pos])
			{
				sz--;
				update(0,ID.size()/4-1,0,pos,false);
				isPresent[pos]=false;
			}
		}
		int kthElement(int k) const
		{
			return query(0,ID.size()/4-1,0,k);
		}
		
		int rank(int k) const
		{
			return rankQuery(0,ID.size()/4-1,0,k);
		}
		bool isElement(int k) const
		{
			return isPresent[k];
		}
		int successor(int k) const
		{
			int node=0;
			int nodeLeft=0;
			int nodeRight=ID.size()/4-1;
			while(nodeLeft!=nodeRight)
			{
				if(inRange(k,k,nodeLeft,(nodeLeft+nodeRight)/2))
				{
					nodeLeft=nodeLeft;
					nodeRight=(nodeLeft+nodeRight)/2;
					node=leftChild(node);
				}
				else
				{
					nodeLeft=(nodeLeft+nodeRight)/2+1;
					nodeRight=nodeRight;
					node=rightChild(node);
				}
			}
			while(node!=0)
			{
				
				while(node==rightChild(parent(node)))
				{
					node=parent(node);
					if(node==0)
						return -1;
				}
					
				node=parent(node);
				
				if(subTreeSize[rightChild(node)])
				{
					node=rightChild(node);
					break;
				}
			}
			
			if(node==0)
				return -1;
			
			while(ID[node]==-1)
			{
				if(subTreeSize[leftChild(node)])
					node=leftChild(node);
				else
					node=rightChild(node);
			}
			return ID[node];
		}
		
		int predecessor(int k) const
		{
			int node=0;
			int nodeLeft=0;
			int nodeRight=ID.size()/4-1;
			while(nodeLeft!=nodeRight)
			{
				if(inRange(k,k,nodeLeft,(nodeLeft+nodeRight)/2))
				{
					nodeLeft=nodeLeft;
					nodeRight=(nodeLeft+nodeRight)/2;
					node=leftChild(node);
				}
				else
				{
					nodeLeft=(nodeLeft+nodeRight)/2+1;
					nodeRight=nodeRight;
					node=rightChild(node);
				}
			}
		
			while(node!=0)
			{
				while(node==leftChild(parent(node)))
				{
					node=parent(node);
					if(node==0)
						return -1;
				}
				node=parent(node);
				if(subTreeSize[leftChild(node)])
				{
					node=leftChild(node);
					break;
				}
			}
			if(node==0)
				return -1;
			
			while(ID[node]==-1)
			{
				if(subTreeSize[rightChild(node)])
					node=rightChild(node);
				else
					node=leftChild(node);
			}
			return ID[node];
		}
};
const int directAddressingTable::INVALID;

int main()
{
//	freopen("DATtest.txt","r",stdin);
	int n;
	cin>>n;
	directAddressingTable DAT(n);
	int q;
	cin>>q;
	while(q--)
	{
		char type;
		int a;
		cin>>type;
		
		if(type=='i')
		{
			cin>>a;
			DAT.insert(a);
		}
		else if(type =='d')
		{
			cin>>a;
			DAT.remove(a);
		}	
		else if(type=='k')
		{
			cin>>a;
			cout<<DAT.kthElement(a)<<endl;
		}
		else if(type=='f')
			cout<<DAT.front()<<endl;
		else if(type=='b')
			cout<<DAT.back()<<endl;
		else if(type=='r')
		{
			cin>>a;
			cout<<DAT.rank(a)<<endl;
		}
		else if(type=='s')
		{
			cin>>a;
			cout<<DAT.successor(a)<<endl;
		}
		else if(type=='p')
		{
			cin>>a;
			cout<<DAT.predecessor(a)<<endl;
		}
	}
}
