#include<iostream>
#include<vector>
using namespace std;

int main()
{
	freopen("testM.txt","r",stdin);
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	
	vector<int> DP(n,1);
	
	int ans=0;
	for(int i=n-1;i>=0;i--)
	{
		int MAX=0;
		for(int j=i+1;j<n;j++)
			if(a[i]<a[j])
				MAX=max(MAX,DP[j]);
		DP[i]+=MAX;
	}
	
	for(int i=0;i<n;i++)
		ans=max(ans,DP[i]);
	
	cout<<ans;
}
