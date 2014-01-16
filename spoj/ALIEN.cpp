#include<stdio.h>
#include<vector>
using namespace std;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long a,b;
		scanf("%lld %lld",&a,&b);
		
		vector<long long> array(a);
		for(int i=0;i<a;i++)
			scanf("%lld",&array[i]);
	
		long long MAXsum=0;
		long long MAXlength=0;
		
		int start=0;
		int end=0;
		long long current_sum=0;
		while(end<a)
		{
			current_sum+=array[end];
			while(current_sum>b)
			{
				current_sum-=array[start];
				start++;
			}
			if(end-start+1==MAXlength&&MAXsum>current_sum)
			{
				MAXlength=end-start+1;
				MAXsum=current_sum;
			}
			else if(end-start+1>MAXlength)
			{
				MAXlength=end-start+1;
				MAXsum=current_sum;
			}
			end++;
		}
		printf("%lld %lld\n",MAXsum,MAXlength);
	}
}
