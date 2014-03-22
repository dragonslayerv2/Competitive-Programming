#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;


//--------------------------------------------------------------------------
#define MAX 1000
int isprime[MAX/32+2];

#define isSet(n) isprime[n>>5]&(1<<(n&31))
#define unset(n) isprime[n>>5] &= ~(1<<(n&31));

vector<int> primeList;
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
                
    for(int i=2;i<=MAX;i++)
    	if(isSet(i))
    		primeList.push_back(i);
}

//---------------------------------------------------------------------------------------------------------
class segmentTree
{
	private:
		vector<vector<pair<int,int> > > tree;
		vector<vector<int> > countTree; 
		
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
		
		void buildTree(const vector<vector<pair<int,int> > > &A,size_t low,size_t high, size_t node)
		{
			if(low==high)
			{
				tree[node]=A[low];
				for(int i=0;i<tree[node].size();i++)
					countTree[node].push_back(1);
			}
			
			else if(low>high)
				return;
			
			else
			{
				buildTree(A,low,(low+high)/2,leftChild(node));
				buildTree(A,(low+high)/2+1,high,rightChild(node));
				
				int lpos=0;
				int rpos=0;
				
				int lChild=leftChild(node);
				int rChild=rightChild(node);
				
				//--------------- merge function -------------------------
				while(lpos<tree[lChild].size()&&rpos<tree[rChild].size())
				{
					if(tree[lChild][lpos].first<tree[rChild][rpos].first)
					{
						tree[node].push_back(tree[lChild][lpos]);
						countTree[node].push_back(countTree[lChild][lpos]);
						lpos++;
					}
					else if(tree[lChild][lpos].first>tree[rChild][rpos].first)
					{
						tree[node].push_back(tree[rChild][rpos]);
						countTree[node].push_back(countTree[rChild][rpos]);
						rpos++;
					}
					else
					{
						if(tree[lChild][lpos].second>tree[rChild][rpos].second)
						{
							tree[node].push_back(tree[lChild][lpos]);	
							countTree[node].push_back(countTree[lChild][lpos]);
						}
						else if(tree[lChild][lpos].second<tree[rChild][rpos].second)
						{
							tree[node].push_back(tree[rChild][rpos]);	
							countTree[node].push_back(countTree[rChild][rpos]);
						}
						else
						{
							tree[node].push_back(tree[lChild][lpos]);
							countTree[node].push_back(countTree[lChild][lpos]+countTree[rChild][rpos]);
						}
						lpos++;
						rpos++;
					}
					
				}
				while(lpos<tree[lChild].size())
				{
					tree[node].push_back(tree[lChild][lpos]);
					countTree[node].push_back(countTree[lChild][lpos]);
					lpos++;
				}
				while(rpos<tree[rChild].size())
				{
					tree[node].push_back(tree[rChild][rpos]);
					countTree[node].push_back(countTree[rChild][rpos]);
					rpos++;
				}
			
			}
				/*
				cout<<"At node "<<node<<endl;
				cout<<"responsible for "<<low<<" "<<high<<endl;
				cout<<"Values"<<endl;
				for(int i=0;i<tree[node].size();i++)
					cout<<tree[node][i].first<<" "<<tree[node][i].second<<" "<<countTree[node][i]<<endl;
				cout<<endl;*/
		}
	public:
		segmentTree(vector<vector<pair<int,int> > > a)
		{
			tree.resize(4*a.size());
			for(int i=0;i<tree.size();i++)
				tree[i].reserve(50);
			countTree.resize(4*a.size());
			for(int i=0;i<countTree.size();i++)
				countTree[i].reserve(50);
			buildTree(a,0,a.size()-1,0);
		}
		pair<int,int> query(int G,int queryLeft,int queryRight,int nodeLeft,int nodeRight,int node)
		{
			if(nodeLeft>=queryLeft&&nodeRight<=queryRight)
			{
				int currentMax=-1;
				int currentCount=-1;
				for(int i=0;i<tree[node].size();i++)
				{
					if(G%tree[node][i].first==0&&tree[node][i].second>currentMax)
					{
						currentMax=tree[node][i].second;
						currentCount=countTree[node][i];
					}
				}
				return make_pair(currentMax,currentCount);
			}
			else
			{
				bool leftInRange=inRange(queryLeft,queryRight,nodeLeft,(nodeLeft+nodeRight)/2);
				bool rightInRange=inRange(queryLeft,queryRight,(nodeLeft+nodeRight)/2+1,nodeRight);
			
				if(leftInRange&&!rightInRange)
					return query(G,queryLeft,queryRight,nodeLeft,(nodeLeft+nodeRight)/2,leftChild(node));

				else if(!leftInRange&&rightInRange)
					return query(G,queryLeft,queryRight,(nodeLeft+nodeRight)/2+1,nodeRight,rightChild(node));
				else
				{
					pair<int,int> first=query(G,queryLeft,queryRight,nodeLeft,(nodeLeft+nodeRight)/2,leftChild(node));
					pair<int,int> second=query(G,queryLeft,queryRight,(nodeLeft+nodeRight)/2+1,nodeRight,rightChild(node));
					
					if(first.first>second.first)
						return first;
					else if(first.first<second.first)
						return second;
					else
					{
						if(first.first==-1)
							return make_pair(-1,-1);
						return make_pair(first.first,first.second+second.second);
					}
				}	
			}
		}
		pair<int,int> query(int G,int l,int h)
		{
		
			return query(G,l,h,0,tree.size()/4-1,0);
		}
};

int occr(vector<int> &O,int l,int h)
{
	return upper_bound(O.begin(),O.end(),h)-lower_bound(O.begin(),O.end(),l);
}
int main()
{
	sieve();
	int n;
	scanf("%d",&n);
		int m;
	scanf("%d",&m);
	vector<vector<pair<int,int> > > a(n);
	
	vector<vector<int> > occurances(100010);
	
	for(int i=0;i<n;i++)
	{
		int x;
		scanf("%d",&x);
		occurances[x].push_back(i);
		
		int tempX=x;
		for(int j=0;j<primeList.size()&&tempX>=primeList[j];j++)
		{
			if(tempX%primeList[j]==0)
			{
				a[i].push_back(make_pair(primeList[j],x));
				while(tempX%primeList[j]==0)
					tempX/=primeList[j];
			}
			else if(isSet(tempX))
			{
				a[i].push_back(make_pair(tempX,x));
				break;
			}
		}
	}
	
	segmentTree T(a);
	
	for(int i=0;i<m;i++)
	{
		int G,l,h;
		scanf("%d %d %d",&G,&l,&h);
		l--;
		h--;
		pair<int,int> solution=T.query(G,l,h);
	
		for(int i=0;i<primeList.size();i++)
			while(G&primeList[i]==0)
				G/=primeList[i];
		
		if(G>1)
		{
			for(int i=1;i*G<=100001;i++)
			{
				int count=occr(occurances[i*G],l,h);
				if(count>1)
					solution=max(solution,make_pair(i*G,count));
			}
		}

		printf("%d %d\n",solution.first,solution.second);
	}
}
