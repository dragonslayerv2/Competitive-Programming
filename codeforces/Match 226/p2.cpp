#include<iostream>
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
			tree.resize(n+10);
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
	string a;
	cin>>a;
	a=' '+a;
	
	int current_match=0;
	string match="bear";
	
	BIT<int> bit(a.size());
	
	long long count=0;
	for(int j=1;j<a.size();j++)
	{
		if(a[j]==match[current_match])
			current_match++;
		else
			current_match=0;
		
		if(current_match==4)
		{
			bit.increase(j-3,1);
			current_match=0;	
		}
		
		for(int i=1;i<=j;i++)
		{
			if(bit.query(i,j))
			{
			cout<<a.substr(i,j-i+1)<<endl;
				count++;
			}
		}
	}
	cout<<count;
}
