#include<iostream>
#include<map>
using namespace std;

map<int,long long> hash;
long long solve(long long n)
{
	if(n==0)
		return 0;
	if(hash.find(n)==hash.end())
		hash[n]=max(n,solve(n/2)+solve(n/3)+solve(n/4));
	return hash[n];
}
int main()
{
	int n;
	while(cin>>n)
	{
		hash.clear();
		cout<<solve(n)<<endl;
	}
}
