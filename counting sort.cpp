/*
	Name: Counting Sort
	Copyright: 
	Author: Shobhit Saxena
	Date: 15/12/13 05:44
	Description: This is the stable version of the counting sort algorithm.
					Running time: O(n+sigma)
					Space complexity: O(sigma)
*/

#include<iostream>
#include<limits>
#include<algorithm>
#include<vector>
using namespace std;


template<class T> class default_counting_hasher
{
	public:
		T operator ()(const T &x)
		{
			return x;
		}
};

template<class iterator,class hasher> void counting_sort(iterator _begin,iterator _end,hasher _hash=default_counting_hasher<typename iterator::value_type>(),size_t size=numeric_limits<typename iterator::value_type>::max()+1)
{
	vector<size_t> cumulative_frequency(size,0);
	
	for(iterator i=_begin;i<_end;i++)
		cumulative_frequency[_hash(*i)]++;
	
	for(size_t i=1;i<cumulative_frequency.size();i++)
		cumulative_frequency[i]+=cumulative_frequency[i-1];
	
	vector<typename iterator::value_type> final_array(_end-_begin);
	for(iterator i=_end-1;i>=_begin;i--)
		final_array[--cumulative_frequency[_hash(*i)]]=*i;
	
	copy(final_array.begin(),final_array.end(),_begin);
}

int main()
{
	vector<string> a(3);
	a[0]="123";
	a[1]="254";
	a[2]="144";
	
	counting_sort(a.begin(),a.end(),radix_hasher<char,string>(0),256);
	
	cout<<a[0]<<endl;
	cout<<a[1]<<endl;
	cout<<a[2]<<endl;
	
}
