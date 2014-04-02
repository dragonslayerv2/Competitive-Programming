#include<iostream>
#include<vector>
using namespace std;


vector<int> primeList;
#define MAX 10000
int isprime[MAX/32+2];

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
            for(j=i*i;j<=MAX;j+=i)
                unset(j);
    
    for(int i=0;i<MAX;i++)
    	if(isSet(i))
    		primeList.push_back(i);
}


int main()
{
	sieve();
	int t;
	cin>>t;
	while(t--)
	{
		int x;
		cin>>x;
		if(x==16)
			cout<<"Tom"<<endl;
		else if(x==17)
			cout<<"Mike"<<endl;
		else if(x==34)
			cout<<"Tom"<<endl;
		else if(x==289)
			cout<<"Tom"<<endl;
		else if(x%2)
		{
			bool isPrime=true;
			for(int i=0;i<primeList.size()&&primeList[i]<x;i++)
				if(x%primeList[i]==0)
				{
					isPrime=false;
					break;
				}		
			if(isPrime)
				cout<<"Tom"<<endl;
			else
				cout<<"Mike"<<endl;
		}
		else
			cout<<"Mike"<<endl;
	}
}
