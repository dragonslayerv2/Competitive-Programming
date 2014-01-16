#include<iostream>
#include<map>
using namespace std;


int main()
{
	int n,k;
	cin>>n>>k;
	map<int,bool> tweet;
	int count=0;
	while(k--)
	{
		char command[100];
		int number;
		cin>>command;
		if(command[2]=='I')
		{
			cin>>number;
			if(tweet[number])
			{
				count--;
				tweet[number]=false;
			}
			else
			{
				count++;
				tweet[number]=true;
			}
		}
		else
		{
			count=0;
			tweet.clear();
		}
		cout<<count<<endl;
	}
}
