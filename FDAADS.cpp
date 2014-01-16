#include<iostream>
#include<algorithm>
using namespace std;


int main()
{
	
	
	int a[]={1,2,4,8,16,32};
	for(int i=0;i<20;i++)
	{
		cout<<binary_search(a,a+6,i)<<endl;
	}
	for(int i=0;i<20;i++)
	{
		cout<<*lower_bound(a,a+6,i)<<endl;
	}
	for(int i=0;i<20;i++)
	{
		cout<<*upper_bound(a,a+6,i)<<endl;
	}
/*	for(int i=0;i<20;i++)
	{
		cout<<*equal_range(a,a+6,i);
	}*/

}
