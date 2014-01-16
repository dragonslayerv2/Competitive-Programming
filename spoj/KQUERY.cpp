#include<stdio.h>
#include<vector>
#include<climits>
#include<map>
#include<algorithm>
using namespace std;

//------------------------------------------------------------------------------
class BIT
{
	vector<long long> tree;
	int n;
	
	public:
		BIT(size_t size)
		{
			n=size;
			tree.resize(n+1);
		}
		long long read(int idx)
		{
			int sum=0;
			while(idx>0)
			{
				sum+=tree[idx];
				idx-=(idx&(-idx));
			}
			return sum;
		}
		
		void increase(int idx, int val)
		{ 
			if(idx<=0)
				return;
			while (idx <= n)
			{ 
				tree[idx] += val; 
				idx += (idx & (- idx)); 
			}
		}
		long long query(int a,int b)
		{
			return read(b)-read(a-1);
		}
};
//------------------------------------------------------------------------------

bool directaddressing;
int maxrank;
inline int find(map<int,int>& rank,int element)
{
	if(directaddressing)
		return element;
	int ans;
	map<int,int>::iterator i=rank.find(element);
	if(i==rank.end())
	{
		rank[element]=1;
		map<int,int>::iterator j=rank.find(element);
		j++;
		if(j==rank.end())
			ans=maxrank;		
		else
			ans=j->second;	
		rank.erase(element);
	}
	else
		ans=i->second;
	return ans;
}
int main()
{
	int n;
	scanf("%d",&n);
	
	map<int,int> rank;
	
	vector<int> array(n+1);
	int MAX=INT_MIN;
	for(int i=1;i<=n;i++)
	{
		scanf("%d",&array[i]);
		MAX=max(array[i],MAX);
	}
	
	if(MAX<1000000)
		directaddressing=true;
	else
		directaddressing=false;
	
	if(!directaddressing)
	{
		for(int i=1;i<=n;i++)
			rank[array[i]]=1;
		int k=2;
		for(map<int,int>::iterator i=rank.begin();i!=rank.end();i++,k++)
			i->second=k;
		maxrank=k;
	}
	else
		maxrank=MAX+1;
	
	int q;
	scanf("%d",&q);
	
	vector<vector<int> > queries(q,vector<int>(3));
	
	vector<pair<int,int> > position;
	
	for(int i=0;i<q;i++)
	{
		scanf("%d %d %d",&queries[i][0],&queries[i][1],&queries[i][2]);
		position.push_back(make_pair(queries[i][0]-1,queries[i][2]));
		position.push_back(make_pair(queries[i][1],queries[i][2]));
	}		
	
	sort(position.begin(),position.end());
	
	map<pair<int,int>,int> solution;
	int current=1;
	
	BIT tree(maxrank);
	for(int i=0;i<position.size();i++)
	{
		while(current<array.size()&&current<=position[i].first)	
		{
			tree.increase(find(rank,array[current]),1);
			current++;
		}
		solution[position[i]]=tree.query(find(rank,position[i].second+1),maxrank);
	}
	
	for(int i=0;i<queries.size();i++)
		printf("%d\n",solution[make_pair(queries[i][1],queries[i][2])]-solution[make_pair(queries[i][0]-1,queries[i][2])]);
}

