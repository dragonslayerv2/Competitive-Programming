/*
	Name: RangeUpdate Data Structure
	Copyright: 
	Author: Shobhit Saxena
	Date: 08/02/14 13:03
	Description: This data structure Process the range update queries once and output the array at last.
				O(1) per query + O(n) in the end.
*/

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
	int n;
	cin>>n;
	rangeUpdateDS<int> DS(n);
	int q;
	cin>>q;
	while(q--)
	{
		int a,b;
		cin>>a>>b;
		DS.update(a,b,1);
	}	
	DS.process();
	for(int i=0;i<n;i++)
		cout<<DS[i]<<" ";
}
