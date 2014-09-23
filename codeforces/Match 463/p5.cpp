#include<iostream>
#include<vector>
#include<list>
#include<map>
#include<limits>
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

class sieve
{
	private:
		vector<int> isprime;
		bool isSet(int n) const
		{
			return (isprime[n>>5]&(1<<(n&31)));
		}
		bool unSet(int n)
		{
			isprime[n>>5] &= ~(1<<(n&31));
		}
		
		
	public:
		sieve(int MAX)
		{
			isprime.resize(MAX/32+10);
		
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
                		unSet(j);
		}
		
		bool isPrime(int n) const
		{
			return isSet(n);
		}	
		int size(){
			return isprime.size();
		}	
};

int main(){
	sieve S(2000);
	
	int n,q;
	cin>>n>>q;
	vector<int> values(n);
	for(int i=0;i<n;i++)
		cin>>values[i];
		
	vector<map<int,int> > nodeFactors(n);
	for(int i=0;i<n;i++){
		for(int j=0;j<S.size();j++)
		{
			if(S.isPrime(j)&&values[i]%j){
				while(values[i]%j)
					values[i]/=j;
				nodeFactors[i][j]++;
			}		
		}
		nodeFactors[i][values[i]]++;
	}
	
	HLD::tree T(n);
	for(int i=1;i<n;i++)
	{
		int a,b;
		cin>>a>>b;
		a--;
		b--;
		T[a].push_back(b);
		T[b].push_back(a);
	}
	
	HLD hld(T);
	
	vector<vector<map<int,int> > > factors(hld.chainSize.size());
	for(int i=0;i<hld.chainSize.size();i++)
			factors[i].assign(hld.chainSize[i],map<int,int>());
	
	for(int i=0;i<n;i++)
		factors[hld.chainNumber[i]][hld.chainPosition[i]]=nodeFactors[i];
	for(int i=0;i<factors.size();i++)
		for(int j=1;j<factors.size();j++)
			for(map<int,int>::iterator k = factors[i][j-1].begin();k!=factors[i][j-1].end();k++)
				factors[i][j][k->first]+=k->second;
		
	while(q--){
		int query;
		cin>>query;
		if(query==1){
			int n;
			cin>>n;
			n--;
			
			map<int,int> currentFactors;
		
			int node = n;
			while(1){
				for(map<int,int>::iterator i=factors[hld.chainNumber[node]][hld.chainPosition[node]].begin();i!=factors[hld.chainNumber[node]][hld.chainPosition[node]].end();i++)
				currentFactors[i->first]+=currentFactors[i->second];
				
				if(hld.chainHead[hld.chainNumber[node]]!=node)
					break;
				node = hld.chainHead[hld.chainNumber[node]];
			}
			bool flag=false;
			for(map<int,int>::iterator i = factors[n].begin();i!=factors[n].end();i++)
				
		}
		else{
			int vertex;
			int newValue;
			cin>>vertex;
			cin>>newValue;
		}
	}
}
