#include<iostream>
using namespace std;
#include<stdio.h>
#define GETCHAR getchar_unlocked
#define PUTCHAR putchar_unlocked

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
	int t=readlong();
	
	while(t--)
	{
		int n=readlong(),m=readlong(),k=readlong();
		if((n==1&&m==1)||(n==2&&m==1)||(m==2&&n==1))
			cout<<0<<endl;
		
		else if(n>1&&m>1)
		{
			if(k%2)
				cout<<k/2+1;
			else
				cout<<k/2;
			cout<<endl;
		}
		else
			cout<<k<<endl;
		
	}
}
