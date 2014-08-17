#include<iostream>
#include<cstdlib>
#include<time.h>
#include<vector>
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
	int t=10;
	cout<<t<<endl;
	while(t--)
	{
	#define nRange 10000
	#define qRange 10000
	#define elementRange 100
	#define p1Range size_t(100)
	#define p2Range size_t(100)
	#define rRange 1000
	#define sRange 1000
	#define dRange 5000
	#define gRange 1000
	
	int n,q,r,p1,p2;
	n=1+rand()%nRange;
	q=qRange;
	r=rand()%rRange;
	p1=primeList[rand()%min(p1Range,primeList.size())];
	p2=primeList[rand()%min(p2Range,primeList.size())];
	
	cout<<n<<" "<<q<<" "<<r<<" "<<p1<<" "<<p2<<endl;
	for(int i=0;i<n;i++)
		cout<<(rand()%elementRange)<<" ";
	
	cout<<endl;
	while(q--)
	{
		int type=rand()%3;
		cout<<type<<" ";
		if(type==0)
		{
			int s,d,x,y;
			s=rand()%sRange;
			d=rand()%dRange;
			x=1;
			y=0;
			while(x>y)
			{
				x=1+rand()%n;
				y=1+rand()%n;
			}
			cout<<s<<" "<<d<<" "<<x<<" "<<y<<endl;
		}
		else if(type==1)
			cout<<(1+rand()%n)<<" "<<rand()%gRange<<endl;
			
		else
		{
			int x=1;
			int y=0;
			while(x>y)
			{
				x=1+rand()%n;
				y=1+rand()%n;
			}
			cout<<x<<" "<<y<<endl;
		}
	}}
}
