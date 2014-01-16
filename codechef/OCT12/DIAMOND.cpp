#include<stdio.h>
#define MAX 2010


long long count =0;
long long numbers=0;
void recurse(int a[],int low,int high,int turn,long long val)
{
     if(low==high)
     {
                  count+=val;
                  if(turn==1)
                           count+=a[low];
                  numbers++;
                  return;
     }
     else
     {
                  if(turn==1)
                  {
                  recurse(a,low+1,high,turn*(-1),val+a[low]);
                  recurse(a,low,high-1,turn*(-1),val+a[high]);
                  }
                  else
                  {
                      recurse(a,low+1,high,turn*(-1),val);
                      recurse(a,low,high-1,turn*(-1),val);
                  }
     }
}

int main()
{
    int t,n,i;
    int a[MAX];
    scanf("%d",&t);
    while(t--)
    {
              scanf("%d",&n);
              count=numbers=0;
              for(i=0;i<n;i++)
              {
                              scanf("%d",&a[i]);               
              }
              
              recurse(a,0,n-1,1,0);
              printf("%.3f\n",(float)count/numbers);
    }
    return 0;
}
