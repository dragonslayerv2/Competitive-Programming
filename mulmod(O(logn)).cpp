/*
	Name: (a*b)%c
	Copyright: 
	Author: Shobhit Saxena
	Date: 14/05/13 22:54
	Description: This algorithm calculates (a*b)%c in O(log(b)).
				 
					
*/


#include<iostream>
using namespace std;



long long mul(long long a,long long b,long long MOD)
{
	if(b==0)
		return 0;
	long long x=mul(a,b/2,MOD);
	
	if(b&1)
		return ((x+x)%MOD+(a%MOD))%MOD;
	else
		return (x+x)%MOD;
}

