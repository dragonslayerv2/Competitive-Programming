#include<iostream>
#include<algorithm>
#include<array>
using namespace std;


int main()
{
	array<int,5> x;
	
	for(int &i:x)
	{
		cin>>i;
	}
	sort(x.begin(),x.end());
	for(int &i:x)
	{
		cout<<i;
	}
}
