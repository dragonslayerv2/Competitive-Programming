/*
	Name: (a*b)%c
	Copyright: 
	Author: Shobhit Saxena
	Date: 14/05/13 22:54
	Description: This algorithm calculates (a*b)%c in O(log(b)).
				 
					
*/


#include<iostream>
using namespace std;

long long mulmod(long long a,long long b,long long c)
{    
	long long x = 0,y=a%c;    
	while(b > 0)
	{
	    if(b%2 == 1)
		{
			x = (x+y)%c;
		}        
		y = (y*2)%c;
		b /= 2;
	}
	return x%c;
}

