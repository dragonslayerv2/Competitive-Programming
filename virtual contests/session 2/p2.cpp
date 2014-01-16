#include<stdio.h>
#include<map>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,m;
		scanf("%d%d",&n,&m);
		
		vector<int> people(n);
		vector<int> prefix(n);
		map<int,int> prefix_station;
		long long P=0;

		for(int i=0;i<n;i++)
		{
			scanf("%d",&people[i]);
			P+=people[i];
			prefix[i]=P;
			prefix_station[P]=i;
		}
		
		long long count=0;
		long long sum=0;
		for(int i=0;i<people[i];i++)
		{
			long long to_find=prefix[i]+m;
			map<int,int>::iterator j=prefix_station.find(to_find);
			
			if(j==prefix_station.end())
			{
				prefix_station[to_find]=-1;
				j=prefix_station.find(to_find);
				j--;	
				prefix_station.erase(to_find);
			}
			if(j->second-i+1>count)
			{
				count=j->second-i+1;
				if(i-1<0)
					sum=j->first-0;
				else
					sum=j->first-prefix[i-1];
			}
		}
		
		
		printf("%lld %d\n",sum,count);
	}
}
