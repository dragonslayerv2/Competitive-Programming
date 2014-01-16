#include<stdio.h>
#include<algorithm>
#include<stdlib.h>
#include<iostream>
using namespace std;
int compare (const void * a, const void * b)
{
  return ( *(long long int*)a - *(long long int*)b );
}
long long int max(long long int a,long long  int b)
{
if(a>b)
return a;
else 
return b;
}

void myknapsack(long long int * weight, long long int * values, long long int n, long long int w){
long long int dp[n+2][w+2],take[n+2][w+2];

for(long long int i=0;i<=n;i++)
{
	for(long long int j=0;j<=w;j++)
	{
		take[i][j] = 0;
	}
}
 
for (long long int i=1;i<=n;i++)
{
	for (long long int j=0;j<=w;j++)
	{
			if (weight[i-1]<=j)
		 	{
		 	long long int prev=i-1;
		 	long long int preweight=abs(j-weight[prev]);
		 	long long int a=dp[prev][j];
		 	long long int b=values[prev]+dp[prev][preweight];
			dp[i][j] = max(a,b);
			if (b>a)
				take[i][j]=1;//take it
			else
				take[i][j]=0;// dont take it
		 	}
		 else
		 {
		//not to take
		take[i][j] = 0;
		dp[i][j] = dp[i-1][j];
		
		}
		
		
	}
}
long long int totalitem=n;
long long int totalsize=w;
long long int count=0;
long long int res[n];
while (totalitem>0){
if (take[totalitem][totalsize]==1){
totalsize =totalsize-weight[totalitem];
res[count++]=totalitem;
}
totalitem--;
}

cout<<count<<"\n";
qsort (res, count, sizeof(long long int), compare);
for (long long int i=0;i<count;i++)
cout<<res[i]<<" ";
cout<<"\n";
/*
for (long long  int i = 0; i < n+1; ++i )//deleting
{
 delete [] take[i];
 delete [] dp[i];
}
delete [] take;
delete [] dp;

*/
}

int main()
{
int t;
cin>>t;
while(t--)
{
long long int n,k;
cin>>n>>k;

long long int a[n+2][k+2];


long long int sum[n],val[n];
long long int sumer=0;
for(long long int i=0;i<n;i++)
{
sumer=0;
for(long long int j=0;j<k;j++)
{
scanf("%lld",&a[i][j]);
sumer=sumer+a[i][j];
}
 
sum[i]=sumer;
val[i]=1;
}

sumer=0;
long long int r;
for(long long int j=0;j<k;j++)
{scanf("%lld",&r);
sumer=sumer+r;
}
 
myknapsack(sum,val,n,sumer);
/*
 for (long long  int i = 0; i < n; ++i )//deleting
{
 delete [] a[i];
}
delete [] a;*/
 
}	

 
}


 
 

