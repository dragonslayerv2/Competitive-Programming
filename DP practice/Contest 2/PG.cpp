#include<iostream>
#include<vector>
using namespace std;

int main()
{
	vector<int> DP(101);
	DP[1]=1;
	for(int i=2;i<=100;i++)
		DP[i]=i*i+DP[i-1];
	while(1)
	{
		int n;
		cin>>n;
		if(n==0)
			break;
		cout<<DP[n]<<endl;
	}
}
