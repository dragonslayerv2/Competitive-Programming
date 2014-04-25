#include<iostream>
#include<vector>
#include<climits>
using namespace std;

int abs(int x)
{
	if(x<0)
		return -1*x;
	else
		return x;
}

int main()
{
//	freopen("testE.txt","r",stdin);
	int t;
	cin>>t;
	
	while(t--)
	{
		int n;
		cin>>n;
		
		vector<int> coins(n);
		int sum=0;
		for(int i=0;i<n;i++)
		{
			
			cin>>coins[i];
			sum+=coins[i];
		}
		
		vector<bool> DP		(sum+1);
		vector<bool> DPTemp	(sum+1);
		
		DP[0]		=true;
		
		for(int j=0;j<n;j++)
		{
			for(int i=0;i<=sum;i++)
			{
				if(DP[i])
					DPTemp[i+coins[j]]=true;	
			}
			for(int i=0;i<=sum;i++)
				DP[i]=DP[i]||DPTemp[i];
		}
		
		int MIN=INT_MAX;
		for(int i=0;i<=sum;i++)
			if(DP[i])
				MIN=min(MIN,abs(sum-2*i));	
		
		cout<<MIN<<endl;
	}
}
