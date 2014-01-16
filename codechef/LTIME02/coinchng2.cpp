#include<iostream>
#include<algorithm>
#include<list>
#include<vector>

using namespace std;


long long decode(vector<int> &number,int base)
{
	long long num=0;
	long long power=1;
	for(vector<int>::reverse_iterator i=number.rbegin();i!=number.rend();i++)
	{
		if(*i>0)
		{
			num+=power*(*i);
		}
		power*=base;
	}
	return num;
}

long long decode(list<int> &number,int base)
{

	long long num=0;
	long long power=1;
	for(list<int>::reverse_iterator i=number.rbegin();i!=number.rend();i++)
	{
		if(*i>0)
		{
			num+=power*(*i);
		}
		power*=base;
	}
	return num;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int c,s,k;
		cin>>c>>s>>k;
		
		if(c==2)
		{
			vector<int> number;
			number.reserve(100);
				
			for(int i=s;i<100;i++)
			{
				number.push_back(0);
			}
			for(int i=0;i<s;i++)
			{
				number.push_back(1);
			}
			for(int i=0;i<k-1;i++)
			{
				next_permutation(number.begin(),number.end());
			}
			cout<<decode(number,2)<<endl;
		}
		else if(k==1)
		{
			list<int> number;
			while(s>=c-1)
			{
				number.push_front(c-1);
				s=s-(c-1);
			}
			if(s>0)
				number.push_front(s);
			cout<<decode(number,c)<<endl;
		}
		else 
			cout<<1<<endl;
	}
}
