#include<iostream>
#include<vector>
using namespace std;

void printArray(vector<vector<int> > array)
{
	for(int i=0;i<array.size();i++)
	{
		for(int j=0;j<array[i].size();j++)
			cout<<array[i][j]<<" ";
		cout<<endl;
	}
	cout<<endl;
}

int main()
{
//	freopen("testMartian.txt","r",stdin);
	ios_base::sync_with_stdio(false);
	while(1)
	{
		int n,m;
		cin>>n>>m;
		if(!n&&!m)	break;
		
		vector<vector<int> > a(n,vector<int>(m)),b(n,vector<int>(m));
		
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin>>b[i][j];
		
		for(int i=0;i<n;i++)
			for(int j=0;j<m;j++)
				cin>>a[i][j];
		
		vector<vector<int> > prefixB(n,vector<int>(m+1)),suffixA(n,vector<int>(m+1));
		
		for(int i=0;i<n;i++)
		{
			for(int j=1;j<=m;j++)
				prefixB[i][j]=b[i][j-1]+prefixB[i][j-1];
			
			for(int j=m-1;j>=0;j--)
				suffixA[i][j]=a[i][j]+suffixA[i][j+1];
		}
		
	//	printArray(suffixA);
	//	printArray(prefixB);
			
		vector<vector<int> > DP(n+1,vector<int>(m+1));
		
		for(int i=n-1;i>=0;i--)
			for(int j=m;j>=0;j--)
			{
					int current=DP[i+1][j]+suffixA[i][j]+prefixB[i][j];
					DP[i][j]=max(DP[i][j+1],current);
			}
				
				
		
	//	printArray(DP);
		cout<<DP[0][0]<<endl;
	}
}
