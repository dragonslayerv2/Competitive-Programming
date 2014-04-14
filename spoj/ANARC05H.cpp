#include<stdio.h>
#include<iostream>
#include<vector>
using namespace std;

int main()
{
	int t=0;
	while(1)
	{
		t++;
		string s;
		cin>>s;
		
		if(s=="bye")
			return 0;
	
		vector<vector<int> > DP(s.size()+1,vector<int>(s.size()*9+1));
		
		for(int i=0;i<DP[s.size()].size();i++)
			DP[s.size()][i]=1;
		
		for(int i=s.size()-1;i>=0;i--)
		{
			for(int j=0;j<DP[i].size();j++)
			{
				int add=0;
				for(int k=i;k<s.size();k++)
				{
					add+=s[k]-'0';
					if(add>=j)
						DP[i][j]+=DP[k+1][add];
				}
			}
		}
		printf("%d. %d\n",t,DP[0][0]);
	}
}
