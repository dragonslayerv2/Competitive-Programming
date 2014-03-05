#include<stdio.h>

#define MOD2 329885391853LL


typedef unsigned long long int64;
int64 mulmod(int64 A, int64 B, int64 C)
{
	int64 a = A/1000LL;
	int64 b = A%1000LL;
	int64 c = B/1000LL;
	int64 d = B%1000LL;
	int64 ac = a * c;
	int64 ad = a * d;
	int64 bc = b * c;
	int64 bd = b * d ;
	
	for (int i = 1; i<=6; i++){
		ac = ac * 10;
		ac %= C;
	}
	for (int i = 1; i<=3; i++){
		ad = ad * 10;
	ad %= C;
}
for (int i = 1; i<=3; i++){
bc = bc * 10;
bc %= C;
}
return (((((ac + ad) % C) + bc) % C) + bd) % C;
}


long long fact[999990];
long long factorials[999990];

void preprocess()
{
			fact[0]=(1);
			factorials[0]=1;
			for(int i=1;i<=999982;i++)
			{
				factorials[i]=(factorials[i-1]*i)%MOD2;
				fact[i]=(mulmod(fact[i-1],factorials[i],MOD2));
			}
}
int main()
{
	preprocess();
	int t;
	scanf("%d",&t);
	while(t--)
	{
		int n;
		scanf("%d",&n);
		if(n>=999983)
			printf("%lld\n",0LL);
		else
		{
			printf("%lld\n",fact[n]);	
		}		
	}
}
