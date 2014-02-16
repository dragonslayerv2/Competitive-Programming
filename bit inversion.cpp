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
	vector<pair<int,int> > marriage(n);
	map<int,int> male;
	map<int,int> female;
	for(int i=0;i<n;i++)
	{
		cin>>marriage[i].first>>marriage[i].second;
		female[marriage[i].second]++;
	}
	sort(marriage.begin(),marriage.end());
	int rank=1;
	for(map<int,int>::iterator i=female.begin();i!=female.end();i++)
		i->second=rank++;
	
	long long count=0;
	
	BIT<long long> T(rank+100);
	for(int i=0;i<n;i++)
	{
		count+=T.query(female[marriage[i].second],rank);
		T.increase(female[marriage[i].second],1);
	}
	cout<<count<<endl;
}
