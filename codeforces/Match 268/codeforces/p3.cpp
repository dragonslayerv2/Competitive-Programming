#include<iostream>
#include<queue>
#include<algorithm>
using namespace std;

int main(){
	int n;
	cin>>n;
	vector<long long> coins(n);
	for(int i=0;i<n;i++)
		cin>>coins[i];
	sort(coins.begin(),coins.end());
	
	long long sum = 0 ;
	for(int i=0;i<coins.size();i++)
		sum+=coins[i];
	
	long long ans = sum;
	for(int i=0;i<coins.size()-1;i++)
	{
		ans+=sum;
		sum-=coins[i];
	}
	cout<<ans;
}
