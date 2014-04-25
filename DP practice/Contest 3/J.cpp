#include<iostream>
#include<vector>
#include<stdio.h>
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
//	freopen("testJ.txt","r",stdin);
	int t;
	cin>>t;
	
	while(t--)
	{
		vector<int> coins;
		int sum=0;
		while(1)
		{
			int a;
			cin>>a;
			coins.push_back(a);
			sum+=coins.back();
			if(getchar()==10)
				break;
		}
		
		vector<bool> DP		(sum+1);
		vector<bool> DPTemp	(sum+1);
		
		DP[0]		=true;
		
		for(int j=0;j<coins.size();j++)
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
		
		if(MIN==0)
			cout<<"YES";
		else
			cout<<"NO";
		cout<<endl;
	}
}
