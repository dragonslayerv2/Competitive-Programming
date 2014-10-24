#include<vector>
using namespace std;

inline long long mul(long long a,long long b,long long c)
{    
	long long x = 0,y=a%c;    
	while(b > 0)
	{
	    if(b%2 == 1)
		{
			x = (x+y)%c;
		}        
		y = (y*2)%c;
		b /= 2;
	}
	return x%c;
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
//	freopen("in.txt","r",stdin);
	int t;
	t=readlong();
	vector<long long> powerSum; 
	vector<long long> power2;
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
		power2.resize(lastBit+1);
		
		power2[0]=x%n;
		for(int i=1;i<power2.size();i++)
			power2[i]=mul(power2[i-1],power2[i-1],n);
		m++;
		
		powerSum[0]=1%n;
		for(int i=1;i<powerSum.size();i++){
			powerSum[i]=mul(power2[i-1]+1,powerSum[i-1],n);
		}
		long long ans=0;
		for(int j=powerSum.size()-1;j>=0;j--){
			bool isSet=(m&(((long long)1)<<j));
			if(isSet){
				ans=mul(ans,power2[j],n);
				ans+=powerSum[j];
				ans%=n;
			}
		}
		printf("%lld\n",ans);
	}
}
