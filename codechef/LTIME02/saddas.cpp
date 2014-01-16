#include<iostream>
#include<algorithm>
#include<vector>
using namespace std;


long long decode(vector<int> &number)
{
	long long power=1;
	long long num=0;
	for(vector<int>::reverse_iterator i=number.rbegin();i!=number.rend();i++)
	{
		if(*i==1)
		{
			num+=power;
		}
		power<<=1;
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
			cout<<decode(number)<<endl;
		}
		else 
			cout<<1;
	}
}
