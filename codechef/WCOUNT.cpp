#include<stdio.h>

#define MOD 1000000007
#define GETCHAR getchar_unlocked
#define PUTCHAR putchar_unlocked

inline void writeInt(int x) 
{
     int i = 11;
     char buf[20];
     // buf[10] = 0;
     buf[11] = '\n';

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


long long fact[501],ifact[501];

long long pow(int m,int n)
{
	if(n==0) return 1;
	long long x=pow(m, n/2);

	if(n%2) return(((x*x)%MOD)*m)%MOD;
	else return (x*x)%MOD;
}

inline void initfact()
{
	fact[0]=1;
	int i;
	for(i=1;i<=500;i++)
		fact[i]=(fact[i-1]*i)%MOD;
	ifact[500]=pow(fact[500],MOD-2);
	
	for(i=499;i>=0;i--)
		ifact[i]=(ifact[i+1]*(i+1))%MOD;
}

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
	initfact();
	int t;
	t=readInt();

	
	while(t--)
	{
		int hashmap[200]={0};
		char c;
		int count=0;
		while((c=GETCHAR())!='\n')
		{
			count++;
			hashmap[c]++;
		}
		
		long long ans=fact[count];
		int i;
		for(i=0;i<26;i++)
		{
			ans=(ans*ifact[hashmap['A'+i]])%MOD;
			ans=(ans*ifact[hashmap['a'+i]])%MOD;
		}
		
		writeInt((int)ans);
	}
	
	return 0;
}
