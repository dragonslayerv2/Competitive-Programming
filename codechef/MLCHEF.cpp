#include<iostream>
#include<vector>
#include<list>
using namespace std;

typedef vector<list<int> > tree;

class linearTree
{
	public:
		typedef vector<list<int> > tree;
	private:
		int p=0;
		tree &T;
		
		int dfs(int node)
		{
				p++;
				pos[node]=p;
				for(list<int>::iterator i=T[node].begin();i!=T[node].end();i++)
					child[node]+=dfs(*i);
				return 1+child[node];
		}
	public:
		vector<int> pos;
		vector<int> child;
		
	linearTree(tree &t):T(t)
	{
		pos.resize(t.size());
		child.resize(t.size(),0);
		dfs(0);
	}		
};


class segmentTree
{
	private:
		vector<int> MIN;
		vector<int> lazy;
		vector<int> count;
		int sz;
		static const int INVALID=INT_MAX;
		
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

		void buildTree(vector<int> &A,int nodeLeft, int nodeRight, int node)
		{		
			if(nodeLeft==nodeRight)
			{
				count[node]=1;
				MIN[node]=A[nodeLeft];
				lazy[node]=0;
			}		
			else
			{
				buildTree(A,nodeLeft,(nodeLeft+nodeRight)/2,leftChild(node));
				buildTree(A,(nodeLeft+nodeRight)/2+1,nodeRight,rightChild(node));

				count[node]	=count[leftChild(node)]+count[rightChild(node)];
				MIN[node]	=min(MIN[leftChild(node)],MIN[rightChild(node)]);
			}
		}
		
		void update(int queryLeft,int queryRight,int nodeLeft,int nodeRight,int node,int value)
		{
			if(!inRange(queryLeft,queryRight,nodeLeft,nodeRight)||count[node]==0)
				return;
			if(lazy[node])
			{
				if(nodeLeft!=nodeRight)
				{
					lazy[leftChild(node)]	+=lazy[node];
					lazy[rightChild(node)]	+=lazy[node];	
					
					MIN[leftChild(node)]	-=lazy[node];
					MIN[rightChild(node)]	-=lazy[node];
				}
				lazy[node]=0;
			}
			
			if(nodeLeft>=queryLeft&&nodeRight<=queryRight)
			{
				lazy[node]+=value;
				MIN[node]-=value;
				if(MIN[node]<=0)
				{		
					if(nodeLeft!=nodeRight)
					{	
						lazy[leftChild(node)]+=lazy[node];
						lazy[rightChild(node)]+=lazy[node];	
						
						MIN[leftChild(node)]-=	lazy[node];
						MIN[rightChild(node)]-=	lazy[node];
						
						update(queryLeft,queryRight,nodeLeft,(nodeLeft+nodeRight)/2,leftChild(node),0);
						update(queryLeft,queryRight,(nodeLeft+nodeRight)/2+1,nodeRight,rightChild(node),0);
						MIN[node]=min(MIN[leftChild(node)],MIN[rightChild(node)]);
						count[node]=count[leftChild(node)]+count[rightChild(node)];
					}
					else
					{
						MIN[node]=INT_MAX;
						count[node]=0;
					}	
					lazy[node]=0;		
				}
			}
			else
			{
				update(queryLeft,queryRight,nodeLeft,(nodeLeft+nodeRight)/2,leftChild(node),value);
				update(queryLeft,queryRight,(nodeLeft+nodeRight)/2+1,nodeRight,rightChild(node),value);
				MIN[node]=min(MIN[leftChild(node)],MIN[rightChild(node)]);
				count[node]=count[leftChild(node)]+count[rightChild(node)];
			}
		}
		int query(int queryLeft,int queryRight,int nodeLeft,int nodeRight,int node)
		{
			if(!inRange(queryLeft,queryRight,nodeLeft,nodeRight))
				return 0;
			else if(nodeLeft>=queryLeft&&nodeRight<=queryRight)
			 	return count[node];
			else
				return query(queryLeft,queryRight,nodeLeft,(nodeLeft+nodeRight)/2,leftChild(node))+query(queryLeft,queryRight,(nodeLeft+nodeRight)/2+1,nodeRight,rightChild(node));
		}
		
	public:
		segmentTree(vector<int> &array)
		{
			MIN.resize(4*array.size());
			lazy.resize(4*array.size());
			count.resize(4*array.size());
			sz=array.size()-1;
			buildTree(array,0,sz,0);
		}
		
		void update(int queryLeft,int queryRight,int value)
		{
			update(queryLeft,queryRight,0,sz,0,value);
		}
		int query(int queryLeft,int queryRight)
		{
			return query(queryLeft,queryRight,0,sz,0);
		}
};

int main()
{
	freopen("testMLCHEF.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	int n;
	cin>>n;
	
	tree T(n+1);
	vector<int> health(n+1);
	for(int i=1;i<=n;i++)
	{
		cin>>health[i];
		int superior;
		cin>>superior;
		T[superior].push_back(i);
	}
	linearTree LT(T);
	
	vector<int> linearHealth(T.size());
	for(int i=0;i<health.size();i++)
		linearHealth[LT.pos[i]]=health[i];
			
	segmentTree ST(linearHealth);
	
	int q;
	cin>>q;
	while(q--)
	{
		int type;
		cin>>type;
		if(type==1)
		{
			int a,x;
			cin>>a>>x;
			ST.update(LT.pos[a]+1,LT.pos[a]+LT.child[a],x);
		}
		else
		{
			int a;
			cin>>a;
			cout<<ST.query(LT.pos[a]+1,LT.pos[a]+LT.child[a])<<endl;
		}
	}
}
