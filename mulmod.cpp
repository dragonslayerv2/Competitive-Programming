/*
	Name: (a*b)%c
	Copyright: 
	Author: Shobhit Saxena
	Date: 14/05/13 22:54
	Description: This algorithm calculates (a*b)%c in O(1).
					it first convert a and b to 
						
													a_high	a_low
												*	b_high	b_low
													--------------
													a_low*b_low
					a_low*b_high b_low*a_high		XXXXXXXXXXX
	a_high*b_high		XXXXXXXXXXX
	------------------------------------------------------------------
	
	and then solves the individual elements in such a way that the whole product donot exceeds MOD
	
	10*MOD must not reach long long limits.
	
	This method is O(1) but yes, solves itself in 18 steps as 18 is the highest power associated with a coefficient.
*/


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

