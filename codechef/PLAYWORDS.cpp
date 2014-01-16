#include<iostream>
#include<vector>
#include<list>
#include<map>
using namespace std;

typedef vector<list<int> > graph;

string YES="YES";
string NO="NO";


void dfs(graph &G,vector<bool> &isvisited,int source)
{
	if(isvisited[source])
		return;
	else
	{
		isvisited[source]=true;
		for(list<int>::iterator i=G[source].begin();i!=G[source].end();i++)
			dfs(G,isvisited,*i);
	}
}
bool check_single_connected(graph &G,int size)
{
	for(int i=0;i<26;i++)
	{
		vector<bool> isvisited(26);
		dfs(G,isvisited,i);
			
		int count=0;	
		for(int j=0;j<26;j++)
			if(isvisited[j])
				count++;
	//	cout<<count<<" "<<size<<endl;
		if(count==size)
			return true;
	}
	return false;
}
int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		graph G(26);
		int n;
		cin>>n;
		map<char,bool> distinct;
		while(n--)
		{
			string a;
			cin>>a;
			
			G[a[0]-'a'].push_back(a[a.size()-1]-'a');
			
			distinct[a[0]-'a']=true;
			distinct[a[a.size()-1]-'a']=true;
		
		}
		bool single_connected=check_single_connected(G,distinct.size());
		if(single_connected)
		{
			int odd=0;
			for(int i=0;i<26;i++)
				if(G[i].size()&1)
					odd++;
			if(odd<=2)
				cout<<YES;
			else 
				cout<<NO;
		}
		else
			cout<<NO;
		cout<<endl;
	}
}

