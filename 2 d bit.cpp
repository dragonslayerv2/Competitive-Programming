#include<iostream>
#include<vector>
using namespace std;

template<class T> class DBIT
{
	public:
		typedef T value_type;
	private:
		vector<vector<value_type> > tree;
	public:
		DBIT(){}
		
		DBIT(size_t x,size_t y)
		{
			assign(x,y);
		}
		
		void assign(size_t x,size_t y)
		{
			tree.clear();
			tree.resize(x+1,vector<value_type>(y+1));
		}
	
	 	value_type read(size_t x,size_t y) const
		{
			value_type sum=0;
			while(x>0)
			{
				size_t dummyy=y;
				while(y>0)
				{
					sum+=tree[x][dummyy];
					dummyy-=(dummyy&(-dummyy));
				}
				x-=(x&(-x));
			}
			return sum;
		}
		
		void increase(size_t x,size_t y, const value_type &val)
		{ 
			while (x <= tree.size()-1)
			{ 
				int dummyy=y;
				while(y<=tree[x].size()-1)
				{
					tree[x][dummyy] += val;
					dummyy += (dummyy & (- dummyy)); 
				}
				x += (x & (- x));  
			}
		}
		value_type query(size_t i1,size_t j1,size_t i2,size_t j2) const
		{
			return read(i2,j2)-read(i1-1,j2)-read(i2,j1-1)+read(i1 - 1,j1 - 1);
		}
		void clear()
		{
			tree.clear();
		}
};

int main()
{
	DBIT<long long> a(6,5);
	a.increase(5,2,1);
	a.increase(6,3,1);
	cout<<a.read(5,2);
	cout<<a.read(6,3);
}
