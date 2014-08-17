#include<iostream>
#include<vector>
#include<cstdlib>
#include<time.h>
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


int main()
{
	sieve S(1000000);
	vector<int> primeList;
	for(int i=0;i<1000000;i++)
		if(S.isPrime(i))
			primeList.push_back(i);
		srand(time(NULL));	
	int t=1000;
	cout<<t<<endl;
	while(t--)
	{
		#define VALUES 10000
		
		cout<<rand()%VALUES<<" "<<rand()%VALUES<<" "<<rand()%VALUES<<" "<<1+rand()%VALUES<<" "<<primeList[rand()%primeList.size()]<<endl;	
	}
	
}
