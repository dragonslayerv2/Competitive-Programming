#include<stdio.h>
#define MOD 1000000007
#define MAX 1000010

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
 

inline void writeString(char *x) 
{
     while(*x)
     {
	 	PUTCHAR(*x);x++;
	 }
	 PUTCHAR('\n');
}


int fibo[MAX];



inline void initfibo()
{
	fibo[0]=fibo[1]=1;
	int i;
	for(i=2;i<MAX;i++)
	{
		fibo[i]=(fibo[i-1]+fibo[i-2])%MOD;
	}
}


inline int get1(long long num)
{
	int count=0;
	while(num)
	{
		if(num&1)
			count++;
		num>>=1;
	}
	return count;
}
int main()
{
	initfibo();
	int t;
	t=readInt();
	while(t--)
	{
		int n,g;
		n=readInt();
		g=readInt();
		if(g>32)
			writeString("INCORRECT");
		else if(get1(fibo[n])==g)
			writeString("CORRECT");
		else
			writeString("INCORRECT");
	}
	return 0;
}
