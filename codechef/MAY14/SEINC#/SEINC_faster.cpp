#include<stdio.h>
#include<iostream>
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

#define MAXDP 100
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
					for(int k=j-1;k<j+2;k++)
					{
						if(k<0||k>=MAXDP)
							continue;
						DP[i][j]=min(DP[i][j],a[i]+4*k+DP[i+1][k]-min(a[i]+4*k,a[i-1]+4*j));
					}		
				}
			}
			
			
			int ansj=0;

			int ans=numeric_limits<int>::max();
			
			for(int i=0;i<MAXDP;i++)
				if(ans>DP[1][i]+a[0]+4*i)
				{
					ans=DP[1][i]+a[0]+4*i;
					ansj=i;
				}
			
			cout<<ans<<"\n";
	}
}
