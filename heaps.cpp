#include<stdio.h>

//-----------------------MACROS--------------------------------
#define parent(i) (i>>1)
#define left(i) (i<<1)
#define right(i) ((i<<1)+1)
#define swap(a,b) {int temp=a;a=b;b=temp;}

//--------------------------------MAX HEAP HEAPIFY-----------------------------------------------
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

//--------------------------------MIN HEAP HEAPIFY-----------------------------------------------
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
//----------------------------------------BUILD MAX HEAP--------------------------------------------------
void buildmaxheap(int *heap,int n)
{
     int i;
     for(i=n/2;i>=1;i--)
                        max_heapify(heap,i,n);
}
//-----------------------------------------BUILD MIN HEAP-------------------------------------------------
void buildminheap(int *heap,int n)
{
     int i;
     for(i=n/2;i>=1;i--)
                        min_heapify(heap,i,n);
}
//--------------------------------Heap Sort using max heaps-----------------------------------------------

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
//------------------------------HEAP EXTRACT MAX -----------------------------------------------------

inline int heap_max(int *heap)
{
       return *heap;
}
//--------------------HEAP EXTRACT MIN------------------------------------------------------------------
inline int heap_min(int *heap)
{
       return *heap;
}

//-----------------------------HEAP EXTRACT MAX---------------------------------------------------------
int heap_extract_max(int *heap,int &n)
{
    if(n==0) return -1;
    int max=heap[1];
    heap[1]=heap[n];
    n--;
    max_heapify(heap,1,n);
    return max;

}
//-----------------------------HEAP EXTRACT Min---------------------------------------------------------
int heap_extract_min(int *heap,int &n)
{
    if(n==0) return -1;
    int min=heap[1];
    heap[1]=heap[n];
    n--;
    min_heapify(heap,1,n);
    return min;
}
//------------------------------Insert Element in Max Heap -------------------------------------------------------------
void insert_max_heap(int *heap,int &n,int element)
{
     n++;
     heap[n]=element;
     int i=n;
     while(heap[parent(i)]<heap[i]&&i!=1)
     {
                  swap(heap[parent(i)],heap[i]);
                  i=parent(i);
     } 
}

//------------------------------Insert Element in Min Heap -------------------------------------------------------------
void insert_min_heap(int *heap,int &n,int element)
{
     n++;
     heap[n]=element;
     int i=n;
     while(heap[parent(i)]>heap[i]&&i!=1)
     {
                  swap(heap[parent(i)],heap[i]);
                  i=parent(i);
     } 
}
//---------------------------------Increase key in max heap-----------------------------------------------
int increase_key_max_heap(int *heap,int n,int i,int nw)
{
     if(nw<heap[i]) return 0;
     heap[i]=nw;
     while(heap[parent(i)]<heap[i]&&i!=1)
     {
                  swap(heap[parent(i)],heap[i]);
                  i=parent(i);
     }   
     return 1;
}

//---------------------------------decrease key in min heap-----------------------------------------------
int decrease_key_max_heap(int *heap,int n,int i,int nw)
{
     if(nw>heap[i]) return 0;
     heap[i]=nw;
     max_heapify(heap,i,n);
     return 1;
}

//---------------------------------Decrease key in min heap-----------------------------------------------
int decrease_key_min_heap(int *heap,int n,int i,int nw)
{
     if(nw>heap[i]) return 0;
     heap[i]=nw;
     while(heap[parent(i)]>heap[i]&&i!=1)
     {
                  swap(heap[parent(i)],heap[i]);
                  i=parent(i);
     }   
     return 1;
}
//---------------------------------Increase key in min heap-----------------------------------------------
int increase_key_min_heap(int *heap,int n,int i,int nw)
{
     if(nw<heap[i]) return 0;
     heap[i]=nw;
     min_heapify(heap,i,n);
     return 1;
}
//--------------------------------------------------------------------------------------------------------
int main()
{
        int a[10]={0,10,20,30,40,50};
        int n=5;
        buildmaxheap(a,n);
       
        decrease_key_max_heap(a,5,1,10);
        
        printf("\n%d",a[1]);
                
        getchar();
        return 0;
}
