#include<iostream>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

#define isgreater(a,b) ((a.first>b.first)&&(a.second>b.second))

#define MAX 10010
pair<long long,long long> array[MAX];
int LIS[MAX];

int main()
{
	
	int t;
	cin>>t;
	
	for(int i=0;i<t;i++)
		cin>>array[i].first>>array[i].second;
	sort(array,array+t);
	
	
	LIS[0]=1;
	int max=1;
	
	for(int i=1;i<t;i++)
	{
		LIS[i]=0;
		for(int j=0;j<i;j++)
		{
			if(LIS[j]>LIS[i]&&(isgreater(array[i],array[j])))
				LIS[i]=LIS[j];
		}	
		LIS[i]++;
		if(LIS[i]>max)
			max=LIS[i];
	}	
/*	for(int i=0;i<t;i++)
		cout<<array[i].first<<" "<<array[i].second<<" "<<LIS[i]<<endl;*/
	cout<<max<<endl;
	return 0;
}
