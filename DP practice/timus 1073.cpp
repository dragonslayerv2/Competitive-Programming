#include<iostream>
#include<climits>
#include<vector>
using namespace std;


vector<int> hashmap(100000,-1);

int solve(int n)
{
	int MIN=INT_MAX;
	if(n==1)
		return 1;
	if(n==0)
		return 0;
	if(hashmap[n]==-1)
	{
		for(int i=1;i*i<=n;i++)
			MIN=min(MIN,1+solve(n-i*i));
		
		hashmap[n]=MIN;
	}
	return hashmap[n];
}

int main()
{
	int n;
	cin>>n;
	cout<<solve(n);
}
