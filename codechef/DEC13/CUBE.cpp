#include<iostream>
#include<cmath>
#include<vector>
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
    while (1)
    { 
              c=GETCHAR();
              if(c>='0'&&c<='9') {n = n * 10 + c - '0';flag=0;}
              else if(flag!=1) break; 
                              
    }
    return n;
}
 

inline void writeInt(int x) 
{
     int i = 10;
     char buf[11];
     // buf[10] = 0;
     buf[10] = '\n';

     do 
     {
        buf[--i] = x % 10 + '0';
        x/= 10;
     }while(x);
     do 
     {
        PUTCHAR(buf[i]);
     } while (buf[i++] != '\n');
}


int main()
{
	int t;
	t=readlong();
	while(t--)		
	{
		int n,P;
		n=readlong();
		P=readlong();
		
		char cube1[41][41][41];
		char cube2[41][41][41];
		
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				for(int k=1;k<=n;k++)
					cube1[i][j][k]=GETCHAR();
		GETCHAR();
					
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				for(int k=1;k<=n;k++)
					cube2[i][j][k]=GETCHAR();
		GETCHAR();
	
		bool match[41][41][41]={false};
		
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				for(int k=1;k<=n;k++)
					match[i][j][k]=(cube1[i][j][k]==cube2[i][j][k]);
		
		
		
		int R[41][41][41]={0};
		
		for(int i=1;i<=n;i++)
			for(int j=1;j<=n;j++)
				for(int k=1;k<=n;k++)
					R[i][j][k]=R[i-1][j][k]+R[i][j-1][k]+R[i][j][k-1]-(R[i-1][j-1][k]+R[i][j-1][k-1]+R[i-1][j][k-1])+R[i-1][j-1][k-1]+match[i][j][k];
		
		
		int S[41][41][41]={0};
		long long count;
		int size;
		for(size=n;size>=1;size--)
		{
			count=0;
			long long minimum=ceil(((double)((size*size*size)*P))/100);
			for(int i=size;i<=n;i++)
				for(int j=size;j<=n;j++)
					for(int k=size;k<=n;k++)
						{
							long long current=R[i][j][k]-(R[i][j][k-size]+R[i-size][j][k]+R[i][j-size][k]) +(R[i-size][j][k-size]+R[i][j-size][k-size]+R[i-size][j-size][k])-R[i-size][j-size][k-size];
							if(current>=minimum)
								count++;	
						}
			if(count)
				break;
		}
		if(size==0)
			cout<<-1<<endl;
		else
			cout<<size<<" "<<count<<endl;
	}
}
