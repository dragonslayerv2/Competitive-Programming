#include<iostream>
#include<vector>
using namespace std;

int DP[2][101][101];

int solve(int i,int n,int k,int last=0)
{
	if(i==0)
		return solve(i+1,n,k,0)+solve(i+1,n,k,1);
	
	if(i==n)
	{
		if(k==0)
			return 1;
		else
			return 0;
	}
	else return solve(i+1,n,k-last,1)+solve(i+1,n,k,0);
}
int main()
{
	freopen("testB.txt","r",stdin);
	int T;
	cin>>T;
	while(T--)
	{
		int t;
		cin>>t;
		cout<<t<<" ";
		
		int n,k;
		cin>>n>>k;
		cout<<solve(0,n,k)<<endl;
	}
}
