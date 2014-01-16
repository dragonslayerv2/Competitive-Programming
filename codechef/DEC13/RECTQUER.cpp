#include<iostream>
#include<vector>
using namespace std;


int main()
{
	int n;
	cin>>n;
	vector<vector<int> > matrix(n+1,vector<int>(n+1));
	for(int i=1;i<=n;i++)
		for(int j=1;j<=n;j++)
			cin>>matrix[i][j];
		
	vector<vector<vector<int> > > counts(11,vector<vector<int> >(n+1,vector<int>(n+1)));
	for(int k=1;k<=10;k++)
	{
		counts[k][1][1]=(matrix[1][1]==k);
		for(int j=2;j<=n;j++)
			counts[k][1][j]=(matrix[1][j]==k)+counts[k][1][j-1];
		for(int i=2;i<=n;i++)
			counts[k][i][1]=(matrix[i][1]==k)+counts[k][i-1][1];
		
		for(int i=2;i<=n;i++)
			for(int j=2;j<=n;j++)
				counts[k][i][j]=(matrix[i][j]==k)+counts[k][i][j-1]+counts[k][i-1][j]-counts[k][i-1][j-1];
	}
	
	int q;
	cin>>q;
	while(q--)
	{
		int i1,j1,i2,j2;
		cin>>i1>>j1>>i2>>j2;
		int distinct = 0;
		for(int k=1;k<=10;k++)
	
			distinct+=((counts[k][i2][j2]-counts[k][i1-1][j2]-counts[k][i2][j1-1]+counts[k][i1 - 1][j1 - 1])>0);
	
		cout<<distinct<<endl;	
	}
	
	
	
}
