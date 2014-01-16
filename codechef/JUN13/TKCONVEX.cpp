#include<iostream>
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
	bool ans[2000]={false};
	
	for(int i=0;i<=n-k;i++)
	{
		long long sum=0;
		for(int j=i;j<i+(k-1);j++)
			sum=sum+a[j].first;		
		
		if(sum>a[i+k-1].first)
			ans[i]=true;
	}
	
	bool ispossible=false;
	
	int firstpos=-1;
	int secondpos=-1;
	
	for(int i=0;i+2*k-1<n;i++)
	{
		//cout<<endl<<"for "<<i;//cin.get();
		if(ans[i])
		{
		//	cout<<i<<endl;
			
			for(int j=i+k;j<n;j++)
			{
				//cout<<"checking for "<<j<<"got "<<ans[j]<<endl;		
				if(ans[j]==true)
				{
					ispossible=true;
					firstpos=i;
					secondpos=j;
					break;
				}
			}
		}
		if(ispossible) break;
	}
	
	
	
	if(!ispossible)
		cout<<"No";
	else
	{
		cout<<"Yes"<<endl;
		for(int i=firstpos;i<firstpos+k;i++)
			cout<<a[i].second<<" ";
			
		for(int i=secondpos;i<secondpos+k;i++)
			cout<<a[i].second<<" ";	
	}
}
