#include<stdio.h>
using namespace std;
const int MaxP=1000001;
#define MAX 1000001
int Primes[MaxP];
int isprime[MAX/32+2];

#define isSet(n) isprime[n>>5]&(1<<(n&31))
#define unset(n) isprime[n>>5] &= ~(1<<(n&31));
	

int sieve()
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
    int k=0;
    for(int i=0;i<MAX;i++)
    {
		if(isSet(i))
		{
			Primes[k++]=i;
		}
	}
	return k;
}



int exp(int a,int p)
{
	if(p>a)return 0;
	int tmp=0;
	while(!(a%p)) 
	{ a/=p;
	  tmp++;
	  //cout<<"hi";
	}
	return tmp;
}

int main()
{
	int index=sieve();
	//for(int i=0;i<index;i++) cout<<Primes[i]<<" ";
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n,p[11],ans=1;
		int Exponent[MaxP]={0};
		scanf("%d",&n);
		for(int i=0;i<n;i++) scanf("%d",&p[i]);
		for(int j=0;j<n;j++)
		{
		 for(int i=0;i<index;i++)
		 {
			Exponent[i]+=exp(p[j],Primes[i]);
	     }
		}
		for(int i=0;i<MaxP;i++)  ans*=(Exponent[i]+1);
		printf("%d\n",ans);
	}
}
