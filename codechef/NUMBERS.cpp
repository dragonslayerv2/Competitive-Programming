#include<iostream>
#include<map>
using namespace std;


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		map<long long,pair<int,string> > hash;
		while(n--)
		{
			char name[10];
			long long number;
			cin>>name>>number;
			map<long long,pair<int,string> >::iterator i=hash.find(number);
			if(i==hash.end())
			{
				hash[number]=make_pair(0,name);
			}
			else
			{
			(	(i->second).first)++;	
			}
		}
		map<long long,pair<int,string> >::iterator i=hash.begin();
		while(i!=hash.end())
		{
			if((i->second).first==0)
				break;
			i++;
		}
		if(i==hash.end())
			cout<<"Nobody wins."<<endl;
		else
			cout<<i->second.second<<endl;
		
	}
}
