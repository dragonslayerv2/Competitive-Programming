#include<stdio.h>
#include<stdlib.h>

int compare (const void * a, const void * b)
{
    return ( *(int*)b-*(int*)a );
}

inline int search(int a[],int min,int max,int c)
{
    int mid;
    while(min<=max)
    {
            mid=(min+max)/2;
            if(a[mid]==c) return 1;       
            else if(a[mid]<c) min=min+1;
            else max=mid-1;
    }
     return 0;
}
int main()
{
    int t,i;
    scanf("%d",&t);
    while(t--)
    {
              int players[11];
              for(i=0;i<11;i++)
              {
                      scanf("%d",&players[i]);
              }
              int k;
              scanf("%d",&k);
              
              qsort (players, 11, sizeof(int), compare);
              int max=0;
              int count =1;
              for(i=0;i<k;i++)
                      max+=players[i];
              for(;i<11;i++)
              {
                            if(search(players, 0,k,players[i])) count++;
              }
              printf("%d\n",count);
    }
return 0;
}
