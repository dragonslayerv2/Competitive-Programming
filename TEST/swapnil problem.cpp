#include<stdio.h>

int main()
{
     
     int sum=0;
     for(int i=1;i<=999;i++)
     {
             
             int n=i;
             int num=1;
             while(n)
             {
                     int r=n%10;
                     if(r) num*r;
                     n/=10;
             }
             sum+=num;
             printf("%d ",num);
     }
     printf("%d",sum);
     getchar();
     
}
