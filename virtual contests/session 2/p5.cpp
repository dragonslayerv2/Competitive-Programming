#include<iostream>
#include<vector>
#include<algorithm>
#include<climits>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		vector<int> height(n);
		for(int i=0;i<n;i++)
			cin>>height[i];
		sort(height.begin(),height.end());
		int MIN=INT_MAX;
		for(int i=0;i<n-(k-1);i++)
			MIN=min(MIN,height[i+k-1]-height[i]);
		cout<<MIN<<endl;
		
	}
}
