#include<iostream>
#include<vector>
using namespace std;

#define MAX 1000000
int main()
{
	vector<int> F(MAX);
	vector<int> S(MAX);
	vector<int> G(MAX);
	F[0]=1;
	
	for(int i=1;i<MAX;i++)
	{
		if(i>=2)
			G[i]=G[i-2]+F[i-2];
		
		if(i>=3)
			S[i]=F[i-2]+F[i-3]+S[i-2];
		else if(i>=2)
			S[i]=F[i-2]+S[i-2];
		
		if(i>=2)
			F[i]=F[i-1]+F[i-2]+2*S[i]+G[i];
		else
			F[i]=F[i-1]+2*S[i]+G[i];
	}
		
	
	
	int t;
	cin>>t;
	for(int T=1;T<=t;T++)
	{
		int n;
		cin>>n;
		cout<<T<<" "<<F[n]<<endl;
	}
}
