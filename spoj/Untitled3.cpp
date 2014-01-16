#include<iostream>
using namespace std;

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		n--;
		
		int ans;
		char s[5];
		cin>>s;
		if(s[0]=='l')
			ans=1;
		else
			ans=0;
		
		while(n--)
		{
			cin>>s;
			if(s[0]=='l')
				ans^=1;
			else
				ans^=0;
		}
		
		if(ans==1)
			cout<<"lxh";
		else
			cout<<"hhb";
		cout<<endl;
	}
}
