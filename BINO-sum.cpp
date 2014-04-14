#include<stdio.h>
#include<iostream>
#include<string.h>
using namespace std;

long long nCr[2000][2000];

#define MOOD 1000000007LL
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

int main()
{
	generatenCr(1000,MOOD);	
	for(int i=0;i<10;i++)
	{
	
		for(int j=0;j<10;j++)
			cout<<nCr[i][j]<<" ";
		cout<<endl;
	}
	int t;
	cin>>t;
	while(t--)
	{
		int n,p;
		cin>>n>>p;
		long long sum=0;
		for(int i=0;i<=p;i++)
		{
			
			sum+=nCr[n][i];
			sum%=MOOD;
		}
			
		cout<<sum<<endl;
	}
}
