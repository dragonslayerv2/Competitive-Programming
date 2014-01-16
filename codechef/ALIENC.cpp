#include<stdio.h>

int day=0;

void days(long long n)
{

	if(day>=36524) return;
	if(n==1) return;
	day++;
	if(n%2) days(3*(n+1));
	else days(n/2);	
}

int main()
{
	int t;
	scanf("%d",&t);
	while(t--)
	{
		long long n;
		scanf("%lld",&n);
		int flag=1;
		while(n)
		{
			if((n&1)&&n!=1){flag=0;break;}
			n=n>>1;
		}
		printf("%s\n",flag?"No":"Yes");
	}
	return 0;
}
