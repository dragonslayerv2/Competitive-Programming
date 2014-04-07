#include<iostream>
#include<vector>
using namespace std;

#define MOD 10000007
int main()

{
	vector<int> DP(100001);
	DP[1]=1;
	DP[2]=2;
	DP[3]=3;
	DP[4]=2;
	DP[5]=1;
	for(int i=6;i<DP.size();i++)
	{
		DP[i]=1*DP[i-1]+2*DP[i-2]+3*DP[i-3]+2*DP[i-4]+1*DP[i-5];
		DP[i]%=MOD;
	}
	
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		cout<<DP[n]<<endl;
	}
	
}
