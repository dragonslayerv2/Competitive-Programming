/*
	Name: Connected Components in Graph(Using Disjoint Set Data Structure)
	Copyright: 
	Author: Shobhit Saxena
	Date: 05/03/13 21:36
	Description: Disjoint Set data Structure. With path compression algorithm and effective parent matching in union.
*/

#include<iostream>
#include<cstdio>
using namespace std;

#define MAX 100001
#define MOD 1000000007

#define GETCHAR getchar_unlocked
#define PUTCHAR putchar_unlocked

inline int readInt() 
{
    int n = 0;
    char c;
    while (1)
    { 
              c=GETCHAR();
              if(c=='\n'||c==' ') break;
                              n = n * 10 + c - '0';
    }
    return n;
}
 

inline void writeInt(int x) 
{
     int i = 10;
     char buf[11];
     // buf[10] = 0;
     buf[10] = '\0';

     do 
     {
        buf[--i] = x % 10 + '0';
        x/= 10;
     }while(x);
     while(buf[i])
     {
        	PUTCHAR(buf[i]);
		i++;
     }
}





struct no
{
	int parent;
	int children;
};

typedef struct no node;

inline void makeset(node *a,int n)
{
	int i;
	for(i=1;i<=n;i++)
	{
		a[i].parent=i;
		a[i].children=1;
	}
}

inline node *root(node *a,int i)
{
	while(1)
	{	
	if(a[i].parent==i)
		return &a[i];
	else i=a[i].parent;	
	}
}

inline bool Union(node *a,int i,int j)
{
	node *iroot=root(a,i);
	node *jroot=root(a,j);
	
	if(iroot->parent==jroot->parent)
		return false;
	else if(iroot->children<jroot->children)
	{
		iroot->parent=jroot->parent;
		jroot->children+=iroot->children;
	}
	else
	{
		jroot->parent=iroot->parent;
		iroot->children+=jroot->children;
	}
	return true;
}


int main()
{	
	node vertices[MAX];
	int t=readInt();
	int n,m;
	int a,b;
	long long ways;
		int i;
	while(t--)
	{
		ways=1;
		
		n=readInt();
		m=readInt();
		makeset(vertices,n);
		int disconnected=n;
		for( i=0;i<m;i++)
		{
			a=readInt();
			b=readInt();	
			if(Union(vertices,a,b)) disconnected--;
		}
		for(i=1;i<=n;i++)
		{
			if(vertices[i].parent==i&&vertices[i].children!=1)
				ways=(ways*vertices[i].children);
			if(ways>MOD)
				ways=ways%MOD;
		}
		
		writeInt(disconnected);
		putchar_unlocked(' ');
		writeInt(ways);
		putchar_unlocked('\n');
	}
	return 0;
}
