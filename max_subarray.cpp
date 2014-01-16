//Maximum SubArray Problem(recursive Approach)...
//This function finds the max sum of a subarray in an array....
//Usage: a is the array
//       l corresponds to lower limit
//       h corresponds to higher limit
//This is a O(nlogn) solution....

#include<stdio.h>
#include<conio.h>
#include<limits.h>

int max_subarray(int a[],int l,int h)
{
        if(l==h) 
                      return a[l];
        int left_sum,right_sum;
        left_sum=right_sum=INT_MIN;
        int sum=0;
        int mid=(l+h)/2;
        for(int i=mid;i>=l;i--)
        {
            sum=sum+a[i];
            if(sum>left_sum)
            {
                            left_sum=sum;
            }
        }
        sum=0;
        for(int i=mid+1;i<=h;i++)
        {
            sum=sum+a[i];
            if(sum>right_sum)
            {
                            right_sum=sum;
            }
        }
        int centre_sum=left_sum+right_sum;
        left_sum=max_subarray(a,l,mid);
        right_sum=max_subarray(a,mid+1,h);
        return centre_sum>left_sum?(centre_sum>right_sum?centre_sum:right_sum):(left_sum>right_sum?left_sum:right_sum);//Return max of three
}
int main()
{
          int a[]={13,-3,-25,20,-3,-16,-23,18,20,-7,12,-5,-22,15,-47};
          printf("%d",max_subarray(a,0,14));
          getch();
          return 0;
}
//---------------------------------O(n) solution
/*
#include<stdio.h>
#include<conio.h>
main(){
       int a[16] = {13,-3,-25,20,-3,-16,-23,18,20,-436,16,-5,-22,15,-4,7};
       int x,y;
       y = 0;
       x = 0;
       for(int i=0;i<16;i++){
               x = x + a[i];
               if(x<0) x = 0;
               if(x>y)
               y = x;
               }
      printf("%d",y);
      getch();
      }    
//------------------------------------------------------------
*/
