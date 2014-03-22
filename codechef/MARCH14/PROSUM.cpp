#include<stdio.h>
#include<vector>
using namespace std;


int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		vector<int> a;
		a.resize(n);
		for(int i=0;i<n;i++)
		{
			scanf("%d",&a[i]);
		}
		int greater2=0;
		int equal2=0;
			long long solution=0;
			
		for(int i=0;i<a.size();i++)
		{
			if(a[i]==2)
				equal2++;
			if(a[i]>2)
				greater2++;
		}
		
		for(int i=0;i<a.size();i++)
		{
			if(a[i]==2)
				equal2--;
			if(a[i]>2)
				greater2--;
			
			if(a[i]>2)
				solution+=equal2;
				
			if(a[i]>=2)
				solution+=greater2;
			
			
		}
		printf("%lld\n",solution);
	}
}
