#include<stdio.h>
#define MAX 1000000
#define max(a,b) (a)>(b)?a:b;
inline int findsum(int a[],int n,int k)
{
   int i,w;
   int array[2][MAX+1];
   int cur=1;
   int prev=0;
   
   for(i=0;i<=k;i++)
                      array[0][i]=0;
 
   for(i=0;i<=n;i++)
   {
                    for(w=0;w<=k;w++)
                    {
                                     if(a[i]>w) array[cur][w]=array[prev][w];
                                     else
                                                array[cur][w]=max(array[prev][w],array[prev][w-a[i]]+a[i]);
                    }
                    cur^=prev^=cur^=prev;
                    
   }
   return array[prev][k]==k;
}
int main()
{
    int i;
    
    int t;
    scanf("%d",&t);
    int a[1001];
    a[0]=0;
    while(t--)
    {
              int n,k;
              scanf("%d %d",&n,&k);
              
              for(i=1;i<=n;i++)
              {
                              scanf("%d",&a[i]);
              }
              printf("%d\n",findsum(a,n,k));          
    }
    return 0;
}
