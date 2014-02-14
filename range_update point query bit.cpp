/*
	Name: Rabnge Update Point Query BIT
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
		vector<value_type> tree;
		
		void increase(size_t idx, const value_type &val)
		{ 
			while (idx <= tree.size()-1)
			{ 
				tree[idx] += val; 
				idx += (idx & (- idx)); 
			}
		}
	public:
		BIT(){}
		
		BIT(size_t n)
		{
			assign(n);
		}
		
		void assign(int n)
		{
			tree.clear();
			tree.resize(n+1);
		}
	
	 	value_type query(size_t idx) const
		{
			value_type sum=0;
			while(idx>0)
			{
				sum+=tree[idx];
				idx-=(idx&(-idx));
			}
			return sum;
		}
		
		value_type update(size_t a,size_t b,const value_type &value)
		{
			increase(a,value);
			increase(b+1,-value);
			
		}
		void clear()
		{
			tree.clear();
		}
};


int main()
{
	BIT<long long> a(5);
	a.update(2,3,2);
	a.update(1,4,1);
	cout<<a.query(3);
}
