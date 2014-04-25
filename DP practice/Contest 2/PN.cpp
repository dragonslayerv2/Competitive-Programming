#include<stdio.h>
#include<string.h>

char S[100005];
long long DP[100005];
#define MOD 1000000007LL

int main()
{		
	int t;
	scanf("%d",&t);
	getchar();
	while(t--)
	{
		gets(S);
		int n=strlen(S);
		
		DP[0]=1;
		int lastOccurence[27]={0};
		int i;
		for( i=1;i<=n;i++)
		{
			DP[i]=2*DP[i-1];
			if(lastOccurence[S[i-1]-'A'])
				DP[i]-=DP[lastOccurence[S[i-1]-'A']-1];
			
			lastOccurence[S[i-1]-'A']=i;
			DP[i]+=MOD;
			DP[i]%=MOD;
		}
	//	for(int i=0;i<=n;i++)
	//		printf("%lld ",DP[i]);
	//	printf("\n");
		printf("%lld\n",DP[n]);
	}
}
