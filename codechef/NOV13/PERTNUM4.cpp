#include<stdio.h>

#include<map>
#include<iostream>
#include<vector>
using namespace std;

#define LIMIT 1000000000000LL
//------------------------------------------------------------------------------
#define MAX 1000005
int isprime[MAX/32+2];

#define isSet(n) isprime[n>>5]&(1<<(n&31))
#define unset(n) isprime[n>>5] &= ~(1<<(n&31));
vector<int> primelist;
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

bool prime(long long j)
{
	bool flag=true;
	int pos=0;
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
			if(solutionarray.find(j)==solutionarray.end()&&prime(j))
				count++;
		}
		
		for(;j<=R;j+=6)
		{
			if(j+1<=R&&solutionarray.find(j+1)==solutionarray.end()&&prime(j+1))
				count++;
			if(j+5<=R&&solutionarray.find(j+5)==solutionarray.end()&&prime(j+5))
				count++;
		}
		cout<<count<<endl;;
		if(!solutionarray[L])
			solutionarray.erase(L);
	}
}
