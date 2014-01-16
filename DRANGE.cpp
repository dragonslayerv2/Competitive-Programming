#include<iostream>
#include<stdio.h>
#include<limits>
#include<vector>
using namespace std;
#define GETCHAR getchar_unlocked
#define PUTCHAR putchar_unlocked



int main()
{
	int t;
	cin>>t;
	while(t--)			
	{
		int n,m;
		cin>>n>>m;
		vector<int> counter(n+2,0);
		
		for(int i=0;i<m;i++)
		{
			int w,x,y,z;
			cin>>w>>x>>y>>z;
			
			if(w==1)
			{
				counter[x]+=z;
				counter[y+1]-=z;
			}
			else
			{
				counter[x]-=z;
				counter[y+1]+=z;
			}
		}	
		
		// process
		
		int MAX=numeric_limits<int>::min();
		int MIN=numeric_limits<int>::max();
		
		int adder=0;
		for(int i=1;i<=n;i++)
		{
			adder+=counter[i];
			
			MIN=min(MIN,i+adder);
			MAX=max(MAX,i+adder);
		}
		cout<<MAX-MIN<<endl;
	}
}
