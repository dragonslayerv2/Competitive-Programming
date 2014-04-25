#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int main()
{
//	freopen("testG.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	int n,m;
	while(cin>>n)
	{
		cin>>m;
		vector<vector<int> > grid(n,vector<int>(m)),DP(n,vector<int>(m));
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
			{
				cin>>grid[i][j];
				DP[i][j]=grid[i][j];
			}
				
		
		for(int j=m-2;j>=0;j--)
			for(int i=0;i<n;i++)
				DP[i][j]+=min(DP[(n+i-1)%n][j+1],min(DP[i][j+1],DP[(i+1)%n][j+1]));	

		int MIN=INT_MAX;
		int I=-1;
		for(int i=0;i<n;i++)
		{
			if(DP[i][0]<MIN)
			{
				MIN=DP[i][0];
				I=i;
			}
		}
		int i=I;
		for(int j=0;1;j++)
		{
			
			cout<<i+1;
		//	cout<<"AT "<<grid[i][j]<<endl;
			if(j==m-1)
				break;
			cout<<" ";
			int MIN2=min(DP[(n+i-1)%n][j+1],min(DP[i][j+1],DP[(i+1)%n][j+1]));	
			//cout<<"Next Min = "<<MIN2<<endl;
			int nextI=INT_MAX;
			
			if(MIN2==DP[(n+i-1)%n][j+1])
				nextI=min(nextI,(n+i-1)%n);
			if(MIN2==DP[i][j+1])
				nextI=min(nextI,i);
			if(MIN2==DP[(i+1)%n][j+1])
				nextI=min(nextI,(i+1)%n);
			i=nextI;
		}
		cout<<endl;
		cout<<MIN<<endl;
	}
}
