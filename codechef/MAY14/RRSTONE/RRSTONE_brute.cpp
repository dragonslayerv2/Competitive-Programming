#include<iostream>
#include<limits>
#include<vector>
using namespace std;

int main()
{
	int n,k;
	cin>>n>>k;
	vector<int> array(n);
	for(int i=0;i<n;i++)
		cin>>array[i];
	
	while(k--)
	{
		int MAX=numeric_limits<int>::min();
		for(int i=0;i<n;i++)
			MAX=max(MAX,array[i]);
		for(int i=0;i<n;i++)
			array[i]=MAX-array[i];
	}
	for(int i=0;i<n;i++)
		cout<<array[i]<<" ";
}
