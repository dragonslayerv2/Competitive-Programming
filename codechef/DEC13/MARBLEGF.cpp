#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

template<class T> class BIT
{
	public:
		typedef T value_type;
	private:
		vector<T> tree;
		
	public:
		BIT(int n=0)
		{
				assign(n);
		}
		void assign(int n)
		{
			tree.clear();
			tree.resize(n+1);
		}
		void increase(size_t position, const T &val)
		{ 
			while (position <= tree.size()-1)
			{ 
				tree[position] += val; 
				position += (position & (- position)); 
			}
		}
		value_type query(size_t position) const
		{
			T sum=0;
			while(position>0)
			{
				sum+=tree[position];
				position-=(position&(-position));
			}
			return sum;
		}
		
		T query(size_t a,size_t b) const
		{
			return query(b)-query(a-1);
		}
		
		
};

int main()
{
	int n,q;
	cin>>n>>q;
	BIT<long long> bit(n);
	for(int i=1;i<=n;i++)
	{
		long long temp;
		cin>>temp;
		bit.increase(i,temp);
	}
	
	while(q--)
	{
		char ch;
		
		int first,second;
		cin>>ch>>first>>second;
		switch(ch)
		{
			case 'S': 	cout<<bit.query(first+1,second+1)<<endl;
						break;
			case 'G':	bit.increase(first+1,second);
						break;
			case 'T':	bit.increase(first+1,-1*second);
						break;
		}
	}
}
