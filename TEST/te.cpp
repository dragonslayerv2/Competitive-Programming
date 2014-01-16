#include<iostream>
#include<cstdio>
#include<cstring>
#define MOD 1000000007
using namespace std;
int main()
{
int cases;
scanf("%d",&cases);
while(cases--){
int N;
scanf("%d",&N);
bool vis[N+1];
memset(vis,0,sizeof(bool)*(N+1));
int count=0;
for(int i=1;i<N+1;i++){
int j=i;
if(!vis[j]){
while(!vis[j]){
vis[j]=1;
if(j<=N/2) j=2*j;
else j=2*(j-N/2)-1;
}
count++;
}
}
long long prod=1;
for(int i=0;i<count;i++) (prod*=26)%=MOD;
printf("%d\n",prod);
}
return 0;
}
