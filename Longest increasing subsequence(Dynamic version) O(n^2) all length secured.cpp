/*
  Name: Longest Increasing Subsequence O(n^2) algorithm. 
  Copyright: 
  Author: Shobhit Saxena
  Date: 17/12/12 00:43
  Description: Well its same as the precribed O(n^2) algorithm but i did the a change. LIS[i] stores the length of latrgest increasing subsequence ending with a[i] not the so far found LIS.
               This help in generating the lIS ending with a number. pass generatesequence the pos of the element which u want to be the last element of IS. It wil print tht.  
               initLIS initialises the array and also returns the position of th element which ends up the LIS.
*/



#include<stdio.h>
#define SIZE(a) sizeof(a)/sizeof(*a)
#define MAX 100
#define max(a,b) (a>b?a:b)

int initLIS(int a[MAX],int LIS[MAX],int back[MAX],int n)
{
    if(n<=0) return 0;
    LIS[0]=1;
    back[0]=0;
    int _max=0;
    for(int i=1;i<n;i++)
    {
            LIS[i]=0;
            back[i]=i;
            for(int j=0;j<i;j++)
            {       
                    if(a[i]>a[j]&&LIS[i]<LIS[j])
                        {LIS[i]=LIS[j];back[i]=j;}
                    
            }
            LIS[i]++;
            if(LIS[i]>LIS[_max])
            _max=i;
    }
    return _max;
}


int main()
{
    int LIS[MAX];
    int back[MAX];
    
    int pos=initLIS(a,LIS,back,n);
    generatesequence(a,back,n,pos);
    for(int i=0;i<SIZE(a);i++)
    {
            printf("\n%d=>%d, %d %d",i,a[i],LIS[i],back[i]);
    }
    getchar();
    
}
