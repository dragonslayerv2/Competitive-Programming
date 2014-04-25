#include<iostream>
#include<cmath>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
	
		int b,ls;
		cin>>b>>ls;
		cout<<sqrt(ls*ls-b*b)<<" "<<sqrt(b*b+ls*ls)<<endl;
	}
}
