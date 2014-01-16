#include<stdio.h>


int sum(int a[],int n,int i=0,int s=0)
{
    if(i==n) return s;
    return sum(a,n,i+1,s)+sum(a,n,i+1,s+a[i]);
}
int main()
{
    int a[]={1,2,3,4};
    printf("%d",sum(a,sizeof(a)/sizeof(*a)));
    getchar();
}
