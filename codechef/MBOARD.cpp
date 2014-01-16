#include<stdio.h>
#include<vector>
using namespace std;


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


int main()
{
	int n,q;
	scanf("%d%d",&n,&q);
	
	vector<pair<int,bool> > RStime(n+1),CStime(n+1);
	vector<BIT> RS(2,BIT(q)),CS(2,BIT(q));
	
	for(int time=1;time<=q;time++)
	{
		char command[10];
		scanf("\n%s",command);
		int i,value;
		scanf("%d",&i);
		if(command[3]=='S')
			scanf("%d",&value);
		if(command[3]=='S')
		{
			if(command[0]=='R')
			{
				RS[RStime[i].second].increase(RStime[i].first,-1);
				RStime[i]=make_pair(time,value);
				RS[RStime[i].second].increase(RStime[i].first,1);
			}
			else
			{
				CS[CStime[i].second].increase(CStime[i].first,-1);
				CStime[i]=make_pair(time,value);
				CS[CStime[i].second].increase(CStime[i].first,1);
			}
		}
		else
		{
			long long ans=0;
			if(command[0]=='R')
			{
				if(RStime[i].second)
					ans+=CS[0].query(RStime[i].first,q);
				else
					ans=n-CS[1].query(RStime[i].first,q);	
			}
			else
			{
				if(CStime[i].second)
				{
					ans+=RS[0].query(CStime[i].first,q);
				}
				else
				{
					ans=n-RS[1].query(CStime[i].first,q);
				}
			}
			printf("%lld\n",ans);
		}		
	}
}
