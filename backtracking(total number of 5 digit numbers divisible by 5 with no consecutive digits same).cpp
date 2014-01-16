/*
  Name: Find the total number of 5 digit numbers divisible by 5 with no consecutive digits same..
  Copyright: 
  Author: Shobhit Saxena
  Date: 23/12/12 15:18
  Description: Backtraking solution.
*/



#include<stdio.h>

int count=0;

int counts[10]={0,0,0,0,0};
int counts05[10]={0,0,0,0,0};
int func(int a[],int i=0)
{
    if(i==4)
    {
            
            if(a[i-1]==0||a[i-1]==5) count++;
            else count+=2; 
    }
    else if(i==0)
    {
            for(int j=1;j<=9;j++)
            {
                    counts[i]++;
                    if(j==5||j==0) counts05[i]++;
                    a[i]=j;
                    func(a,i+1);
            }
    }
    else
    {
            for(int j=0;j<=9;j++)
            {
                    if(j==a[i-1]) continue;
                    counts[i]++;
                    if(j==5||j==0) counts05[i]++;
                    a[i]=j;
                    func(a,i+1);
            }
    }
}

int main()
{
    int a[5];
    func(a);
    printf("Digit\t\tTotal Allowed\t\tTOtal 5s&0sin this digit\n");
    for(int i=0;i<5;i++)
    {
            printf("%d\t\t%d\t\t\t%d\n",i,counts[i],counts05[i]);
    }
    printf("Answer=>>>%d",count);
    getchar();
}
