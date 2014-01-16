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

long long count=0;
void findsum(int a[],int n,int k, int restsum,int i=0,int sum=0)
{
   // printf("%d ",i);
    
    if(i==n) 
    {
             if(sum==k) count++;
             return;
    }
    else if(restsum==k) {count++;return;}// remove this if u have to find the subset also... which sum tht....
    else if(sum>k) return;           // since sum >k no need to proceed further    
    else if(sum+restsum<k) return;   // even we include all the elements the sum there sum is < k, so no need to proceed further
    else if(sum==k||sum+restsum==k) {count++;return;} // this is a condition for true....
    else
    {
         findsum(a,n,k,restsum-a[i],i+1,sum+a[i]);
         findsum(a,n,k,restsum-a[i],i+1,sum);
    }
}
int main()
{
    int n=4;
    int k=12;
    int a[]={2,3,4,5};
    findsum(a,n,k,14);
    printf("%lld",count);
    getchar();
    return 0;
}
