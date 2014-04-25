#include<iostream>
using namespace std;

int main()
{
	while(1)
	{	
		string s;
		cin>>s;
		if(s=="00e0")
			break;
			
		int n=s[0]-'0';
		n*=10;
		n+=s[1]-'0';
		for(int i=0;i<s[3]-'0';i++)
			n*=10;
		
		int a=1;
		int d=1;
		while(n!=1)
		{
			d*=2;
			if(n%2)
				a+=d;
			n/=2;
		}
		cout<<a<<endl;
	}
}

