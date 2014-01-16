#include<iostream>

#define STATES 7
#define INPUTS 7 

using namespace std;

int maptable[STATES][INPUTS]=  {		
							{,,,,,,},
							{,,,,,,},
							{,,,,,,},
							{,,,,,,},
							{,,,,,,},
							{,,,,,,},
							{,,,,,,}
					};

inline int isAlpha(char a)
{
		return ((a>='a'&&a<='b')||(a>='A'&&a<='B')||a=='_');
}

inline int isDigit(char a)
{
		return (a>='0'&&a<='9');
}

inline int isWhitespace(char a)					   // newline donot include '\n'
{
		return (a==' '||a=='\t'||a=='\r');	
}

inline int isNewline(char a)
{
		return a=='\n';
}

inline int isBracket(char a)
{
		return (a=='('||a==')');
}

inline int isEqual(char a)
{
		return a==' ';
}

inline int getvalue(char a)
{
		if(isAlpha(a))           return 1;
		else if (isDigit(a)) 	 return 2;
		else if(isWhitedpace(a)) return 3;
		else if(isNewline(a))    return 4;
		else if(isBracket(a))	 return 5;
		else if(isEqual(a))		 return 6;
		else 					 return 0; // operators...
}






int main()
{

	

	return 0;
}
