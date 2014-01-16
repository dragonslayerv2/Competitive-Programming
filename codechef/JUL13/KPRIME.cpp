#include<iostream>
using namespace std;

#define MAX 100005
int isprime[MAX/32+2];
int divisors[MAX];
int ans[MAX][6];
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

void preprocess()
{
	sieve();
	int count=0;
	for(int i=2;i<=MAX;i++)
  	{
		if(isSet(i))
		{
			for(int j=i;j<MAX;j+=i)
			{
				divisors[j]++;
			}
		}  
	}         
	for(int i=1;i<=MAX;i++)
	{
		for(int j=0;j<7;j++)
			ans[i][j]=ans[i-1][j];
		
		if(divisors[i]<=5&&divisors[i]>0)
		{
			ans[i][divisors[i]]++;
		}
	}
}
int main()
{
    preprocess();
    int t;
    cin>>t;
    while(t--)
    {
		int a,b,k;
		cin>>a>>b>>k;
		cout<<ans[b][k]-ans[a-1][k]<<endl;
	}
}
