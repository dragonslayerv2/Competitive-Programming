#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int n;
	cin>>n;
	vector<int> V(n);
	
	for(int i=0;i<n;i++)
		cin>>V[i];
		
	vector<vector<int> > DP(n,vector<int>(n));
	for(int i=n-1;i>=0;i--)
		for(int j=i;j<n;j++)
		{
			if(i==j)
				DP[i][j]=V[i]*(V.size()-(j-i));	
			else
				DP[i][j]=max(V[i]*(V.size()-(j-i))+DP[i+1][j],V[j]*(V.size()-(j-i))+DP[i][j-1]);	
		}
	cout<<DP[0][n-1];
}
