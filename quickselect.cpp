/*
	Name: Quick Select randomisation version
	Copyright: 
	Author: Shobhit Saxena
	Date: 06/12/13 21:34
	Description: This is a quick select algorithm use to find the ith smallest element in the array in O(n) time. 
					Randomised Version.
*/

#include<iostream>
#include<cstdlib>
#include<time.h>
#include<algorithm>
using namespace std;


template<class iterator,class compare>iterator random_partition(iterator begin, iterator end,const compare &cmp)
{
	iterator pivot=begin+((rand())%(end-begin));

	swap(*pivot,*(end-1));
	pivot=end-1;
	iterator k=begin;
	while(begin!=end)
	{
		if(cmp(*begin,*pivot))
		{
			swap(*begin,*k);
			k++;
		}
		begin++;
	}
	
	swap(*pivot,*k);
	return k;
}

template<class iterator,class compare> iterator select(iterator begin,iterator position,iterator end,const compare &cmp)
{
	iterator i=random_partition(begin,end,cmp);
	
	if(i==position)
		return i;
	else if(i<position)
		return select(i+1,position,end,cmp);
	else
		return select(begin,position,i,cmp);
}

int main()
{
	srand(time(NULL));
	int a[]={5,3,1,7,8,2,3,5};
	cout<<*(select(a,a+7,a+8,less<int>() ));
}
