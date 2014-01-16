#include<stdio.h>

#define MAX 20001
#define _MAX 10000001

#define a(i) (((i%10000)*(i%10000))%10000)
int LIS[_MAX+100];
int pos(int lis[],int l,int u,int key)
{
            while(l<=u)
           {
                       int m=(l+u)/2;
                       if(lis[m]>key) u=m-1;
                       else if(lis[m]<key) l=m+1;
                       else return m;
           }
           return u+1;
}
 
void initLIS(int L[])
{
    int lis[MAX]; 
    lis[0]=a(1);
    int len=1;
    for(int i=1;i<_MAX;i++)
    {
            int x=a(i);
            if(x<lis[0]) lis[0]=x;
            else if(x>lis[len-1]) lis[len++]=x;
            else lis[pos(lis,0,len-1,x)]=x;
            L[i]=len;
    }
}
 
 
int main()
{
    
    initLIS(LIS);
    LIS[0]=0;
    for(int i=1;i<_MAX;i++)
    {
            if(LIS[i-1]!=LIS[i])
            printf("%d, %d",i,LIS[i]);
    }
    getchar();
    /*int t;
    scanf("%d",&t);
    while(t--)
    {
              int n,k;
              scanf("%d%d",&n,&k);
              printf("%d\n",LIS[n]>=k);
    }*/
    return 0;
} 

