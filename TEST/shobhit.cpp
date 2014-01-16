#include<stdio.h>
#include<stdlib.h>

int compare (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}


int process(int a[],int n)
{
    int initial=0;
    int sum=0;
    for(int i=1;i<n;i++)
    {
        initial=initial+a[i]-a[i-1];
        sum+=initial;
    }
    return sum;
}
int main()
{
    int t;
    scanf("%d",&t);
    while(t--)
    {
        int a[100];
        int n;
        scanf("%d",&n);
        for(int i=0;i<n;i++)
            scanf("%d",&a[i]);
        qsort (a, n, sizeof(int), compare);
        printf("%d\n",process(a,n));
    }
    return 0;
}
