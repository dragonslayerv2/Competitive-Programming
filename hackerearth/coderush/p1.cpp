#include<vector>
#include<iostream>
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
		size_t size() const {
			return isprime.size();
		}	
};

int main(){
	sieve primeSieve(1000000);
	vector<int> primes;

	primes.reserve(1000000);
	for(int i=2;i<primeSieve.size();i++){
		if(primeSieve.isPrime(i))
			primes.push_back(i);
	}
	
	int t;
	cin>>t;
	while(t--){
		int n;
		cin>>n;
		long long ans = 1;
		
		for(int j=0;j<primes.size();j++){
			int count=0;
			while(n%primes[j]==0)
			{
				n/=primes[j];
				count++;
			}
			ans*=count+1;
		}
		if(n!=1)
			ans*=2;
		cout<<ans<<endl;
	}
}
