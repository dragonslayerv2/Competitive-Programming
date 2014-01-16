// 2 different Partition sub routine of quick sort...
#include<stdio.h>
#include<conio.h>
int count;
int partition(int a[],int min,int max)
{
     int i=min+1;
     int k=max-1;
     int temp;
     while(i<k)
     {
               if(a[i]>a[min])
               {
                              temp=a[k];
                              a[k]=a[i];
                              a[i]=temp;
                              k--;                
               }                     
               else
                   i++;
     }
     temp=a[i-1];
     a[i-1]=a[min];
     a[min]=temp;
     return i-1;
}

int partition2(int a[],int min,int max)
{
     int i=min;
     int j=i+1;
     int temp;
     while(j<max)
     {
               if(a[j]<a[min])
               {

                              i++; 
                              temp=a[i];
                              a[j]=a[i];
                              a[i]=temp;                
               }                     
               j++;
     }
     temp=a[i];
     a[i]=a[min];
     a[min]=temp;
     return i;
}

