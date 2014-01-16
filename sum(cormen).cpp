//This functions check whether the sum of two numbers of an array equals x or not... if yes it return true else false...
// Cormen Exercise Question....


#include<stdio.h>
#include<conio.h>
#include<stdlib.h>
int compare (const void * a, const void * b)
{
    return ( *(int*)a - *(int*)b );
}

int sum(int a[],int n,int x)
{
            qsort (a, n, sizeof(int), compare);
            int i=0;
            int f=n-1;
            while(i!=f)
            {
                    int sum=a[i]+a[f];
                    if(sum==x) return 1;
                    else if(sum<x) i++;
                    else f--;
            }
            return 0;
}

int main()
{
 int a[]={1,2,5,4,3,7,8};
 printf("%d",sum(a,7,7));
 getch();
}
