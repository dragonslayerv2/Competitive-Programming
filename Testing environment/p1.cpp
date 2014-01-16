#include<iostream>
#include<map>
using namespace std;

int main()
{
	string a;
	cin>>a;
	map<string,bool> M;
	for(int i=0;i<a.size();i++)
		for(int j=i;j<a.size();j++)
			M.insert(make_pair(a.substr(i,j-i+1),true));
	int t;
	cin>>t;
	while(t--)
	{
		string b;
		cin>>b;
		cout<<(M.find(b)!=M.end())<<endl;
	}
}
