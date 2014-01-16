#include<iostream>
#include<vector>
#include<algorithm>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		
		vector<vector<int> > matrix(n,vector<int>(k+1));
		
		for(int i=0;i<n;i++) 	matrix[i][k]=i;
		
		for(int i=0;i<n;i++)
			for(int j=0;j<k;j++)
				cin>>matrix[i][j];
		
		vector<int> newvector(k);
		for(int i=0;i<k;i++)
			cin>>newvector[i];
			
		sort(matrix.begin(),matrix.end());
		
		vector<int> solutionarray=newvector;
		
		vector<int> ans;
		for(int i=0;i<n;i++)
		{
			bool flag=0;
			for(int j=0;j<k;j++)
				if(matrix[i][j]>solutionarray[j])
				{
					flag=true;
					break;
				}
			
			if(!flag)
			{
				for(int j=0;j<k;j++)
					solutionarray[j]-=matrix[i][j];
				ans.push_back(matrix[i][k]);
			}
		}
		
		cout<<ans.size()<<endl;
		sort(ans.begin(),ans.end());
		for(int i=0;i<ans.size();i++)
			cout<<ans[i]+1<<" ";
		cout<<endl;
	}
}
