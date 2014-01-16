/*
	Name: Segmented Sieve
	Copyright: 
	Author: Shobhit Saxena
	Date: 05/11/13 09:10
	Description: Segmented Sieve of Erastothenes
*/

#include<iostream>
#include<vector>
#include<map>
#include<string.h>
using namespace std;


//-----------------------SIEVE--------------------------------------------------
#define MAX 1000000
int isprime[MAX/32+2];

#define isSet(a,n) a[n>>5]&(1<<(n&31))
#define unSet(a,n) a[n>>5] &= ~(1<<(n&31));
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
    
    for(i=5;i*i<=MAX;i+=2)
	        if(isSet(isprime,i))
         	      for(j=i*i;j<=MAX;j+=i)
            		  unSet(isprime,j);
            		  
	for(int i=2;i<=MAX;i++)
		if(isSet(isprime,i))
			primelist.push_back(i);
}
//------------------------------------------------------------------------------
#define GAP 1000000
int segmentedprime[GAP/32+2];

int segmentedsieve(long long a,long long b)
{	
	memset(segmentedprime,-1,sizeof(segmentedprime));
	if(1>=a&&1<=b)
		unSet(segmentedprime,1-a);
	long long L=a;
	long long R=b;
	while(L%6&&L<=R)
	{
		if(L==2)
			L++;
		if(L==3)
			L++;
		if(L%2==0||L%3==0)
			unSet(segmentedprime,(L-a));
		L++;
	}
	
	for(;L<=R;L+=6)
	{
		unSet(segmentedprime,(L-a));
		unSet(segmentedprime,(L+2-a));
		unSet(segmentedprime,(L+3-a));
		unSet(segmentedprime,(L+4-a));
	}
	
	for(int i=2;i<primelist.size()&&(primelist[i]*primelist[i])<=b;i++)
	{
		long long j=(a/primelist[i])*primelist[i];
		if(j<a||j==primelist[i])
			j+=primelist[i];
		
		for(;j<=b;j+=primelist[i])
			unSet(segmentedprime,(j-a));
	}
}

int main()
{
	sieve();

 	int t;
 	cin>>t;
 	while(t--)
 	{
	 	long long L,R;
	 	cin>>L>>R;
	 	segmentedsieve(L,R);
	 	for(long long i=L;i<=R;i++)
	 		if(isSet(segmentedprime,(i-L)))
			 	cout<<i<<endl;
		cout<<endl;
	}
	   
}
