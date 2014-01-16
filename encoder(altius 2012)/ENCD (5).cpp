#include<stdio.h>

int main()
{
   
    while(1)
    {
            int m,n;
            
    int min0=0;
    int min1=1;
    
    int max0=1;
    int max1=0;
   
    int mid0;
    int mid1;
                              scanf("%d %d",&m,&n);
                              
                              if(m==1&&n==1) break;
                              while(1)
                              {
                                                        mid0=min0+max0;
                                                        mid1=min1+max1;
                                                        if((float)mid0/mid1==(float)m/n) break;
                                                        if((float)mid0/mid1<(float)m/n){printf("R");min0=mid0;min1=mid1;}
                                                        else {printf("L");max0=mid0;max1=mid1;}                         
                              }
                              printf("\n");
    }
}
