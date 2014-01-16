#include<iostream>
#include<cctype>
#include<list>
#include<map>
using namespace std;



int main()
{
	//--------------------------------
	map<char,int> precedence;
	
	precedence['+']=1;	
	precedence['-']=2;
	precedence['*']=3;
	precedence['/']=4;
	precedence['^']=5;
	//---------------------------------

	int t;
	cin>>t;
	while(t--)
	{
		list<char> stack;	
		string str;
		cin>>str;
		
		for(int i=0;i<str.size();i++)
		{
			/*for(list<char>::iterator i=stack.begin();i!=stack.end();i++)
			{
				cout<<*i;
			}*/
			
			if(isalpha(str[i]))
			{
				cout<<str[i];
			}
			
			else if(str[i]=='(')
				stack.push_back(str[i]);
			else if(str[i]==')')
			{
				char ch;
				while(1)
				{
					ch=stack.back();
					stack.pop_back();
					if(ch=='(') break;					
					cout<<ch;
				}
			}
			
			else
			{
				char ch;
				
				while(stack.size())
					{
						ch=stack.back();
						stack.pop_back();
						if(precedence[ch]<precedence[str[i]]||ch=='(')
						{
							stack.push_back(ch);
							break;
						}
						
						cout<<ch;
					}
				stack.push_back(str[i]);		
			}
				
		}	
	
		while(stack.size())
		{
			cout<<stack.back();
			stack.pop_back();	
		}
			cout<<endl;
	}
	return 0;
}


