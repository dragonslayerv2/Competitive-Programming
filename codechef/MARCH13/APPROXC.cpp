#include<stdio.h>
#define GCC
#define PUTCHAR putchar//_unlocked
#undef ONLINEJUDGE
#define GETCHAR getchar//_unlocked
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


int main()
{
	
	int t;
	t=readInt();
	while(t--)
	{
		int num=103993%33102;
		int den=33102;
		int n;
		n=readInt();
		
		PUTCHAR('3');
		if(n>0)
		{
			PUTCHAR('.');
			while(n)
			{
				num=num*10;
				PUTCHAR('0'+num/den);
				num=num%den;
				n--;
			}			
		}
		PUTCHAR('\n');
	}
	return 0;
}
