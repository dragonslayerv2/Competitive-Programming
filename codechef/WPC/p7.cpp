#include<vector>
using namespace std;

inline long long mul(long long a,long long b,long long MOD)
{
	long long a_high=	a/1000000000;
	long long a_low =	a%1000000000;
	
	long long b_high=	b/1000000000;
	long long b_low =	b%1000000000;
	
	long long result = (a_high*b_high)%MOD;
	for(int i=0;i<9;i++)
		result=(result*10)%MOD;
	
	result=(result+a_high*b_low+a_low*b_high)%MOD;
	for(int i=0;i<9;i++)
		result=(result*10)%MOD;
	
	result=(result+a_low*b_low)%MOD;
	return result;
}

long long p(long long n,long long m, long long MOD)
{
    if(m==0) return 1%MOD;
    
    long long x=p(n,m/2,MOD);
    x=mul(x,x,MOD);
    if(m&1)
    	x=mul(x,n,MOD);
    return x;
}

#include<stdio.h>
#ifdef ONLINE_JUDGE
	#define GETCHAR getchar_unlocked	
	#define PUTCHAR putchar_unlocked
#endif
#ifndef ONLINE_JUDGE
	#define GETCHAR getchar
	#define PUTCHAR putchar
#endif

inline long long readlong() 
{
	int flag=1;
    long long n = 0;
    char c;
    int sign=1;
    while (1)
    { 		
		c=GETCHAR();
    	if(c=='-')	sign=-1;
        else if(c>='0'&&c<='9') {n = n * 10 + c - '0';flag=0;}
        else if(flag!=1) break; 
   }
    return sign*n;
}

int main(){
	int t;
	t=readlong();
	vector<long long> powerSum; 
	while(t--){
		powerSum.clear();
		long long x=readlong(),m=readlong(),n=readlong();
		long long xCopy=m;
		int lastBit=1;
		while(xCopy){
			lastBit++;
			xCopy>>=1;
		}
		powerSum.resize(lastBit+1);
		m++;
		powerSum[0]=1%n;
		for(int i=1;i<powerSum.size();i++){
			long long power2=p(x,((long long)1<<(i-1)),n);
			powerSum[i]=(mul(power2,powerSum[i-1],n)+powerSum[i-1])%n;
		}
		long long ans=0;
		for(int j=powerSum.size()-1;j>=0;j--){
			bool isSet=(m&((long long)1<<j));
			if(isSet){
				long long power2=p(x,((long long)1<<(j)),n);
				ans=mul(ans,power2,n);
				ans+=powerSum[j];
				ans%=n;
			}
		}
		printf("%lld\n",ans);
	}
}
