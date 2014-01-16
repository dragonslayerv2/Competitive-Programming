#include<iostream>
using namespace std;

int coef[]={1,2,5,10};
int var(int total,int sum,int current=0)
{
	if(current==total)
	{
		if(sum==0)
			return 1;
		else
			return 0;
	}
	long long count=0;
	for(int i=0;i<=sum/coef[current]+1;i++)
	{
		count+=var(4,sum-coef[current]*i,current+1);
	}
	return count;
}

int main()
{
	cout<<var(4,19);
}
