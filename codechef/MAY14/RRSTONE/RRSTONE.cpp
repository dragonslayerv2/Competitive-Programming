#include<iostream>
#include<vector>
#include<limits>
using namespace std;

int main()
{
	ios_base::sync_with_stdio(false);
	int n,k;
	cin>>n>>k;
	vector<long long> array(n);

	for(int i=0;i<n;i++)
		cin>>array[i];
		
	if(k==0)
		for(int i=0;i<n;i++)
			cout<<array[i]<<" ";
	else if(k%2==0)
	{
		long long MIN=numeric_limits<long long>::max();
		for(int i=0;i<array.size();i++)
			MIN=min(MIN,array[i]);
		for(int i=0;i<array.size();i++)
			cout<<array[i]-MIN<<" ";
	}	
	else
	{
		long long MAX=numeric_limits<long long>::min();
		for(int i=0;i<array.size();i++)
			MAX=max(MAX,array[i]);
		for(int i=0;i<array.size();i++)
			cout<<MAX-array[i]<<" ";
	}
}

