/*
  Name: Knuth Shuffle
  Copyright: 
  Author: Shobhit Saxena
  Date: 26/10/12 00:54
  Description: Shuffling an array... Normal code but yes preserves loop invariants. While creating shuffles do care for the seed bits. They matter a lot.
*/

#include<stdio.h>
#include<time.h>
#include<stdlib.h>

#define MAX 100

inline void swap(int *a,int *b)
{
       int temp=*a;
       *a=*b;
       *b=temp;
}
int main()
{
    srand(time(NULL));
    int a[MAX];
    int n;
    scanf("%d",&n);
    for(int i=0;i<n;i++)
    {
            scanf("%d",&a[i]);
    }
    
    //---shuffling part---------------
    for(int i=1;i<n;i++)
    {
            swap(&a[i],&a[rand()%(i+1)]);// Do care for this i+1
    }
    //--------------------------------
    
    for(int i=0;i<n;i++)
    {
            printf("%d ",a[i]);
    }
    fflush(stdin);
    getchar();

}
