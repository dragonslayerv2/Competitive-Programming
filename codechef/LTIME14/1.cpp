#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
		
		int maximum =0;
	for(int i=0;i<n;i++)
		for(int j=i+1;j<n;j++)
			maximum=max(a[i]&a[j],maximum);
	cout<<maximum;
}
