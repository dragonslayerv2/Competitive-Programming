#include<stdio.h>
#include<vector>
using namespace std;

int main()
{
	int n;
	long long m;
	scanf("%d %lld",&n,&m);
	
	vector<long long> A(n);
	for(int i=0;i<n;i++)
		scanf("%lld",&A[i]);
		
	int l=0,h=0;
	
	long long sum=0;
	long long currentSum=0;
	while(1)
	{
		if(h<n&&currentSum<=m)
		{
			currentSum+=A[h];
			h++;
		}
		else
		{
			currentSum-=A[l];
			l++;			
		}
			
		if(currentSum<=m)
			sum=max(sum,currentSum);
		if(h==n&&l==h)
			break;
	}
	printf("%lld",sum);
}
