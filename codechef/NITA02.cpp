#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;


int main()
{
	int n,m;
	cin>>n>>m;
	vector<vector<int> > table(n,vector<int>(m));
	
	bool flag=true;
	
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<m;j++)
		{
			cin>>table[i][j];
		}
	}
	
	
	
	for(int i=0;i<n;i++)
	{
		int ele=table[i][0];
		if(i&&ele==table[i-1][0])
			{
				flag=false;
				break;
			}
				
		for(int j=0;j<m;j++)
		{
			if(table[i][j]!=ele)
			{
				flag=false;
				break;
			}
		}
		if(!flag)
			break;
	}
	if(flag)
		cout<<"YES"<<endl;
	else
		cout<<"NO"<<endl;
	

}

