#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<long long> a(n),b(n);
	for(int i=0;i<n;i++)
		cin>>a[i];
	
	for(int i=0;i<n;i++)
		cin>>b[i];

	long long score=0;	
	for(int i=0;i<n;i++)
	{
		long long first=b[i]/2;
		long long second=b[i]-first;
		if(first>=1&&second>=1&&first<=a[i]&&second<=a[i])
			score+=first*second;		
		else
			score--;
	}
	cout<<score;
}
