#include<stdio.h>
#include<stdlib.h>


int compare (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

int main()
{
    
    int t;
    scanf("%d",&t);
    while(t--)
    {
    int n;
    scanf("%d",&n);
    int p[30],w[30];
    for(int i=0;i<n;i++)
    {
            scanf("%d",&p[i]);
    }
    
    for(int i=0;i<n;i++)
    {
            scanf("%d",&w[i]);
    }
    qsort (p, n, sizeof(int), compare);
    qsort (w, n, sizeof(int), compare);
    int j=n-1;
    int k=n-1;
    int ans=0;
    while(j>=0&&k>=0)
    {
                     if(w[j]>=p[k])
                     {
                                 j--;
                                 k--;
                                 ans++;  
                     }
                     else
                                 k--;
    }
    printf("%d\n",ans);        
    }      
        
    return 0;
}
