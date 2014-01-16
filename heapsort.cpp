#include<stdio.h>

#define parent(i) (i>>1)
#define left(i) (i<<1)
#define right(i) ((i<<1)+1)
#define swap(a,b) {int temp=a;a=b;b=temp;}


void max_heapify(int *heap,int i,int n)
{     
     if(i<n)
     {
            int maxPos=i;
            
            if(left(i)<=n)
                       if(heap[left(i)]>heap[maxPos])
                                          maxPos=left(i); 
            if(right(i)<=n)
                       if(heap[right(i)]>heap[maxPos])
                                          maxPos=right(i); 
            
            if(i!=maxPos) 
            {
                          swap(heap[i],heap[maxPos]);
                          max_heapify(heap,maxPos,n);
            }
     }
} 


void buildmaxheap(int *heap,int n)
{
     int i;
     for(i=n/2;i>=1;i--)
                        max_heapify(heap,i,n);
}


void heapsort(int *a,int n)
{
     buildmaxheap(a,n);
     for(int i=n;i>1;i--)
     {
             swap(a[1],a[i]);
             n--;
             max_heapify(a,1,n);
     }
}


int main()
{
    int a[100];
    for(int i=1;i<=5;i++)
    {
            scanf("%d",&a[i]);
    }
    heapsort(a,5);
    for(int i=1;i<6;i++)
    {
            printf("%d ",a[i]);
    }
    fflush(stdin);
    getchar();
}
