#include<iostream>
#include<vector>
using namespace std;

map<pair<int,pair<int,int> >,int> DP;
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		cout<<solve(0,0,n)<<endl;
	}
}
