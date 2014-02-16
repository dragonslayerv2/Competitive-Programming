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
		cin>>n;
		vector<long long > array(n);
		for(int i=0;i<n;i++)
			cin>>array[i];
		sort(array.begin(),array.end());
		long long result=0;
		for(int i=1;i<n;i++)
			result+=array[0]*array[i];
		cout<<result<<endl;
		
	}
}
