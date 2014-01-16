#include<stdio.h>
#include<ctype.h>
#define MAX 100006
#define ULIM 32
double E[MAX][ULIM]={0};
char outbuf[5*MAX*50];
#define PUTCHAR putchar_unlocked
#define GETCHAR getchar_unlocked

inline int readInt() 
{
	int flag=1;
    int n = 0;
    char c;
    while (1)
    { 
              c=GETCHAR();
              if(isdigit(c)) {n = n * 10 + c - '0';flag=0;}
              else if(flag!=1) break; 
                              
    }
    return n;
}
 
 
char *p;
inline void tobuf(double a)
{
	
	p=p+sprintf(p,"%.6lf",a);
	*p='\n';
	p++;
}
 
inline int putbuf()
{
	*p='\0';
	p=outbuf;
	while(*p)
		{
			PUTCHAR(*p);
			p++;
		}
}





void preprocess()
{
	int n,k;
	for(n=1;n<MAX;n++)
	{
		E[n][0]=n;
		for(k=1;k<ULIM;k++)
		{
				E[n][k]=((n-1)*E[n-1][k]+E[n-1][k-1])/n;
		}
	}
}


int main()
{
	p=outbuf;
	preprocess();
	
	int t;
	t=readInt();
	while(t--)
	{
		int n,k;
		n=readInt();
		k=readInt();
		if(k>=n||k>=ULIM)
			{
				tobuf(0.0);
			}
		else
			{
			//	printf("%d %d",n,k);
			//	printf("%f\n",E[n][k]);
				tobuf(E[n][k]);
			}
	}
	putbuf();
	return 0;
}
