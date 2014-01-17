#include<iostream>
#include<list>
#include<cstdio>
using namespace std;

int main()
{
	list<char> pans[2];
	
	string initial;
	cin>>initial;
	
	int current=0;
	for(int i=0;i<initial.size();i++)
	{
		if(initial[i]=='|')
			current=1;
		else
			pans[current].push_back(initial[i]);
	}
	
	string newpans;
	cin>>newpans;
	for(int i=0;i<newpans.size();i++)
	{
		if(pans[0].size()>pans[1].size())
			pans[1].push_back(newpans[i]);
		else
			pans[0].push_back(newpans[i]);
	}
	if(pans[0].size()==pans[1].size())
	{
		for(list<char>::iterator i=pans[0].begin();i!=pans[0].end();i++)
			cout<<*i;
		cout<<"|";
		for(list<char>::iterator i=pans[1].begin();i!=pans[1].end();i++)
			cout<<*i;
	}
	else
		cout<<"Impossible";
}
