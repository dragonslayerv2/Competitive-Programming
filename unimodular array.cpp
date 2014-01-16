/*
  Name: Unimodular Array
  Copyright: 
  Author: Shobhit Saxena
  Date: 25/10/12 19:22
  Description: 
*/


#include<stdio.h>
#define SIZEOF(a) (sizeof(a)/sizeof(*a))
int find(int a[],int low,int high)
{
    if(low==high) return -1;
    int mid=(low+high)/2;
    if(a[mid-1]>a[mid]&&a[mid+1]>a[mid]) return mid;
    else if(a[mid+1]<a[mid]) return find(a,mid+1,high);
    else return find(a,low,mid-1);
}

int main()
{
          int a[]={5,4,3,2,3,4,5,6,7,8,9};
          printf("%d",find(a,0,SIZEOF(a)-1));
          getchar();
          return 0;
}
