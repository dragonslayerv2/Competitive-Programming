#include<iostream>
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
				long long N=n;     
				long long i=1;
      			while(N)
      			{
            		 N>>=1;
            		 i<<=1;       
      			}
      			i>>=1;
				int k=((n-(i+1))/2)%2;
				if(k==0)
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
			{
				cout<<*i;
			}
			cout<<endl;
		}
	}
	return 0;
}
