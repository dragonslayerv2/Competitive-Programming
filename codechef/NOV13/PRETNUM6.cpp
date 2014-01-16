#include<stdio.h>
#include<stdlib.h>
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
vector<long long> power3;
void generatesolutionarray()
{
	long long number=2;
	for(int count=1;number<=LIMIT;count++)
	{
		if(isSet(count+1))
			power2.push_back(number);
		number*=2;
	}
	number=3;
	for(int count=1;number<=LIMIT;count++)
	{
		if(isSet(count+1))
			power3.push_back(number);
		number*=3;
	}
	for(long long i=2;i<primelist.size();i++)
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
//----------------------------------------------------------------------------
int modulo(int a,int b,int c){
    long long x=1,y=a; // long long is taken to avoid overflow of intermediate results
    while(b > 0){
        if(b%2 == 1){
            x=(x*y)%c;
        }
        y = (y*y)%c; // squaring the base
        b /= 2;
    }
    return x%c;
}

long long mulmod(long long a,long long b,long long c){
    long long x = 0,y=a%c;
    while(b > 0){
        if(b%2 == 1){
            x = (x+y)%c;
        }
        y = (y*2)%c;
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
//------------------------------------------------------------------------------
bool prime(long long j)
{

	return Miller(j,2);
/*	bool flag=true;
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
	return flag;*/
}


inline bool isanswer(long long L)
{
	if(L==2||L==3)
		return false;
	
	if(solutionarray.find(L)!=solutionarray.end()||(prime(L)))
		return true;
	else return false;
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
			//	cout<<power2[i]<<endl;
				count++;
			}
		}
			
		for(int i=0;i<power3.size();i++)
		{
			if(power3[i]>R)
				break;
			if(power3[i]>=L)
			{
	//			cout<<power3[i]<<endl;
				count++;
			}
		}
		
		while(L%6&&L<=R)
		{
			if(isanswer(L))
				count++;
			L++;
		}
		
		for(;L<=R;L+=6)
		{
			if(L+1<=R&&isanswer(L+1))
				count++;
			if(L+5<=R&&isanswer(L+5))
				count++;
		}
		cout<<count<<endl;
	}
}
