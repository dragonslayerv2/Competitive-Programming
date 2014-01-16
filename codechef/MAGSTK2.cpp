#include<iostream>
#include<vector>
using namespace std;



int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		vector<int> sticks;
		int n;
		cin>>n;
		sticks.resize(n);
		vector<bool> isstick(500);
		vector<int> height(500);
		for(int i=0;i<n;i++)
		{
			cin>>sticks[i];
			sticks[i]+=200;
			isstick[sticks[i]]=true;
			cin>>height[sticks[i]];
		}
		
		vector<int> ans(500);
		for(int i=ans.size()-2;i>=0;i--)
		{
			if(isstick[i])
			{
				bool flag=false;
				int other=0;
				for(int j=i+1;j<=i+height[i]-1&&j<500;j++)
				{
					if(isstick[j])
					{	
						
						ans[i]=max(ans[i],other+ans[j]);
						other++;
					}
				}
				ans[i]++;
			}
		
		}
		
		for(int i=0;i<n;i++)
		{
			cout<<ans[sticks[i]]<<" ";
		}
	}
}
