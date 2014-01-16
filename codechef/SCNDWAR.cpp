#include<iostream>
#include<map>
#include<string>
using namespace std;


long long solve(const string &s)
{
	map<int,int> value;
	
	value[s[0]]=1;
	
	int current=0;
	for(int i=1;i<s.size();i++)
	{
		if(value.find(s[i])==value.end())
		{
			value[s[i]]=current;
			current++;
			if(current==1)
				current=2;
		}
	}
	
	long long ans=0;
	int base=value.size();
	if(base==1)
		base=2;
	for(int i=0;i<s.size();i++)
	{
		ans=ans*base+value[s[i]];
	}
	return ans;
}


int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		string s;
		cin>>s;
		cout<<solve(s)<<endl;
	}

}
