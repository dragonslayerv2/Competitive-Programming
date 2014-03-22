#include<stdio.h>
#include<algorithm>
#include<vector>
using namespace std;

#define MOD 1000000

vector<int> cumulative_frequency;

void countingSort(vector<long long> &A)
{
	cumulative_frequency.clear();
	cumulative_frequency.resize(MOD+5);

	for(int i=0;i<A.size();i++)
		cumulative_frequency[A[i]]++;
		
	int pos=0;
	
	for(int i=0;i<cumulative_frequency.size();i++)
		while(cumulative_frequency[i]--)
		{
			A[pos]=i;
			pos++;
		}
}
vector<long long> A;
int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long a,b,c,d,n;
		scanf("%lld%lld%lld%lld%lld",&n,&a,&b,&c,&d);
		
		A.resize(n);
		A[0]=d;

		for(int i=1;i<A.size();i++)
			A[i]=(a*A[i-1]*A[i-1]+b*A[i-1]+c)%MOD;
		
		countingSort(A);
		
		long long solution=0;
		for(int i=0;i<A.size();i++)
		{
			if((i&1)==0)
				solution+=A[i];
			else
				solution-=A[i];
		}
		
		if(solution<0)
			solution*=-1;
		printf("%lld\n",solution);
	}
}
