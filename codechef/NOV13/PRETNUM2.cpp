#include<iostream>
#include<map>
#include<random>
using namespace std;


inline long long gcd(long long a, long long b)
{
   long long temp;    
   while(b)
   {
           temp=a;
           a=b;
           b=temp%b;
   }
   return a;
}

long long pollard(long long n)
{
	default_random_engine generator;
	uniform_int_distribution<long long> distribution(0,n);
	
	long long x=2;
	long long y=2;
	long long d=1;
	while(d==1)
	{
		x=distribution(generator);
		y=distribution(generator);
		long long abs=x-y;
		if(abs<0) abs*=-1;
		d=gcd(abs,n);
	}
 	return d;
}
map<long long,int> divisors;
void divisorcount(long long n)
{
	while(!(n&1))
	{
			divisors[2]++;
			n>>=1;
	}
	if(n==1)
		return;
	else
	{		
				long long divisor=pollard(n);				
				if(divisor==n||divisor==1)
					divisors[n]++;
				else
				{
					divisorcount(n/divisor);
					divisorcount(divisor);
				}			
	}
}
	
long long mulmod(long long a,long long b,long long MOD)
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

    long long modulo(long long a,long long b,long long c){
    long long x=1,y=a;
    while(b > 0){
        if(b%2 == 1){
            x = mulmod(x,y,c);
        }
        y =mulmod(y,y,c);
        b /= 2;
        }
    return x%c;
    }
bool Miller(long long p,int iteration){
    if(p<2){
        return false;
    }
    if(p!=2 && p%2==0){
        return false;
    }
    long long s=p-1;
    while(s%2==0){
        s/=2;
    }
    for(int i=0;i<iteration;i++){
        long long a=rand()%(p-1)+1,temp=s;
        long long mod=modulo(a,temp,p);
        while(temp!=p-1 && mod!=1 && mod!=p-1){
            mod=mulmod(mod,mod,p);
            temp *= 2;
        }
        if(mod!=p-1 && temp%2==0){
            return false;
        }
    }
    return true;
}

int main()
{
	int t;
	cin>>t;
	while(t--)
	{
		long long L,R;
		cin>>L>>R;
		int ans=0;
		while(L<=R)
		{
			divisors=map<long long,int>();	
			divisorcount(L);	
			divisors[1]=0;
			
			long long count=1;
			for(map<long long,int>::iterator j=	divisors.begin();j!=divisors.end();j++)
				count*=j->second+1;
			if(Miller(count,2))
				ans++;
			L++;
		}
		cout<<ans<<endl;
	}
}
