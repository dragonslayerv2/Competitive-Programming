#include<iostream>
using namespace std;


long long maxsub(int a[],int n)
{
	long long global_sum=0;
	long long sum=0;
	for(int i=0;i<n;i++)
	{
		
		sum+=a[i];
		
		if(sum<0)
			sum=0;	
		
		if(global_sum<sum)
			global_sum=sum;
	}
	return global_sum;
}


int main()
{
	int a[]={-1,-2,-3};
	cout<<maxsub(a,3);
}
