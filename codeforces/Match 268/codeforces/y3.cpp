#include<stdio.h>
#include<algorithm>
using namespace std;

int main(){
	long long int n,sum=0,i,j,l,r,ar[300005],ans=0,tmp;
	scanf("%I64d",&n);
	for(i=0;i<n;i++)
	{
		scanf("%I64d",&ar[i]);
		sum+=ar[i];
	}
	ans+=sum;
	sort(ar,ar+n);
	
	for(i=0;i<n-1;i++)
	{
		ans+=ar[i]+sum-ar[i];
		sum=sum-ar[i];
	}
	printf("%I64d",ans);
}
