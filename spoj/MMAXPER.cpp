#include<iostream>
#include<cmath>
#include<vector>
using namespace std;

int main()
{
//	freopen("testH.txt","r",stdin);
	int n;
	cin>>n;
	vector<vector<int> > sides(n,vector<int>(2));
	for(int i=0;i<n;i++)
		cin>>sides[i][0]>>sides[i][1];
	
	vector<vector<int> > DP(n+1,vector<int>(2));
	
	for(int i=n-1;i>=1;i--)
	{
		DP[i][0]=max(DP[i+1][0]+abs(sides[i-1][0]-sides[i][0])+sides[i][1],DP[i+1][1]+abs(sides[i-1][0]-sides[i][1])+sides[i][0]);
		DP[i][1]=max(DP[i+1][0]+abs(sides[i-1][1]-sides[i][0])+sides[i][1],DP[i+1][1]+abs(sides[i-1][1]-sides[i][1])+sides[i][0]);
	}
	cout<<max(DP[1][0]+sides[0][1],DP[1][1]+sides[0][0]);
}
