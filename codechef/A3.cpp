#include<iostream>
#include<vector>
#include<map>
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
		size_t size()
		{
			return array.size();
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
	struct query
	{
		char op;
		int number;
		bool yes;
	};
	
	int t;
	cin>>t
	while(t--)
	{
		int n;
		cin>>n;
		vector<query> Q(n);
		for(int i=0;i<n;i++)
		{
			cin>>Q[i].op>>Q[i].number;
			char YES[4];
			cin>>YES;
			Q[i].yes=(YES[0]=='Y');
		}
	
		map<int,int> ranks;
		for(int i=0;i<n;i++)
		{
			ranks[Q[i].number-1]=0;
			ranks[Q[i].number]=0;
			ranks[Q[i].number+1]=0;
		}
	
		int currentRank=0;
		for(map<int,int>::iterator i=ranks.begin();i!=ranks.end();i++,currentRank++)
			i->second=currentRank;
	
		rangeUpdateDS<int> array(ranks.size());
	
		for(int i=0;i<Q.size();i++)
		{
					if(Q[i].op=='<'&&Q[i].yes)
						array.update(0,ranks[Q[i].number-1],1);
			else 	if(Q[i].op=='<'&&!Q[i].yes)
						array.update(ranks[Q[i].number],array.size()-1,1);
			else 	if(Q[i].op=='='&&Q[i].yes)
						array.update(ranks[Q[i].number],ranks[Q[i].number],1);
			else 	if(Q[i].op=='='&&!Q[i].yes)
					{
						array.update(0,ranks[Q[i].number-1],1);
						array.update(ranks[Q[i].number+1],array.size()-1,1);
					}
			else 	if(Q[i].op=='>'&&Q[i].yes)
						array.update(ranks[Q[i].number+1],array.size()-1,1);
			else 	if(Q[i].op=='>'&&!Q[i].yes)
						array.update(0,ranks[Q[i].number],1);
		}
		array.process();
		int MAX=0;
		for(map<int,int>::iterator i=ranks.begin();i!=ranks.end();i++)
		{
			if(i->first>=1&&i->first<=1000000000)
				MAX=max(MAX,array[i->second]);
		}
		cout<<n-MAX<<endl;
	}
}
