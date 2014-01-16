#include<stdio.h>
#include<string.h>
#define MAX 100005

int isprime[MAX/32+2];
int divisors[MAX];
#define isSet(n) isprime[n>>5]&(1<<(n&31))
#define unset(n) isprime[n>>5] &= ~(1<<(n&31));

//int array[MAX/32];

void sieve()
{
    int i,j;
    memset(isprime,-1,sizeof(isprime));
    unset(0);
    unset(1);
    unset(4);

    for(i=6;i<=MAX;i+=6)
    {

            unset(i);
            unset(i+2);
            unset(i+3);
            unset(i+4);
    }
    for(i=5;i*i<=MAX;i+=2)
                  {  if(isSet(i))
                             {
                                        for(j=i*i;j<=MAX;j+=i)
                                                unset(j);
                         }}
  
  	for(int i=2;i<=MAX;i++)
  	{
		if(isSet(i))
		{
			for(int j=i+i;j<MAX;j++)
			{
				divisors[j]++;
			}
		}  
	}
  
    int k=0;
  /*  for(i=0;i<MAX;i++)
    {
		if(isSet(i))
			{array[k]=i;
			k++;}
	}
	printf("%d",k);*/
   
}
int main()
{
    sieve();
    /*int t;
    scanf("%d",&t);
    while(t--)
	{
		int n;
		scanf("%d",&n);
		if(isSet(i))
		{
			for(int i=1;i
		}
		else printf("-1\n");
		
	
	}
    return 0;*/
}
