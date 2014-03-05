#include<stdio.h>
#include<stdio.h>
#include<string.h>
using namespace std;



long long nCr[200][200];

void generatenCr(int n,long long MOD)
{
	for(int i=0;i<=n;i++)
		for(int j=0;j<=i;j++)
		{
			if(i==0||j==0)
				nCr[i][j]=1%MOD;
			else
				nCr[i][j]=(nCr[i-1][j-1]+nCr[i-1][j])%MOD;
		}
}

long long p(long long n,long long m,long long MOD)
{
    if(m==0) return 1%MOD;
    
    long long x=p(n,m/2,MOD);
    if(m%2==0) 
               return (x*x)%MOD;
    else
               return (((x*x)%MOD)*n)%MOD;
}

int main()
{	
	int t;
	scanf("%d",&t);
	
	while(t--)
	{
		char s[200];
		long long MOD;
		scanf("%s %lld",s,&MOD);
		
		//strrev(s);
		generatenCr(100,MOD);
			
		long long ans=0;
		
		int N=strlen(s);
		for(int i=0;s[i];i++)
		{
			int n=i+1;
			long long tempAns=0;
			for(int j=0;j<=n-1;j++)
			{
				tempAns+=nCr[n-1][j]*p(10,j,MOD);	
				tempAns%=MOD;
			}	
			tempAns=tempAns*(s[i]-'0');		
			tempAns%=MOD;
			tempAns*=p(2,N-i-1,MOD);
			tempAns%=MOD;
			ans+=tempAns;
			ans%=MOD;
		}
		printf("%lld\n",ans);
	}
}
