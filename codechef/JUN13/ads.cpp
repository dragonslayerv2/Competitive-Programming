#include<stdio.h>
#define mod 1000000007;
long int fact[1000010];
void compute()
{
	long int i;
	fact[0] = 1;
	for(i=1;i<=1000000;i++)
	{
		fact[i] = fact[i-1]*i%mod;
	}
}
long int power(long int x,long int y)
{

   if(y == 0)
   return 1;
   else if(y%2==0)
   return (power(x,y/2)%1000000007)*(power(x,y/2)%1000000007);
   else
     return x*(power(x,y/2)%1000000007)*(power(x,y/2)%1000000007);

}
int main()
{
	int cases;
	long int a,b,temp;
	long long result;
	compute();
	scanf("%d",&cases);
	while(cases--)
	{
		scanf("%ld%ld",&a,&b);
		temp = b-a+1;
//	result = power(2,3);
    result = (fact[temp]*(power((temp),(a-temp)/2)%1000000007)*power((temp-1),(a-temp+1)/2))%mod;
		printf("%lld\n",result);
	}
}

