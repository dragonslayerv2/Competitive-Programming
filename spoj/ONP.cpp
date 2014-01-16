#include<iostream>
#include<stack>
#include<map>
using namespace std;

map<char,int> priority;


bool isoperator(char x)
{
	if(x=='+')	return	true;
	if(x=='-')	return	true;
	if(x=='*')	return	true;
	if(x=='/')	return	true;
	if(x=='^')	return	true;
	return false;
}
int main()
{
	priority['(']=0;
	priority['+']=1;
	priority['-']=2;
	priority['*']=3;
	priority['/']=4;
	priority['^']=5;
	
	int t;
	cin>>t;
	
	const int MAX=500;
	while(t--)
	{
		char a[MAX];
		cin>>a;
		stack<char> S;
		for(int i=0;a[i];i++)
		{
			if(a[i]=='(')
				S.push('(');
			else if(a[i]==')')
			{
				while(S.top()!='(')
				{
					cout<<S.top();
					S.pop();
				}
				S.pop();
			}
			else if(isoperator(a[i]))
			{
				while(!S.empty()&&priority[S.top()]>priority[a[i]])
				{
					cout<<S.top();
					S.pop();
				}
				
				S.push(a[i]);
			}
			else
				cout<<a[i];
		}
		while(!S.empty())
		{
			cout<<S.top();
			S.pop();
		}
		cout<<endl;
	}

}
