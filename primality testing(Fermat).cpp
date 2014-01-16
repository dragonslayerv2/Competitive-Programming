/*
	Name: Fermat Primality testing.
	Copyright: 
	Author: 
	Date: 14/05/13 23:55
	Description: Test whether a number is prime or not.
				Complexity(iterations*O(logn))
*/

#include<cstdlib>
#include<iostream>


using namespace std;

long long mul(long long a,long long b,long long MOD)
{
	long long a_high=	a/1000000000;
	long long a_low =	a%1000000000;
	
	long long b_high=	b/1000000000;
	long long b_low =	b%1000000000;
	
	long long result = (a_high*b_high)%MOD;
	for(int i=0;i<9;i++)
		result=(result*10)%MOD;
	
	result=(result+a_high*b_low+a_low*b_high)%MOD;
	for(int i=0;i<9;i++)
		result=(result*10)%MOD;
	
	result=(result+a_low*b_low)%MOD;
	return result;
}


long long p(long long a,long long b,long long MOD)
{
	if(b==0) return 1;
    
    long long x=p(a,b/2,MOD);
   	
    if((b&1)==0) 
	   return mul(x,x,MOD);
    else
	   return mul(mul(x,x,MOD),a,MOD);
}



bool fermat(long long num,int iterations)
{
	if(num==1)
		return false;
	if(num==2)
		return true;
	else
	{
		for(int i=0;i<iterations;i++)
		{
			long long a=(rand()%(num-2))+2;
			
			if(p(a,num-1,num)!=1) return false;
		}
	}
	return true;
}

int main()
{
	cout<<fermat(2209032015182513LL,10000);	
}
