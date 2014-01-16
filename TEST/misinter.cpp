#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include<string.h>
#include <limits.h>
#include <stdbool.h>
long long int power(int x, unsigned int y)
{
// printf("%d\n",y);
long long int temp=0;
if( y == 0)
return 1;
else if(y==1)
return x;
else if (y%2 == 0)
{
temp=power(x,y/2)%1000000007;
return (temp*temp)%1000000007;
}
 
else
{
temp=power(x,y/2)%1000000007;
return (x*((temp*temp)%1000000007))%1000000007;
}
 
}
int loopsinNALL(int n)
{
int i=0,current=0,count=0,temp=0,temp2,j=0;
bool s[n+1];
memset(s,0,sizeof s);
//for(i=0; i<=n; i++)
// s[i]=0;
for(i=1; i<=n/2; i++)
{
current=s[i];
temp=i;
temp2=i;
//s[i]=1;
if(current == 0)
{
do
{
if(temp <= n/2)
{
s[temp]=1;
temp*=2; //s[temp]=1;
}
else //if(temp2 != temp)
{
s[temp]=1;
temp=temp-(n-temp+1);
}
}
while(temp2 != temp);
count++;
}
}
return count;
 
}
long long int combi(int n)
{
int i=0;
long long int x=0;
long long int prevresult;
 
for(i=n; i<=n; i++)
{
if(i%2==0)
{
prevresult =1;
x=(x+prevresult%1000000007)%1000000007;
 
}
else
{
if(i==n)
x=(x+(power(26,loopsinNALL(i-1))*26)%1000000007)%1000000007;
else
x=(x+prevresult*26)%1000000007;
}
}
return x;
}
int main(int argc, char **argv)
{
char T;
long long int L;
scanf("%d\n",&T);
while(T > 0)
{
scanf("%lld\n", &L);
printf("%lld\n",combi(L));
T -= 1;
}
return 0;
}
