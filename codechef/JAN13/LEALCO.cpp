#include<stdio.h>
#define GETCHAR getchar//_unlocked
#define PUTCHAR putchar//_unlocked

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

int changed[17];
int n,k,m;
int min;
int array[17];

void check()
{
int count=0;
int i,j;
int nmax=0;
int max=0;
for(i=0;i<=n-k;++i)
{ nmax=max=0;

 for(j=i;j<i+k;++j)
	 {if((array[j]+changed[j])>max)
		{max=(array[j]+changed[j]);nmax=1;
		}
	 else if((array[j]+changed[j])==max)
	 {nmax++;
	 }
	 }
 if(nmax>=m)
 break;
}
if(i<=n-k);
else
{for(i=0;i<n;++i)
if(changed[i])
count++;
if(count<min)
min=count;
}
}

void xxx(int cur)
{
if(cur==n)
  check();

else{changed[cur]=0;
	  xxx(cur+1);

	 changed[cur]=1;
	 xxx(cur+1);
	 }
}

int main()
{
int t,i;
t=readInt();
while(t--)
{
min=20;
n=readInt();
k=readInt();
m=readInt();
for(i=0;i<n;++i)
array[i]=readInt();
xxx(0);
if(min!=20)
writeInt(min);
else
printf("-1\n");
}
return 0;
}
