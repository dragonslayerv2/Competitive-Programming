#include<iostream>
#include<queue>
#include<list>
#include<vector>
using namespace std;

typedef vector<list<int> > tree;

vector<bool> isVisisted;
vector<int> nodeLevel;
vector<vector<int> > solution;
vector<vector<int> > target1, target2;
vector<list<int> > paths;
int currentPathNumber;

tree T;

int solve(int node,bool isPartofChain)
{
	
	if(solution[isPartofChain][node]==-1)
	{
		target1[isPartofChain][node]=target2[isPartofChain][node]=-1;
		int allNewChainSum=0;
		for(list<int>::iterator i=T[node].begin();i!=T[node].end();i++)
			if(nodeLevel[*i]>nodeLevel[node])
				allNewChainSum+=solve(*i,false);
		
		int MIN=allNewChainSum;
		
		for(list<int>::iterator i=T[node].begin();i!=T[node].end();i++)
			if(nodeLevel[*i]>nodeLevel[node])
			{
				if(MIN>allNewChainSum+solve(*i,true)-solve(*i,false));
				{
					MIN=allNewChainSum+solve(*i,true)-solve(*i,false);
					target1[isPartofChain][node]=*i;
				}
			}
				
		if(!isPartofChain)
		{
			for(list<int>::iterator i=T[node].begin();i!=T[node].end();i++)
				if(nodeLevel[*i]>nodeLevel[node])
				{
					list<int>::iterator j=i;
					j++;
					for(;j!=T[node].end();j++)
						if(nodeLevel[*j]>nodeLevel[node])
							if(MIN>allNewChainSum+solve(*i,true)+solve(*j,true)-solve(*i,false)-solve(*j,false))
							{
								MIN=allNewChainSum+solve(*i,true)+solve(*j,true)-solve(*i,false)-solve(*j,false);
								target1[isPartofChain][node]=*i;
								target2[isPartofChain][node]=*j;
							}
				}
			MIN++;
		}
		solution[isPartofChain][node]=MIN;
	}
	return solution[isPartofChain][node];
}

void generatePath(int node,bool isPartofChain,char where)
{
	if(node==-1)
		return;
	else
	{
		if(where=='b')
			paths[currentPathNumber].push_back(node);
		else
			paths[currentPathNumber].push_front(node);
		
		generatePath(target1[isPartofChain][node],true,where);
		generatePath(target2[isPartofChain][node],true,(where=='b'?'f':'b'));
		for(list<int>::iterator i=T[node].begin();i!=T[node].end();i++)
			if(nodeLevel[*i]>nodeLevel[node])
				if(*i!=target1[isPartofChain][node]&&*i!=target2[isPartofChain][node])
				{
					currentPathNumber++;
					generatePath(*i,false,'b');
				}
	}
}
int main()
{
//	freopen("PT07Ftest.txt","r",stdin);
	
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		T.assign(n,list<int>());
		
		for(int i=0;i<n-1;i++)
		{	
			int a,b;
			cin>>a>>b;
			a--;
			b--;
			T[a].push_back(b);
			T[b].push_back(a);
		}

		nodeLevel.assign(n,-1);
		queue<int> Q;
		Q.push(0);
		nodeLevel[0]=0;
		
		while(!Q.empty())
		{
			int current=Q.front();
			Q.pop();
			for(list<int>::iterator i=T[current].begin();i!=T[current].end();i++)
			{
				if(nodeLevel[*i]==-1)
				{
					nodeLevel[*i]=1+nodeLevel[current];
					Q.push(*i);
				}
			}
		}
		solution=vector<vector<int> >(2,vector<int>(n,-1));
		target1=target2=vector<vector<int> >(2,vector<int>(n,-1));
		int totalPaths=solve(0,false);
		paths.assign(totalPaths,list<int>());
		currentPathNumber=0;
		generatePath(0,false,'b');
		cout<<paths.size()<<endl;
	/*	for(int i=0;i<paths.size();i++)
		{
			for(list<int>::iterator j=paths[i].begin();j!=paths[i].end();j++)
			{
				cout<<*j+1;
				if(*j!=paths[i].back())
					cout<<" ";
			}
			if(i!=paths.size()-1)
				cout<<endl;
		}
		if(t!=0)
			cout<<endl;*/
	}
}
