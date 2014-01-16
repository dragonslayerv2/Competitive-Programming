#include<iostream>
#include<vector>
using namespace std;


const int INVALID = -100000;

// Normally wouldn't bother with this, but there's a lot of data to read so we need to be fast.
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
		int n;
		n=readlong();;
		vector<pair<int,int> > point(n);
		for(int i=0;i<n;i++)
		{
			point[i].first=readlong();
			point[i].second=readlong();
		}
		
		int count=0;
		for(int i=0;i<n;i++)
		{
			if(point[i].first!=INVALID)
			{
				count++;
				int rows=0,columns=0;
				for(int j=i+1;j<n;j++)
				{
					if(point[j].first==point[i].first)
						rows++;
					if(point[j].second==point[i].second)
						columns++;
				}	
				if(rows>columns)
				{
					for(int j=i+1;j<n;j++)
					{
						if(point[j].first==point[i].first)
							point[j].first=point[j].second=INVALID;
					}
				}
				else
				{
					for(int j=i+1;j<n;j++)
					{
						if(point[j].second==point[i].second)
							point[j].first=point[j].second=INVALID;
					}
				}
				point[i].first=point[i].second=INVALID;
			}
		}
		writeInt(count);
	}
}
