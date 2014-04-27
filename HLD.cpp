#include<iostream>
#include<limits>
#include<vector>
#include<list>
#include<queue>
using namespace std;


class HLD
{
	public:
		typedef vector<list<int> > tree;		
	private:
		tree &T;

		void doHLD(int cur=0)
		{
			chainNumber[cur]=chainSize.size()-1;
			chainPosition[cur]=chainSize.back();
			chainSize.back()++;
			
			int maxTreeSize=numeric_limits<int>::min();
			int maxTreeSizeNode=-1;
			
			for(list<int>::iterator i=T[cur].begin();i!=T[cur].end();i++)
				if(nodeLevel[*i]>nodeLevel[cur])
					if(maxTreeSize<treeSize[*i])
					{
						maxTreeSize=treeSize[*i];
						maxTreeSizeNode=*i;
					}
			
			if(maxTreeSizeNode==-1)
				return;
			doHLD(maxTreeSizeNode);

			for(list<int>::iterator i=T[cur].begin();i!=T[cur].end();i++)
				if(nodeLevel[*i]>nodeLevel[cur])
					if(*i!=maxTreeSizeNode)
					{
						chainSize.push_back(0);
						chainHead.push_back(cur);
						doHLD(*i);
					}
		}
		
		void calculateTreeSize(int node)
		{
			treeSize[node]=1;
			for(list<int>::iterator i=T[node].begin();i!=T[node].end();i++)
			{
				if(nodeLevel[*i]>nodeLevel[node])
				{
					calculateTreeSize(*i);
					treeSize[node]+=treeSize[*i];
				}
			}
		}	
		
	public:
		vector<int> chainHead;
		vector<int> chainNumber;
		vector<int> chainPosition;
		vector<int> chainSize;
		vector<int> nodeLevel;
		vector<int> treeSize;
		HLD(tree &t,int start=0):T(t)
		{
			chainHead.reserve(T.size());
			chainNumber.resize(T.size());
			chainPosition.resize(T.size());
			chainSize.reserve(T.size());
			nodeLevel.resize(T.size(),-1);
			treeSize.resize(T.size());
						
			chainSize.push_back(0);
			chainHead.push_back(-1);
			// bfs for finding the level of the node
			
			queue<int> Q;
			nodeLevel[start]=0;
			Q.push(start);
			while(!Q.empty())
			{
				int current=Q.front();
				Q.pop();
				for(list<int>::iterator i=T[current].begin();i!=T[current].end();i++)
				{
					if(nodeLevel[*i]==-1)
					{
						nodeLevel[*i]=nodeLevel[current]+1;
						Q.push(*i);
					}
				}
			}

			// dfs
			calculateTreeSize(start);
			doHLD(start);
		}
};


int main()
{
	freopen("testHLD.txt","r",stdin);
	HLD::tree T;
	int n;
	cin>>n;
	T.resize(n);
	int e;
	cin>>e;
	while(e--)
	{
		int a,b;
		cin>>a>>b;
		T[a].push_back(b);
		T[b].push_back(a);
	}
	HLD hld(T);
}
