#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		vector<int> height(n);
		for(int i=0;i<n;i++)
			cin>>height[n];

		vector<int> heightdif(n-1);
		
		for(int i=0;i<n-1;i++)
			heightdif[i]=height[i+1]-height[i];

	}
}
