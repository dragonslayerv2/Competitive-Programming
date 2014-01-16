#include<iostream>
#include<cstdio>
#include<list>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		list<char> ans;
		long long n;
		cin >>n;
		if(n%2==0)
			cout<<0<<endl;
		else
		{
			while(n!=3&&n!=1)
			{
				int k=((n+1)/2)%2;
				if(k==1)
				{
					ans.push_front('1');
					n=(n+1)/2;
				}
				else
				{
					ans.push_front('2');
					n=(n-1)/2;
				}
			}
			if(n==3)
				ans.push_front('2');
			else
				ans.push_front('1');
			
			for(list<char>::const_iterator i=ans.begin();i!=ans.end();i++)
				cout<<*i;
			cout<<endl;
		}
	}
	return 0;
}
