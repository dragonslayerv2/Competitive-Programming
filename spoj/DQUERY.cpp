#include<stdio.h>
#include<map>
#include<algorithm>
#include<vector>
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
struct event
{
	int a;
	int b;
	int pos;
	char type;
	
	bool operator <(const event &x) const
	{
		if(type==x.type)
			return b<x.b;
		else if(b==x.b)
		{
			if(type=='n')
				return true;
			else
				return false;
		}
		else
			return b<x.b;
	}
	event()
	{}
	
	event(int A,int B,char T,int P=0)
	{
		a=A;
		b=B;
		type=T;
		pos=P;
	}
	
};
//------------------------------------------------------------------------------

int main()
{
	int n;
	scanf("%d",&n);
	vector<event> events;
	
	map<int,int> lastpos;
	for(int i=1;i<=n;i++) 
	{
		int a;
		scanf("%d",&a);
		events.push_back(event(lastpos[a],i,'n'));
		lastpos[a]=i;
	}
	
	int q;
	scanf("%d",&q);
	for(int i=0;i<q;i++)
	{
		int a,b;
		scanf("%d %d",&a,&b);
		events.push_back(event(a,b,'q',i));
	}
	
	sort(events.begin(),events.end());
	
	BIT tree(n);
	vector<int> solution(q);
	
	for(int i=0;i<events.size();i++)
	{
		if(events[i].type=='q')
			solution[events[i].pos]=events[i].b-events[i].a+1-tree.query(events[i].a,events[i].b);
		else
			tree.increase(events[i].a,1);
	}
	
	for(int i=0;i<solution.size();i++)
		printf("%d\n",solution[i]);
}
