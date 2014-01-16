#include<iostream>
using namespace std;

//-------------------------SIEVE------------------------------------------------
#define MAX 10010
int isprime[MAX/32+2];

#define isSet(n) isprime[n>>5]&(1<<(n&31))
#define unset(n) isprime[n>>5] &= ~(1<<(n&31));

void sieve()
{
    int i,j;
    isprime[0]=0xA28A28AC;
    for(int i=1;i<=MAX/32+1;i+=3)
    {
            isprime[i]  =0x28A28A28;
            isprime[i+1]=0x8A28A28A;
            isprime[i+2]=0xA28A28A2;
    }
    for(i=5;i*i<=MAX;i+=2)
                           if(isSet(i))
                             {
                                        
										
										for(j=i*i;j<=MAX;j+=i)
                                                unset(j);
                             }
}
//--------------------------------------------------------------------------------
#define MAXPRIME 1230
#define MAXSEMIPRIME 670

int prime[MAXPRIME];
int semiprime[MAXSEMIPRIME];

int bsearch(int l,int h,int a[],int c)
{
    int pos;
    while(l<=h)
    {
     pos=(l+h)/2;
     if(a[pos]==c)
                  break;
     else if(a[pos]<c)
                      l=pos+1;
     else
                      h=pos-1;
    }
	if(a[pos]<c)
		return pos;
	if(a[pos]==c)
		return pos-1;
	else
		return pos-1;
	
}
void init()
{
	int k=1;
	prime[0]=2;
	for(int i=3;i<10010;i+=2)
	{	
		if(isSet(i))
			prime[k++]=i;
			
	}
	k=0;
	for(int i=0;i<10010;i+=2)
	{	
		if(isSet((i/2)))
			semiprime[k++]=i;
	}
}

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


int main()
{	
	sieve();
	init();
	
	int t;
	t=readInt();
	//cin>>t;
	while(t--)
	{
		int n;
		n=readInt();
		//cin>>n;
		int count=0;
		int k=bsearch(0,(sizeof(semiprime))/4-1,semiprime,n);

		
		int i=0;
		
		while(k>0||prime[i]<n)
		{
			if(prime[i]+semiprime[k]==n)
			{
					count++;
					i++;
					k--;
			}
			else if(prime[i]+semiprime[k]<n)
					i++;
			else
					k--;
		}
		writeInt(count);
		//cout<<count<<endl;
	}
	return 0;
}
