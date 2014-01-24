#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

long long abs(long long a)
{
	if(a<0)
		return -1*a;
	else
		return a;
}
int main()
{
	int n;
	cin>>n;
	vector<int> array(n);
	for(int i=0;i<n;i++)
		cin>>array[i];
	sort(array.begin(),array.end());
	long long sum=0;
	for(int i=0;i<n;i++)
	{
		sum+=abs(array[i]-(i+1));
	}
	cout<<sum;
}
