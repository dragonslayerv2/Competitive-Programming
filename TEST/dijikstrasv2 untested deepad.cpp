/*
  Name: Dijikstras implementation (heaps)
  Copyright: 
  Author: 
  Date: 06/11/12 22:28
  Description: Do check it later
*/



#include<stdio.h>

#define parent(i) (i>>1)
#define left(i) (i<<1)
#define right(i) ((i<<1)+1)
#define swap(a,b) {int temp=a;a=b;b=temp;}

#define MAX 10

#define min(a,b) a<=b?a:b


void min_heapify(int *heap,int i,int n)
{     
     if(i<n)
     {
            int minPos=i;
            
            if(left(i)<=n)
                       if(heap[left(i)]<heap[minPos])
                                          minPos=left(i); 
            if(right(i)<=n)
                       if(heap[right(i)]<heap[minPos])
                                          minPos=right(i); 
            
            if(i!=minPos) 
            {
                          swap(heap[i],heap[minPos]);
                          min_heapify(heap,minPos,n);
            }
     }
} 


//------------------------------------------------------------------------------
void buildminheap(int *heap,int n)
{
     int i;
     for(i=n/2;i>=1;i--)
                        min_heapify(heap,i,n);
}

//------------------------------------------------------------------------------
inline int heap_min(int *heap)
{
       return *heap;
}
//------------------------------------------------------------------------------
int heap_extract_min(int *heap,int &n)
{
    if(n==0) return -1;
    int min=heap[1];
    heap[1]=heap[n];
    n--;
    min_heapify(heap,1,n);
    return min;
}
//------------------------------------------------------------------------------ 
int decrease_key_max_heap(int *heap,int n,int i,int nw)
{
     if(nw>heap[i]) return 0;
     heap[i]=nw;
     max_heapify(heap,i,n);
     return 1;
}
//------------------------------------------------------------------------------



