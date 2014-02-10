#include<iostream>
#include<vector>
using namespace std;


int main()
{
	int n,q;
	scanf("%d %d",&n,&q);
	
	int sum=0;
	vector<int> array(n);
	for(int i=0;i<n;i++)
	{
		scanf("%d",&array[i]);
		sum+=array[i];
	}
	
	vector<long long> Sum(sum+1);
	
	Sum[0]=1;
	
	for(int i=0;i<array.size();i++)
	{
		for(int last=sum,first=sum-array[i];first>=0;first--,last--)
			Sum[last]|=Sum[first]<<1;
	}
	
	while(q--)
	{
		int s,k;
		scanf("%d %d",&s,&k);
		if(s<Sum.size()&&Sum[s]&(((long long)1)<<k))
			printf("YES");
		else
			printf("NO");
		printf("\n");
	}
	
}
