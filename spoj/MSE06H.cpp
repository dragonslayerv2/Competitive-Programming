#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

template<class T> class BIT
{
	public:
		typedef T value_type;
	private:
		vector<value_type> tree;
	public:
		BIT(){}
		
		BIT(int n)
		{
			assign(n);
		}
		
		void assign(int n)
		{
			tree.clear();
			tree.resize(n+1);
		}
	
	 	value_type read(size_t idx) const
		{
			value_type sum=0;
			while(idx>0)
			{
				sum+=tree[idx];
				idx-=(idx&(-idx));
			}
			return sum;
		}
		
		void increase(size_t idx, const value_type &val)
		{ 
			while (idx <= tree.size()-1)
			{ 
				tree[idx] += val; 
				idx += (idx & (- idx)); 
			}
		}
		value_type query(size_t a,size_t b) const
		{
			return read(b)-read(a-1);
		}
		void clear()
		{
			tree.clear();
		}
};

int main()
{
	int t;
	scanf("%d",&t);
	for(int T=1;T<=t;T++)
	{
		int n,m,k;
		scanf("%d %d %d",&n,&m,&k);
		vector<pair<int,int> > array(k);
		for(int i=0;i<k;i++)
			scanf("%d %d",&array[i].first,&array[i].second);
		
		sort(array.begin(),array.end());
		BIT<long long> bit(2000);
		
		long long count=0;
		for(int i=0;i<k;i++)
		{
			count+=bit.query(array[i].second+1,1000);
			bit.increase(array[i].second,1);
		}	
		printf("Test case %d: %lld\n",T,count);
	}
}
