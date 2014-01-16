#include<iostream>
#include<set>
using namespace std;


int main()
{
	int n;
	long long k;
	cin>>n>>k;
	set<long long> SET;
	for(int i=0;i<n;i++)
	{
		int a;
		cin>>a;
		SET.insert(a);
	}
	long long count=0;
	for(set<long long>::iterator i=SET.begin();i!=SET.end();i++)
	{
		if(SET.find(*i+k)!=SET.end())
			count++;
	}
	cout<<count;
	cout<<count;
}
