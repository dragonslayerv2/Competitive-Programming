#include<iostream>
#include<map>
#include<vector>
#include<algorithm>
#include<ctype.h>
using namespace std;

#define MAX 150001
int main()
{
	int t;
	cin>>t;
	cin.get();
	while(t--)
	{
		char frequency[27];
		cin>>frequency;
		cin.get();
		char string[MAX];
		cin.getline(string,MAX);
		
		map<char,int> string_frequency;
		for(int i=0;string[i];i++)
			if(isalpha(string[i]))
				string_frequency[tolower(string[i])]++;
		
		vector<pair<int,char> > ordered;
		
		for(auto i=string_frequency.begin();i!=string_frequency.end();i++)
			ordered.push_back(make_pair(i->second,i->first));
		
		sort(ordered.rbegin(),ordered.rend());
		
		map<char,char> matchings;
		
		int k=25;
		for(int i=0;i<ordered.size();i++)
			matchings[ordered[i].second]=frequency[k--];
			
		for(int i=0;string[i];i++)
		{
			if(isalpha(string[i]))
			{
				if(islower(string[i]))
					cout<<matchings[string[i]];
				else
					cout<<(char)toupper(matchings[tolower(string[i])]);
			}
			else
				cout<<string[i];
		}
		cout<<endl;
	}
}
