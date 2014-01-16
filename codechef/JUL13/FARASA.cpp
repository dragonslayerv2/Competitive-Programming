#include<iostream>
#include<map>
#include<vector>
#include<hash_map>
using namespace std;
using namespace __gnu_cxx;
int main()
{
	vector<long long> array;
	int n;
	cin>>n;
	array.reserve(n);
	for(int i=0;i<n;i++)
	{
		long long a;
		cin>>a;
		array.push_back(a);
	}
	
	
	hash_map<int,bool> sums;
	for(int i=0;i<n;i++)
	{
		long long sum=0;
		for(int j=i;j<n;j++)
		{
			sum+=array[j];
			sums[sum]=true;
		}
	
	}
	
	cout<<sums.size()-1;
}
