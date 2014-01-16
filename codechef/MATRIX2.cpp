#include<iostream>
#include<vector>
using namespace std;


int main()
{
	int n,m;
	cin>>n>>m;
	vector<vector<char> > matrix(n,vector<char>(m));
	for(int i=0;i<n;i++)
		for(int j=0;j<m;j++)
			cin>>matrix[i][j];
	
	vector<vector<int> > horizontal(n+1,vector<int>(m+1));
	vector<vector<int> > ans(n+1,vector<int>(m+1));
	for(int i=0;i<n;i++)
	{
		for(int j=m-1;j>=0;j--)
		{
			if(matrix[i][j]=='0')
				horizontal[i][j]=0;
			else
				horizontal[i][j]=1+horizontal[i][j+1];
		}
	}
	
	
	for(int i=n-1;i>=0;i--)
	{
		for(int j=0;j<m;j++)
		{
			if(matrix[i][j]=='0')
				ans[i][j]=0;
			else
				ans[i][j]=min(horizontal[i][j],ans[i+1][j+1]+1);
		}
	}
	
	long long result=0;
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			result+=ans[i][j];
	}
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
			cout<<ans[i][j];
		cout<<endl;
	}
	cout<<result<<endl;
}
