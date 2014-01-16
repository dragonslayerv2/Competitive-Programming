#include<iostream>
#include<list>
#include<vector>
#include<map>
#include<algorithm>
using namespace std;

pair<long long,int> a[2000];

int main()
{
	int n,k;
	cin>>n>>k;
	for(int i=0;i<n;i++)
	{
		cin>>a[i].first;
		a[i].second=i+1;
	}
	
	sort(a,a+n);
	
	bool is1possible=false;
	bool is2possible=false;	
	
	for(int i=k-1;i<n-1;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			list<pair<long long,int> > dq1;
			list<pair<long long,int> > dq2;	
			long long sumdq1=0;
			long long sumdq2=0;
			
			is1possible=false;
			is2possible=false;
			
			pair<long long,int> maxedge1=a[i];
			pair<long long,int> maxedge2=a[j];
			pair<long long,int> dump;
			
			
			for(int x=0;x<j;x++)
			{
				if(x!=i&&x!=j)
				{
					if(sumdq1<=sumdq2&&dq1.length()<k-1&&)
					{
						dq1.push_back(a[i]);
					}
				}
			}
			
			
			
			
			
			
		}
	}
	
	
	
	
	maxedge1=a[k-1];
	maxedge2=a[2k-1];
	
	
	
	
	
	
	
	
}
