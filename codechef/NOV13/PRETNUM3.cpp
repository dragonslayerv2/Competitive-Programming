#include<stdio.h>
#include<random>
#include<map>
#include<iostream>
using namespace std;

#define LIMIT 1000000000000LL
//------------------------------------------------------------------------------
#define MAX 1000005
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
                             {
                                        for(j=i*i;j<=MAX;j+=i)
                                                unset(j);
                             }    
}

//------------------------------------------------------------------------------
map<long long,bool> solutionarray;

void generatesolutionarray()
{
	long long number=2;
	int count=1;
	while(1)
	{
		
		if(number>LIMIT)
			break;
		if(isSet(count+1))
			solutionarray[number]=true;
		
		if(count==1)
		{
			count++;
			number*=2;
		}
		else
		{
			count+=2;
			number*=2*2;
		}
	}
	
	for(int i=3;i<=MAX;i+=2)
	{
		
		if(isSet(i))
		{
			{
				long long number=i;
				int count=1;
				while(1)
				{
					if(number>LIMIT)
						break;
					if(isSet(count+1))
					{
						solutionarray[number]=true;
		
					}
					if(count==1)
					{
						count++;
						number*=i;
					}
					else
					{
						if(number>LIMIT/(i*i))
							break;
						count+=2;
						
						number*=i*i;
					}
				}
			}
		}
	}
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
    sieve();
   	generatesolutionarray();
   	
   	
   	int t;
   	cin>>t;
   	while(t--)
   	{
		   		
		long long L,R;
		cin>>L>>R;
		map<long long,bool>::iterator i=solutionarray.find(L);
		if(i==solutionarray.end())
		{
			i=solutionarray.insert(make_pair(L,false)).first;
			i++;
		}
		
		long long count=0;
		while(i->first<=R&&i!=solutionarray.end())
		{
			count++;
			i++;
		}
		
		long long j;
		for(j=L;j%6&&j<=R;j++)
		{
			if(solutionarray.find(j)==solutionarray.end()&&Miller(j,1))
				count++;
		}
		
		for(;j<=R;j+=6)
		{
			if(j+1<=R&&solutionarray.find(j+1)==solutionarray.end()&&Miller(j+1,2))
				count++;
			if(j+5<=R&&solutionarray.find(j+5)==solutionarray.end()&&Miller(j+5,2))
				count++;
		}
		cout<<count<<endl;;
		if(!solutionarray[L])
			solutionarray.erase(L);
	}
}
