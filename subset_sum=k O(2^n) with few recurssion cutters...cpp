/*
  Name: Sum of elements os subsets of a set....
  Copyright: 
  Author: Shobhit Saxena
  Date: 28/11/12 00:51
  Description: A subset can be treated as a binary tree.. If we r moving left we means we include tht element else we exclude tht from the set.
               Alternatively we can think tht to find the sum of a subset we either include a term or exclude it. Left show tht we include the term and right we exclude tht.
               Complexity O(2^n)
*/


#include<stdio.h>


int findsum(int a[],int n,int k, int restsum,int i=0,int sum=0)
{
   // printf("%d ",i);
    
    if(i==n) 
    {
             if(sum==k) return 1;
             else return 0;
    }
    else if(restsum==k) return 1;// remove this if u have to find the subset also... which sum tht....
    else if(sum>k) return 0;           // since sum >k no need to proceed further    
    else if(sum+restsum<k) return 0;   // even we include all the elements the sum there sum is < k, so no need to proceed further
    else if(sum==k||sum+restsum==k) return 1; // this is a condition for true....
    else
    {
         if(findsum(a,n,k,restsum-a[i],i+1,sum+a[i])) return 1;
         else return findsum(a,n,k,restsum-a[i],i+1,sum);
    }
}
int main()
{
    int n=4;
    int k=13;
    int a[]={2,3,4,5};
    printf("%d",findsum(a,n,k,14));
    getchar();
    return 0;
}
