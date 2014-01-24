#include<iostream>
using namespace std;
#define MOD 1000000007
long long arr[]={1,0,3,0,15,0,133,0,2025,0,37851,0,1030367,0,36362925,0,1606008513LL};

int main()
{
	int n;
	cin>>n;
	
	long long solution=arr[n-1];
	for(int i=1;i<=n;i++)
	{
		solution=(i*solution)%MOD;
	}
	cout<<solution;
}
