// Merge sort  with sentinals... as described in cormen

#include<stdio.h>
#include<limits.h>
#define MAX 1000
int left[MAX];
int right[MAX];
void merge(int a[],int l,int m,int h)
{
    
    int j=0,k=0;
    for(int i=l;i<=m;i++)
    {
        left[j++]=a[i];
    }

    for(int i=m+1;i<=h;i++)
    {
        right[k++]=a[i];
    }

    left[j]=right[k]=INT_MAX;
    j=k=0;

    for(int i=l;i<=h;i++)
    {
        if(left[j]<right[k])
        {
            a[i]=left[j];
            j++;
        }
        else
        {
            a[i]=right[k];
            k++;
        }
    }
}
void msort(int a[],int l,int h)
{
    if(l==h)
        return;
    int m=(l+h)/2;
    msort(a,l,m);
    msort(a,m+1,h);
    merge(a,l,m,h);
}
int main()
{
        int a[MAX];
        for(int i=0;i<10;i++)
        {
            scanf("%d",&a[i]);
        }
        msort(a,0,9);
        for(int i=0;i<10;i++)
        {
            printf("%d ",a[i]);
        }
}
