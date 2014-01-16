#include<stdio.h>

int findsum(int a[],int n,int k, int restsum,int i,int sum)
{
   // printf("%d ",i);
    
    if(i==n) 
    {
             if(sum==k) return 1;
             else return 0;
    }
    
    else if(sum>k) return 0;           
    else if(sum+restsum<k) return 0;   
    else if(sum==k||sum+restsum==k) return 1;
    else
    {
         if(findsum(a,n,k,restsum-a[i],i+1,sum+a[i])) return 1;
         else return findsum(a,n,k,restsum-a[i],i+1,sum);
    }
}
int main()
{
    int i;
    
    int t;
    scanf("%d",&t);
    int a[1001];
    while(t--)
    {
              int n,k;
              scanf("%d %d",&n,&k);
              int r=0;
              for(i=0;i<n;i++)
              {
                              scanf("%d",&a[i]);
                              r+=a[i];
              }
              printf("%d\n",findsum(a,n,k,r,0,0));          
    }
    return 0;
}
