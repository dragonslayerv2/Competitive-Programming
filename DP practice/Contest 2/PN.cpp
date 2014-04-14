#include<stdio.h>
#include<cstring>
using namespace std;

#define MOD 1000000007LL

char S[100005];
long long DP[100000][27];
inline int charHash(char a)
{
	return a-'A'+1;
}
int main()
{
	freopen("test.txt","r",stdin);
	int t;
	scanf("%d",&t);
	while(t--)
	{
		scanf("%s",S);
		int n=strlen(S);
		

		
		for(int i=n-1;i>=0;i--)
		{
			for(int j=0;j<27;j++)
			{
				if(i==n-1)
				{
					if(charHash(S[i])!=j)
						DP[i][j]=2;
					else
						DP[i][j]=1;
				}
				else
				{
					if(charHash(S[i])!=j)
					{
			
						DP[i][j]=DP[i+1][j]+DP[i+1][charHash(S[i])];
					}
					else
					{
						DP[i][j]=DP[i+1][j];
					}
				}
				DP[i][j]%=MOD;
			
			}
		
		}
		
		printf("%lld\n",DP[0][0]);
	}
}
