#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
using namespace std;


int main()
{
	int t;
	cin>>t;
	
	
	while(t--)
	{
		int n,k;
		vector<int> a;
		cin>>n>>k;
		int sum=0;
		for(int i=0;i<n;i++)
		{
			int x;
			cin>>x;
			a.push_back(x);
			sum+=a[i];
		}
		sort(a.begin(),a.end());
		if(n-k<k)
			k=n-k;
		for(int i=0;i<k;i++)
		{
			sum=sum-2*a[i];
		}
		cout<<abs(sum)<<endl;
	}
	return 0;
}
