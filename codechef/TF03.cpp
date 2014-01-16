#include<stdio.h>
 
#define SIZE(a) sizeof(a)/sizeof(*a)
#define MAX 20001
 
#define a(i) (((i%10000)*(i%10000))%10000)
 
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
 
int LIS(int n,int k)
{
    if(k==1) return 1;
    int lis[MAX];
    lis[0]=a(1);
    int len=1;
    for(int i=1;i<n;i++)
    {
            int x=a(i);
            if(x<lis[0]) lis[0]=x;
            else if(x>lis[len-1]) lis[len++]=x;
            else lis[pos(lis,0,len-1,x)]=x;
            if(len==k) return 1;
    }
    return 0;
}
 
 
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
              int n,k;
              scanf("%d %d",&n,&k);
              printf("%d\n",LIS(n,k));
    }
    return 0;
} 
