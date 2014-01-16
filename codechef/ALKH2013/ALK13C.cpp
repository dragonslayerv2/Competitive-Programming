#include<iostream>
#include<map>
using namespace std;
#include<stdio.h>
#ifdef ONLINE_JUDGE
	#define GETCHAR getchar_unlocked	
	#define PUTCHAR putchar_unlocked
#endif
#ifndef ONLINE_JUDGE
	#define GETCHAR getchar
	#define PUTCHAR putchar
#endif
	
inline int readlong() 
{
	int flag=1;
    long long n = 0;
    char c;
    int sign=1;
    while (1)
    { 
    			
              c=GETCHAR();
              if(c=='-')
              	sign=-1;
              else if(c>='0'&&c<='9') {n = n * 10 + c - '0';flag=0;}
              else if(flag!=1) break; 
                              
    }
    return sign*n;
}
int main()
{
	int t=readlong();
	
	while(t--)
	{
	map<int,bool> row,column;
		int n=readlong();
		while(n--)
		{
			int a,b;
			a=readlong();
			b=readlong();
			row[a]=true;
			column[b]=true;
		}
		long long distinctrows=row.size();
		long long distinctcolumn=column.size();
		cout<<(distinctrows+1)*(distinctcolumn+1)<<endl;
	}

}
