#include<stdio.h>
#include<iostream>
#include<vector>
#include<cmath>
using namespace std;

class sieve
{
	private:
		vector<int> isprime;
		bool isSet(int n) const
		{
			return (isprime[n>>5]&(1<<(n&31)));
		}
		bool unSet(int n)
		{
			isprime[n>>5] &= ~(1<<(n&31));
		}
		
		
	public:
		sieve(int MAX)
		{
			isprime.resize(MAX/32+10);
		
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
            		for(j=i*i;j<=MAX;j+=i)
                		unSet(j);
		}
		
		bool isPrime(int n) const
		{
			return isSet(n);
		}		
};

#ifdef ONLINE_JUDGE
	#define GETCHAR getchar_unlocked	
	#define PUTCHAR putchar_unlocked
#endif
#ifndef ONLINE_JUDGE
	#define GETCHAR getchar
	#define PUTCHAR putchar
#endif

inline int readInt() 
{
	int flag=1;
    int n = 0;
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
	//freopen("in.txt","r",stdin);
	sieve S(1000000);
	vector<int> primes;
	primes.reserve(100000);
	for(int i=2;i<=1000000;i++)
		if(S.isPrime(i)){
			primes.push_back(i);
		}
	
	vector<vector<int> > factors(1000001);
	for(int i=2;i<factors.size();i++){
		int currentNumber=i;
		int iterations=sqrt(currentNumber);
		for(int j=0;j<=iterations;j++){
			if(!(currentNumber%primes[j])){
				factors[i].push_back(primes[j]);
				while(!(currentNumber%primes[j]))
					currentNumber/=primes[j];
			}
		}
		if(currentNumber!=1)
			factors[i].push_back(currentNumber);
	}
	
	int t=readInt();
	vector<int> lastOccurances;
	lastOccurances.resize(1000001);
	while(t--){
		for(int i=0;i<primes.size();i++)
			lastOccurances[primes[i]]=-1;			
					
		int n=readInt();
		int first=0;
		int longestStreak=-1;
		
		for(int last=0;last<n;last++){
			int currentNumber=readInt();
			if(last!=0){
				for(int i=0;i<factors[currentNumber].size();i++)
					first=max(first,lastOccurances[factors[currentNumber][i]]+1);				
				longestStreak=max(longestStreak,last-first+1);
			}
			for(int i=0;i<factors[currentNumber].size();i++)
				lastOccurances[factors[currentNumber][i]]=last;
		}
		if(longestStreak<=1)
			cout<<-1;
		else
			cout<<longestStreak;
		cout<<endl;
	}
}
