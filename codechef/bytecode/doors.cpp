#include<stdio.h>
#include<math.h>
int func(int n)
{
 int low=1;
 int high=sqrt(n);
 int mid;
 if(n==0) return 1;
 while(low<=high)
 {
        
         mid=(high+low)/2;
         if((mid*mid+2*mid>=n)&&((mid*mid-1)<n)) return mid;
         else if((mid*mid+2*mid<n)) low=mid+1;
         else high = mid-1;
 }
 
}

int main()
{
    int t,n,i;
    scanf("%d",&t);
    while(t--)
    {
              
              scanf("%d",&n);
              printf("%d\n",func(n));
    }
    
    return 0;
}
