/*
	Name: Rabnge Update Range Query BIT
	Copyright: 
	Author: Shobhit Saxena
	Date: 14/02/14 19:08
	Description: http://kartikkukreja.wordpress.com/2013/12/02/range-updates-with-bit-fenwick-tree/
*/

#include<iostream>
#include<vector>
using namespace std;

template<class T> class BIT
{
	public:
		typedef T value_type;
	private:
		vector<value_type> tree[2];
		
		void increase(size_t treeNumber,size_t idx, const value_type &val)
		{ 
			while (idx <= tree[treeNumber].size()-1)
			{ 
				tree[treeNumber][idx] += val; 
				idx += (idx & (- idx)); 
			}
		}
		
		value_type _query(size_t treeNumber,size_t idx) const
		{
			value_type sum=0;
			while(idx>0)
			{
				
				sum+=tree[treeNumber][idx];
				idx-=(idx&(-idx));
			}
			return sum;
		}
	public:
		BIT(){}
		
		BIT(size_t n)
		{
			assign(n);
		}
		
		void assign(int n)
		{
			tree[0].clear();
			tree[1].clear();
			tree[0].resize(n+2);
			tree[1].resize(n+2);
		}
	
		value_type query(size_t idx)
		{
			return _query(0,idx)+idx*_query(1,idx);
		}
		
		
		
		value_type update(size_t a,size_t b,const value_type &v)
		{
			increase(0,a,(1-a)*v);
			increase(0,b+1,b*v);
			increase(1,a,v);
			increase(1,b+1,-v);
		}
		void clear()
		{
			tree.clear();
		}
		
		value_type query(size_t a,size_t b)
		{
			return query(b)-query(a-1);
		}
};


int main()
{
	BIT<long long> a(5);
	a.update(2,3,2);
	a.update(1,4,1);
	cout<<a.query(1,5);
}
