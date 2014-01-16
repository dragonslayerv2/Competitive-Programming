
#include<iostream>
#include<map>
#include<stack>
using namespace std;

bool isoperator(char a)
{
	return (a=='+'||a=='-'||a=='*'||a=='/');
}
map<char,int> getprecedence()
{
	map<char,int> precedence;
	precedence['(']=-1;
	precedence['+']=0;
	precedence['-']=0;
	precedence['*']=1;
	precedence['/']=1;
	return precedence;
}
string postfix(const string &a)
{
	map<char,int> precedence=getprecedence();
	string output;
	stack<char> S;
	for(int i=0;i<a.size();i++)
	{
		if(a[i]=='(')
			S.push(a[i]);
		else if(a[i]==')')
		{
			while(S.top()!='(')
			{
				output+=S.top();
				S.pop();
			}
			S.pop();
		}
		else if(isoperator(a[i]))
		{
		 	while(!S.empty()&&precedence[S.top()]>precedence[a[i]])
		 	{
				 output+=S.top();
				 S.pop();
			}
			S.push(a[i]);
		}
		else  // its an operand
		{
			output+=a[i];
		}
	}
	while(!S.empty())
	{
		output+=S.top();
		S.pop();
	}
	return output;
}
int main()
{
	string a;
	cin>>a;
	cout<<postfix(a);
}
