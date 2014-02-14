#include<iostream>
#include<vector>
using namespace std;

template<class T> class BIT
{
	public:
		typedef T value_type;
	private:
		vector<value_type> tree[2];
		
		void increase(int treeNumber,int idx, const value_type &val)
		{ 
			while (idx <= tree[treeNumber].size()-1)
			{ 
				tree[treeNumber][idx] += val; 
				idx += (idx & (- idx)); 
			}
		}
		
		value_type _query(int treeNumber,int idx) const
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
	
		value_type query(int idx)
		{
			return _query(0,idx)+idx*_query(1,idx);
		}
		
		
		
		value_type update(int a,int b,const value_type &v)
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
		
		value_type query(int a,int b)
		{
			return query(b)-query(a-1);
		}
};


int main()
{
	int n,m,w;
	cin>>n>>m>>w;
	BIT<long long> x(n);
	BIT<long long> y(m);
	
	long long sum=0;
	while(w--)
	{
		int type;
		cin>>type;
		
		
		long long x1,y1,x2,y2;
		cin>>x1>>y1>>x2>>y2;
		if(type)
		{
			cout<<(x.query(x1,x2)+y.query(y1,y2)-sum)<<endl;
		}
		else
		{
			long long value;
			cin>>value;
			sum+=value*(x2-x1+1)*(y2-y1+1);
			x.update(x1,x2,value*(y2-y1+1));
			y.update(y1,y2,value*(x2-x1+1));
		}
	}
	
}
