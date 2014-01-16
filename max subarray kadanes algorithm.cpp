// Kadane's Algorithm to check for the maximum subarray....
// An extra check has been added since if all the array's elements are negative original algorithm returns 0.
#include<stdio.h>
#include<limits.h>
int maxsubarray(int a[],int n)
{
    bool flag=true;
    int i,max_so_far=INT_MIN, max_ending_here=0;
    for(i=0;i<n;i++)
    {
            if(a[i]>0&&flag) {flag=false;max_so_far=0;}
            if(flag)
            {            
                         if(a[i]>max_so_far)                             
                             max_so_far=a[i];
                                         continue;                           
            }
            
            max_ending_here+=a[i];
            if(max_ending_here<0)
                          max_ending_here=0;
            if(max_ending_here>max_so_far)
                          max_so_far=max_ending_here;   
    }
    return max_so_far;
}
int main()
{
 int a[] = {-1,-2,-1,-2,-3,-1,-1,-1};
   int max_sum = maxsubarray(a, 8);
   printf("Maximum contiguous sum is %d\n", max_sum);
   getchar();
   return 0;
}
