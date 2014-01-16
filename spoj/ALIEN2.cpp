#include<stdio.h>
#include<vector>
using namespace std;
int main()
{
	
		long long a,b;
		scanf("%lld %lld",&a,&b);
		
		vector<long long> array1(a);
		vector<long long> array2(a);
		for(int i=0;i<a;i++)
			scanf("%lld",&array1[i]);
		for(int i=0;i<a;i++)
			scanf("%lld",&array2[i]);
			
		vector<long long> array(a);
		for(int i=0;i<a;i++)
			array[i]=min(array1[i],array2[i]);
			
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
		printf("%lld %lld\n",MAXlength,MAXsum);
	
}

