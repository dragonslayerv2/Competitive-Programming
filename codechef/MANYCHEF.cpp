#include<iostream>
#include<cstring>
using namespace std;
char S[3000];

inline bool isPossible(int i)
{
	if(S[i-3]!='C'&&S[i-3]!='?')
		return false;
	if(S[i-2]!='H'&&S[i-2]!='?')
		return false;
	if(S[i-1]!='E'&&S[i-1]!='?')
		return false;
	if(S[i]!='F'&&S[i]!='?')
		return false;
	return true;
}
int main()
{
	ios_base::sync_with_stdio(false);
	int t;
	cin>>t;
	while(t--)
	{
		cin>>S;
		int len=strlen(S);
		for(int i=len-1;i>=3;i--)
		{
			if(isPossible(i))
			{
				S[i-3]='C';
				S[i-2]='H';
				S[i-1]='E';
				S[i]='F';
			}
			else
				if(S[i]=='?') S[i]='A';
		}
		for(int i=0;i<3;i++)
			if(S[i]=='?')
				S[i]='A';
		cout<<S<<endl;	
	}
}
