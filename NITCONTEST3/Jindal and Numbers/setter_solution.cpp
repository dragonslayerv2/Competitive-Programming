#include<iostream>
#include<vector>
using namespace std;


#define MAX 1000000
#define MOD 10000007
int main()
{
	vector<long long> ways(MAX+1);
	ways[1]=1;
	ways[2]=1;
	ways[3]=2;
	ways[4]=4;
	
	for(int i=5;i<ways.size();i++)
	{
		ways[i]=ways[i-1]+ways[i-3]+ways[i-4];
		ways[i]%=MOD;
	}	
		
	
	int T;
	cin>>T;
	while(T--)
	{
		int n;
		cin>>n;
		cout<<ways[n]<<endl;
	}
}
