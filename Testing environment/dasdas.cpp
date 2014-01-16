#include<stdio.h>
#include<string.h>
int islighted[10010];

#define GETCHAR getchar//_unlocked
#define PUTCHAR putchar//_unlocked

inline int readInt() 
{
    int n = 0;
    char c;
    while (1)
    { 
              c=GETCHAR();
              if(c=='\r'||c==' '||ch==EOF) break;
                              n = n * 10 + c - '0';
    }
    return n;
}
 

inline void writeInt(int x) 
{
     int i = 10;
     char buf[11];
     // buf[10] = 0;
     buf[10] = ' ';

     do 
     {
        buf[--i] = x % 10 + '0';
        x/= 10;
     }while(x);
     do 
     {
        PUTCHAR(buf[i]);
     } while (buf[i++] != ' ');
}


void init()
{
	memset(islighted,-1,sizeof(islighted));
	
	for(int k=2;k<1000;k++)
	{
		int count=0;
		for(int i=1;i<10000;i++)
		{
			if(islighted[i])
				count++;
			if(count==k)
			{
				islighted[i]=0;
				count=0;
			}	
		}
	}
}
int main()
{
		init();
		int t;
		t=readInt();
		while(t--)
		{
			int n;
			n=readInt();
			for(int i=1;i<=n;i++)
			{
				if(islighted[i])
					writeInt(i);
			}
			printf("\n");
		}
		return 0;
}
