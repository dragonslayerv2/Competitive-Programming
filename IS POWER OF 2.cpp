/*
	Name: Number power of 2
	Copyright: 
	Author: Shobhit Saxena
	Date: 30/01/13 10:41
	Description: To check whether a number is power of 2 or not. O(1) solution.
				 x&(~x+1) returns the lowest binary digit tht is one. If this is the only digit tht is one thn than its 2^n. so we compare this number with the original number checking whether the 2 things are same or not.
*/

#include<stdio.h>

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long n;
		scanf("%lld",&n);
		int flag=1;
		printf("%s\n",(n!=0&&(n&(~n+1))==n)?"Yes":"No");
	}
	return 0;
}


/*
			0001000000
			1110111111
			1111000000
			0001000000
			
			
			
			
			
			
			
			0011100000
			1100011111
			1100100000
			0000100000
			
			
			
			0010010000
			1101101111
			1101110000
			0000010000	
*/






