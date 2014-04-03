#include<iostream>
#include<vector>
#include<algorithm>
#include<map>
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
	int n;
	cin>>n;
	
	vector<int> array(n);
	map<int,int> rank;
	
	for(int i=0;i<n;i++)
	{
		cin>>array[i];
		rank[array[i]]=0;
	}
	
	int r=0;
	for(map<int,int>::iterator i=rank.begin();i!=rank.end();i++)
		i->second=(++r);

	BIT<long long> T(rank.size()+20);
	
	long long count=0;	
	
	for(int i=0;i<array.size();i++)
	{
		count+=T.query(rank[array[i]],rank.size());
		T.increase(rank[array[i]],1);
	}
	
	cout<<"Number of inversions are "<<count<<endl;
}
