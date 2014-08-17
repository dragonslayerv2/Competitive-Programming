#include<stdio.h>
#include<limits>
#include<vector>
#include<climits>
using namespace std;

#ifdef ONLINE_JUDGE
	#define GETCHAR getchar_unlocked	
	#define PUTCHAR putchar_unlocked
#endif
#ifndef ONLINE_JUDGE
	#define GETCHAR getchar
	#define PUTCHAR putchar
#endif
	
inline int readlong() 
{
	int flag=1;
    int n = 0;
    char c;
    while (1)
    { 
              c=GETCHAR();
              if(c>='0'&&c<='9') {n = n * 10 + c - '0';flag=0;}
              else if(flag!=1) break; 
                              
    }
    return n;
}

#define MAXDP 8
int a[100100];
int DP[100100][MAXDP];

int main()
{
//	freopen("sample.txt","r",stdin);
	int t;
	t=readlong();
	while(t--)
	{
			
			int n;
			n=readlong();
			for(int i=0;i<n;i++)
				a[i]=readlong();
		
			for(int i=0;i<n;i++)
			{
				int b;
				b=readlong();
				a[i]=(4+b-a[i])%4;
			}
			
			for(int i=0;i<MAXDP;i++)
				DP[n][i]=0;
		
			for(int i=n-1;i>=1;i--)
			{
				for(int j=0;j<MAXDP;j++)
				{
					DP[i][j]=numeric_limits<int>::max();
					for(int k=0;k<MAXDP;k++)
						DP[i][j]=min(DP[i][j],a[i]+4*k+DP[i+1][k]-min(a[i]+4*k,a[i-1]+4*j));
				}
			}
			int ans=numeric_limits<int>::max();
			for(int i=0;i<MAXDP;i++)
				ans=min(ans,DP[1][i]+a[0]+4*i);
			printf("%d\n",ans);
	}
}
