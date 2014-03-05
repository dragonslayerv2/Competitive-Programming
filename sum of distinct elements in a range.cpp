#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

//--------------------------------------------------------------------------
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

//--------------------------------------------------------------------------

struct query
{
	int x,y;
	int pos;
	bool operator <(const query &q2) const
	{
		if(y==q2.y)
			return x<q2.x;
		return y<q2.y;	
	}
};
int main()
{
	freopen("test.txt","r",stdin);
	int n;
	cin>>n;
	vector<int> a(n+1);
	for(int i=1;i<=n;i++)
		cin>>a[i];
	
	int m;
	cin>>m;
	vector<query> Q(m);
	for(int i=0;i<m;i++)
	{
		cin>>Q[i].x>>Q[i].y;	
		Q[i].pos=i;
	}
	
	sort(Q.begin(),Q.end());
	
	BIT<long long> rangeSum(n);
	BIT<long long> duplicateSum(n);
	map<int,int>   lastOccurence;
	vector<long long> output(m);
	
	int lastInserted=1;
	for(int i=0;i<Q.size();i++)
	{
		while(lastInserted<=Q[i].y)
		{
			rangeSum.increase(lastInserted,a[lastInserted]);
			if(lastOccurence[a[lastInserted]]!=0)
				duplicateSum.increase(lastOccurence[a[lastInserted]],a[lastInserted]);
				
			lastOccurence[a[lastInserted]]=lastInserted;
			lastInserted++;
		}
		output[Q[i].pos]=rangeSum.query(Q[i].x,Q[i].y)-duplicateSum.query(Q[i].x,Q[i].y);
	}
	for(int i=0;i<output.size();i++)
		cout<<output[i]<<endl;
}
