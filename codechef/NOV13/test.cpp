#include<stdio.h>
#include<map>
#include<iostream>
#include<vector>
using namespace std;
			
#define LIMIT 1000000000000LL
//------------------------------------------------------------------------------
#define MAX 10000100
int isprime[MAX/32+2];

#define isSet(n) isprime[n>>5]&(1<<(n&31))
#define unset(n) isprime[n>>5] &= ~(1<<(n&31));
vector<long long> primelist;
void sieve()
{
    long long i,j;
    isprime[0]=0xA28A28AC;
    for(long long i=1;i<=MAX/32+1;i+=3)
    {
            isprime[i]  =0x28A28A28;
            isprime[i+1]=0x8A28A28A;
            isprime[i+2]=0xA28A28A2;
    }
    primelist.push_back(2);
    primelist.push_back(3);
    for(i=5;i*i<=MAX;i+=2)
                           if(isSet(i))
                             {
                             	primelist.push_back(i);
                             	
                                        for(j=i*i;j<=MAX;j+=i)
                                                unset(j);
                             }    
}

//------------------------------------------------------------------------------
map<long long,bool> solutionarray;
vector<long long> power2;
void generatesolutionarray()
{
	long long number=2;
	for(int count=1;number<=LIMIT;count++)
	{
		if(isSet(count+1))
			power2.push_back(number);
		number*=2;
	}
	for(long long i=1;i<primelist.size();i++)
	{
				long long number=primelist[i];
				
				long long count=1;
				while(1)
				{	
					if(number>LIMIT)
						break;
					if(isSet(count+1))
					{
						solutionarray[number]=true;
					}		
					count++;
					
					number*=primelist[i];
				}
	}
}

bool prime(long long j)
{
	if(j==1)
		return false;
	bool flag=true;
	long long pos=0;
	while(1)
	{
		if(pos>=primelist.size())
			break;
		long long temp=primelist[pos];
		if(temp*temp>j)
			break;
		if(j%temp==0)
		{
			flag=false;
			break;
		}
		pos++;
	}
	return flag;
}

int main()
{
    sieve();
   	generatesolutionarray();
   	
 
   	long long t;
   	cin>>t;
   	while(t--)
   	{
		long long L,R;
		cin>>L>>R;
		long long count=0;
		for(int i=0;i<power2.size();i++)
		{
				if(power2[i]>R)
				break;
			if(power2[i]>=L)
			{
				count++;
			//	cout<<power2[i]<<endl;
			}
			
		
		}
		
		if(L%2==0)
			L++;
		while(L<=R)
		{ 
			if(solutionarray.find(L)!=solutionarray.end()||(prime(L)&&L!=2))
			{
				count++;
			//	cout<<L;
			}
			L+=2;
		}
		cout<<count<<endl;
	}
}
