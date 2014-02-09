#include<iostream>
#include<vector>
using namespace std;

template<class T> class rangeUpdateDS
{
	public:
		typedef T value_type;
	private:
		vector<value_type> incrementArray;
		vector<value_type> array;
	public:
		//----------------------------------------------------------------------
		rangeUpdateDS(size_t n,value_type default_value=0)
		{
			assign(n,default_value);
		}
		template<class iterator> rangeUpdateDS(iterator begin,iterator end)
		{
			assign(begin,end);
		}
		//----------------------------------------------------------------------
		void assign(size_t n,value_type default_value=0)
		{
			array.clear();
			incrementArray.clear();
			incrementArray.assign(n+1,0); // one more for sentinel
			array.assign(n,default_value);
		}	
		//----------------------------------------------------------------------
		template<class iterator> void assign(iterator begin,iterator end)
		{
			array.clear();
			incrementArray.clear();
			while(begin!=end)
			{
				array.push_back(*begin);
				incrementArray.push_back(0);
				begin++;
			}
			incrementArray.push_back(0);
		}
		//----------------------------------------------------------------------
		void update(size_t low,size_t high,value_type value)
		{
			incrementArray[low]+=value;
			incrementArray[high+1]-=value;
		}
		//----------------------------------------------------------------------
		void process()
		{
			value_type current=0;	
			for(int i=0;i<array.size();i++)
			{
				current+=incrementArray[i];
				incrementArray[i]=0;
				array[i]+=current; // change this as per ur need.
			}
		}
		size_t size()
		{
			return array.size();
		}
		//----------------------------------------------------------------------
		value_type operator[](size_t pos)
		{
			return array[pos];
		}
		//----------------------------------------------------------------------
		void clear()
		{
			incrementArray.clear();
			array.clear();
		}
};


int main()
{
	int n,m,k;
	cin>>n>>m>>k;
	vector<long long> array(n);
	for(int i=0;i<n;i++)
		cin>>array[i];
	
	struct query
	{
		long long low,high,value;
		
		query()
		{}
		query(long long l,long long h,long long v)
		{
			low=l;
			high=h;
			value=v;
		}
	};
	
	vector<query> Q(m);
	for(int i=0;i<m;i++)
	{
		cin>>Q[i].low>>Q[i].high>>Q[i].value;
		Q[i].low--;
		Q[i].high--;
	}
	
	rangeUpdateDS<long long> QDS(m);
	while(k--)
	{
		int a,b;
		cin>>a>>b;
		a--;
		b--;
		QDS.update(a,b,1);
	}
	QDS.process();
	for(int i=0;i<QDS.size();i++)
		Q[i].value*=QDS[i];
		
	QDS.clear();
	QDS.assign(n);
	for(int i=0;i<Q.size();i++)
		QDS.update(Q[i].low,Q[i].high,Q[i].value);
	QDS.process();
	for(int i=0;i<array.size();i++)
		cout<<array[i]+QDS[i]<<" ";
	
}
