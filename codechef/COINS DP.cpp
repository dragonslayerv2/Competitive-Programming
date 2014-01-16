#include<iostream>
#include<map>
using namespace std;

map<int,long long> lookuptable; 

long long solve(long long n)
{
	if(n==0)
		return 0;
	else
		long long ans=0;
		if(lookuptable.find(n/2)==lookuptable.end())
			lookuptable[n/2]=solve(n/2);
		if(lookuptable.find(n/3)==lookuptable.end())
			lookuptable[n/3]=solve(n/3);
		if(lookuptable.find(n/4)==lookuptable.end())
			lookuptable[n/4]=solve(n/4);
		return max(lookuptable[n/2]+lookuptable[n/3]+lookuptable[n/4],n);
}

int main()
{
	int n;
	
	while(cin>>n)
	{
		cout<<solve(n)<<endl;
	}
}
