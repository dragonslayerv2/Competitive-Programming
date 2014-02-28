#include<iostream>
using namespace std;


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		int corrections=0;
		int count=0;
		for(int i=0;i<s.size();i++)
		{
			if(s[i]=='x')
				count+=1;
			else 
				count-=1;
			if(count<=0)
			{
				corrections++;
				count+=2;
			}
		}
		if(count>1)
		{
			while(count-1>=1)
			{
				count-=2;
				corrections++;
			}
		}
		cout<<corrections<<endl;
	}
}
