#include<stdio.h>

#define MAX 100006

float E[MAX][50];
char outbuf[5*MAX*50];

#define GETCHAR getchar_unlocked
#define PUTCHAR putchar_unlocked

inline int readInt() 
{
    int n = 0;
    char c;
    while (1)
    { 
              c=GETCHAR();
              if(c=='\n'||c==' '||c=='\t'||c==EOF) break;
                              n = n * 10 + c - '0';
    }
    return n;
}
 
 

char *p;
inline void tobuf(float a)
{
	
	p=p+sprintf(p,"%f",a);
	*p='\n';
	p++;
}

inline int putbuf()
{
	*p='\0';
	p=outbuf;
	while(*p&&(p-outbuf)<5*MAX*50)
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
		for(k=1;k<25;k++)
		{
				E[n][k]=E[n-1][k]+(E[n-1][k-1]-E[n-1][k])/n;
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
		if(k>=n||k>=25)
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
