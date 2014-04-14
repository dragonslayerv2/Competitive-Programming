#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string a,b;
		cin>>a>>b;
		vector<vector<int> > DP(a.size()+1,vector<int>(b.size()+1));
		
		for(int i=a.size();i>=0;i--)
			for(int j=b.size();j>=0;j--)
			{
				if(i==a.size())
					DP[i][j]=b.size()-j;
				else if(j==b.size())
					DP[i][j]=a.size()-i;
				
				else 
				{
					DP[i][j]=1+min(DP[i+1][j],min(DP[i][j+1],DP[i+1][j+1]));
					if(a[i]==b[j])
						DP[i][j]=min(DP[i][j],DP[i+1][j+1]);
				}
			}
			cout<<DP[0][0]<<endl;
	}
}
