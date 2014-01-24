#include<iostream>
#include<vector>
#include<limits>
using namespace std;

int main()
{
	int n,c;
	cin>>n>>c;
	vector<int> a(n);
	for(int i=0;i<n;i++)
		cin>>a[i];	
	
	int MAX=numeric_limits<int>::min();
	for(int i=0;i<n-1;i++)
		MAX=max(MAX,a[i]-a[i+1]);
	
	MAX-=c;
	
	if(MAX<0)
		cout<<0;
	else
		cout<<MAX;
}
