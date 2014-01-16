#include<iostream>
#include<limits>
#include<vector>
using namespace std;


int main()
{
	int n;
	cin>>n;
	vector<int> characters(26,numeric_limits<int>::max());
	for(int i=0;i<n;i++)
	{
		vector<int> current(26);
		string a;
		cin>>a;
		for(int i=0;i<a.size();i++)
			current[a[i]-'a']++;
		for(int i=0;i<characters.size();i++)
			characters[i]=min(characters[i],current[i]);
	}
	bool printed=false;
	for(int i=0;i<characters.size();i++)
		for(int j=0;j<characters[i];j++)
		{
			printed=true;
			cout<<(char)(i+'a');
		}
		
	if(!printed)
		cout<<"no such string";
	cout<<endl;
}
