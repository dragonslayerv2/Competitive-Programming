#include<stdio.h>
#include<string.h>
using namespace std;



int nCr[200][200];

void generatenCr(int n,long long MOD)
{
	for(int i=0;i<=n;i++)
		for(int j=0;j<=i;j++)
		{
			if(i==0||j==0)
				nCr[i][j]=1;
			else
				nCr[i][j]=nCr[i-1][j-1]+nCr[i-1][j];
		}
}

int main()
{
	
}
