#include<iostream>
#include<algorithm>
#include<vector>
#include<map>
using namespace std;
#define LIMIT 1000000000000LL
map<long long,bool> solutionarray;
vector<long long> power2;
vector<long long> power3;
//----------------------------------------------------
#define MAX 1000005
int isprime[MAX/32+2];

#define isSet(n) isprime[n>>5]&(1<<(n&31))
#define unSet(n) isprime[n>>5] &= ~(1<<(n&31));
vector<long long> primelist;
vector<long long> ans;
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
    for(i=5;i*i<=MAX;i+=2)
                           if(isSet(i))
                             {
                                        for(j=i*i;j<=MAX;j+=i)
                                                unSet(j);
                             }
	for(int i=2;i<=MAX;i++)
		if(isSet(i))
			primelist.push_back(i);
}

bool segmentedprime[MAX];

long long segmentedsieve(long long a,long long b)
{
	
	for(long long i=a;i<=b;i++)
	{	
		if(i==1) 
			segmentedprime[i-a]=false;
		else if(i==2||i==3||i==5)
			segmentedprime[i-a]=true;
		else if(i%2==0||i%3==0||i%5==0)
			segmentedprime[i-a]=false;
		else
			segmentedprime[i-a]=true;
	}
	
	for(int i=3;i<primelist.size()&&(primelist[i]*primelist[i])<=b;i++)
	{
		long long j=(a/primelist[i])*primelist[i];
		if(j<a)
			j+=primelist[i];
		for(;j<=b;j+=primelist[i])
		{
			if(j!=primelist[i])
				segmentedprime[j-a]=false;
		}
	}
	int count=0;

	for(long long i=a;i<=b;i++)
	{
		if(segmentedprime[i-a])
		{
			ans.push_back(i);
		//	cout<<i<<" ";
			count++;
		}	
	}
	//cout<<endl;
	return count;
}


void generatesolutionarray()
{
	long long number=4;
	for(int count=2;number<=LIMIT;count++)
	{
		if(isSet(count+1))
			power2.push_back(number);
		number*=2;
	}
	number=9;
	for(int count=2;number<=LIMIT;count++)
	{
		if(isSet(count+1))
			power3.push_back(number);
		number*=3;
	}
	for(long long i=2;i<primelist.size();i++)
	{
				long long number=primelist[i]*primelist[i];
				
				long long count=2;
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

long long primepowers(long long L,long long R)
{
		int count=0;
		for(int i=0;i<power2.size();i++)
		{
			
			if(power2[i]>R)
				break;
			if(power2[i]>=L)
			{
				count++;
				ans.push_back(power2[i]);
			}
		}
			
		for(int i=0;i<power3.size();i++)
		{
			if(power3[i]>R)
				break;
			if(power3[i]>=L)
			{
				count++;
				ans.push_back(power3[i]);
			}
		}
		
		while(L%6&&L<=R)
		{
			if(solutionarray[L])
			{
				count++;
						ans.push_back(solutionarray[L]);
			}
			L++;
		}
		for(;L<=R;L+=6)
		{
			if(L+1<=R&&solutionarray[L+1])
			{
				ans.push_back(solutionarray[L+1]);
				count++;
				
			}
			if(L+5<=R&&solutionarray[L+5])
			{
				count++;
				ans.push_back(solutionarray[L+5]);
			}
		}
		return count;
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
		long long count=primepowers(L,R);
	//	cout<<count<<" ";
		count+=segmentedsieve(L,R);
		
		sort(ans.begin(),ans.end());
		
		for(int i=0;i<ans.size();i++)
			cout<<ans[i]<<endl;
			
		cout<<count<<endl;
	}	
}
