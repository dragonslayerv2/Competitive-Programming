#include<iostream>
#include<vector>
#include<map>
using namespace std;

map<pair<int,pair<int,int> >,int> DP;

#define make_state(n,x,y) make_pair(n,make_pair(x,y));
int solve(int x,int y,int n)
{
	if(n==0)
	{
		if(x==0&&y==0)
			return 1;
		else
			return 0;
	}
	
	pair<int,pair<int,int> > currentState=make_state(n,x,y);
	
	if(DP.find(currentState)==DP.end())
	{
		DP[currentState]+=solve(x+1,y+1,n-1);
		DP[currentState]+=solve(x+1,y-1,n-1);
		DP[currentState]+=solve(x-1,y+1,n-1);
		DP[currentState]+=solve(x-1,y-1,n-1);
		DP[currentState]+=solve(x+2,y,n-1);
		DP[currentState]+=solve(x-2,y,n-1);
	}
	return DP[currentState];
		
		 
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		DP.clear();
		cout<<solve(0,0,n)<<endl;
	}
}
